
#include "stratum.h"

#ifdef COINDSUBMIT_DEBUG
#define cdslog(args...) debuglog(args); stratumlog(args)
#else
#define cdslog(args...) stratumlog(args)
#endif

#define NULLRETFALSE(x, msg) do { if (!(x)) { debuglog("%s:%s", __func__, msg); return false; } } while (0) 
  
bool coind_submitwork(YAAMP_COIND *coind, const char *block)
{
	int paramlen = strlen(block);

	char *params = (char *)malloc(paramlen+1024);
	if(!params) {
		debuglog("%s: OOM!\n", __func__);
		return false;
	}

	sprintf(params, "[\"%s\"]", block);
	json_value *json = rpc_call(&coind->rpc, "getwork", params);
	if(!json) {
		debuglog("%s: retry\n", __func__);
		usleep(500*YAAMP_MS);
		json = rpc_call(&coind->rpc, "getwork", params);
	}
	free(params);

	if(!json) {
		debuglog("%s: error, no answer\n", __func__);
		return false;
	}

	json_value *json_res = json_get_object(json, "result");

	bool b = json_res && json_res->type == json_boolean && json_res->u.boolean;
	json_value_free(json_res);

	return b;
}

bool coind_submitblock(YAAMP_COIND *coind, const char *block)
{
	int paramlen = strlen(block);

	char *params = (char *)malloc(paramlen+1024);
	NULLRETFALSE(params, "OOM");

	sprintf(params, "[\"%s\"]", block);
	json_value *json = rpc_call(&coind->rpc, "submitblock", params);

	free(params);
	NULLRETFALSE(json, "ERROR submitblock returned NULL");

	json_value *json_error = json_get_object(json, "error");
	if(json_error && json_error->type != json_null)
	{
		const char *p = json_get_string(json_error, "message");
		if(p) cdslog("ERROR %s %s %s\n", coind->name, p, __func__);

	//	job_reset();
		json_value_free(json);

		return false;
	}

	json_value *json_result = json_get_object(json, "result");

	bool b = json_result && json_result->type == json_null;
	json_value_free(json);

	return b;
}

bool coind_submitblocktemplate(YAAMP_COIND *coind, const char *block)
{
	int paramlen = strlen(block);

	char *params = (char *)malloc(paramlen+1024);
	NULLRETFALSE(params, "OOM");

	sprintf(params, "[{\"mode\": \"submit\", \"data\": \"%s\"}]", block);
	json_value *json = rpc_call(&coind->rpc, "getblocktemplate", params);

	free(params);
	NULLRETFALSE(json, "ERROR submitblock returned NULL");

	json_value *json_error = json_get_object(json, "error");
	if(json_error && json_error->type != json_null)
	{
		const char *p = json_get_string(json_error, "message");
		if(p) cdslog("ERROR %s %s %s\n", coind->name, p, __func__);

	//	job_reset();
		json_value_free(json);

		return false;
	}

	json_value *json_result = json_get_object(json, "result");

	bool b = json_result && json_result->type == json_null;
	json_value_free(json);

	return b;
}

bool coind_submit(YAAMP_COIND *coind, const char *block)
{
	bool b;

	if(coind->usegetwork) // DCR
		b = coind_submitwork(coind, block);
	else if(coind->hassubmitblock)
		b = coind_submitblock(coind, block);
	else
		b = coind_submitblocktemplate(coind, block);

	return b;
}

bool coind_submitgetauxblock(YAAMP_COIND *coind, const char *hash, const char *block)
{
	int paramlen = strlen(block);

	char *params = (char *)malloc(paramlen+1024);
	if(!params) return false;

	sprintf(params, "[\"%s\",\"%s\"]", hash, block);
	json_value *json = rpc_call(&coind->rpc, "getauxblock", params);

	free(params);
	if(!json) return false;

	json_value *json_error = json_get_object(json, "error");
	if(json_error && json_error->type != json_null)
	{
		const char *p = json_get_string(json_error, "message");
		if(p) stratumlog("ERROR %s %s\n", coind->name, p);

	//	job_reset();
		json_value_free(json);

		return false;
	}

	json_value *json_result = json_get_object(json, "result");
	bool b = json_result && json_result->type == json_boolean && json_result->u.boolean;

	json_value_free(json);
	return b;
}
