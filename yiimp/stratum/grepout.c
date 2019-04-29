~~base58.cpp:40:	memset(outi, 0, outisz * sizeof(*outi));

~~client_core.cpp:210:	memset(tmp, 0, 1024);
~~client_core.cpp:211:	strncpy(tmp, client->password, 1023);

--never hit
~~client_core.cpp:293:    	strcpy(ip, hostname); 
~~client_core.cpp:309:        strcpy(ip, inet_ntoa(*addr_list[i]));
--


--
client.cpp:33:	strcpy(client->extranonce1, client->extranonce1_default);
client.cpp:38:		memset(client->extranonce1, '0', sizeof(client->extranonce1));
client.cpp:39:		memcpy(&client->extranonce1[16], client->extranonce1_default, YAAMP_EXTRANONCE2_SIZE*2);
client.cpp:49:			strncpy(client->version, json_params->u.array.values[0]->u.string.ptr, 1023);
client.cpp:63:			strncpy(notify_id, json_params->u.array.values[1]->u.string.ptr, 1023);
client.cpp:68:			strncpy(client->notify_id, notify_id, 1023);
client.cpp:75:			strcpy(client->extranonce1_default, client1->extranonce1_default);
client.cpp:78:			strcpy(client->extranonce1, client1->extranonce1_reconnect);
client.cpp:86:			memcpy(client->job_history, client1->job_history, sizeof(client->job_history));
client.cpp:99:				strncpy(client->notify_id, notify_id, 1023);
client.cpp:104:				memcpy(client->job_history, client1->job_history, sizeof(client->job_history));
client.cpp:114:	strcpy(client->extranonce1_last, client->extranonce1);
client.cpp:206:		strncpy(client->password, json_params->u.array.values[1]->u.string.ptr, 1023);
client.cpp:215:		strncpy(client->username, json_params->u.array.values[0]->u.string.ptr, 1023);
client.cpp:225:			strncpy(client->worker, sep+1, 1023-len);
client.cpp:457://		memset(source, 0, sizeof(YAAMP_SOURCE));
client.cpp:459://		strncpy(source->ip, client->sock->ip, 64);
client.cpp:526:	memset(client, 0, sizeof(YAAMP_CLIENT));
--

___
client_submit.cpp:16:	memset(coinbase_bin, 0, 1024);
client_submit.cpp:20:	memset(doublehash, 0, 128);	
client_submit.cpp:92:	memcpy(&header, templ->header, sizeof(header));
client_submit.cpp:94:	memset(header.extra, 0, 32);
client_submit.cpp:106:	memcpy(out->header_bin, &header, sizeof(header));
client_submit.cpp:120:		memset(coinbase_bin, 0, 1024);
client_submit.cpp:200:			memset(block_hex, 0, block_size);
client_submit.cpp:202:			strcat(block_hex, submitvalues->coinbase);		// parent coinbase
client_submit.cpp:203:			strcat(block_hex, submitvalues->hash_be);		// parent hash
client_submit.cpp:215:			strcat(block_hex, "00000000");
client_submit.cpp:229:			strcat(block_hex, submitvalues->header_be);
client_submit.cpp:255:		memset(block_hex, 0, block_size);
client_submit.cpp:271:			strcat(block_hex, "00");
client_submit.cpp:292:			memset(doublehash2, 0, 128);
client_submit.cpp:301:			memset(hash1, 0, 1024);
client_submit.cpp:307:				strcpy(hash1, submitvalues->hash_hex);
client_submit.cpp:413:	strncpy(extranonce2, json_params->u.array.values[2]->u.string.ptr, 31);
client_submit.cpp:414:	strncpy(ntime, json_params->u.array.values[3]->u.string.ptr, 31);
client_submit.cpp:415:	strncpy(nonce, json_params->u.array.values[4]->u.string.ptr, 31);
client_submit.cpp:424:			strncpy(extra, json_params->u.array.values[5]->u.string.ptr, 128);
client_submit.cpp:428:			strncpy(vote, json_params->u.array.values[5]->u.string.ptr, 7);
client_submit.cpp:493:		strcpy(extra1_id, &client->extranonce1[cmpoft]);
client_submit.cpp:494:		strcpy(extra2_id, &extranonce2[cmpoft]);
client_submit.cpp:520:	memset(&submitvalues, 0, sizeof(submitvalues));
___


coinbase.cpp:25:	strcat(data, evalue);
coinbase.cpp:26:	strcat(data, coinb2_len);
coinbase.cpp:27:	strcat(data, coinb2_part);
coinbase.cpp:76:	memset(merkle_hash, 0, 4*1024);
coinbase.cpp:95:		strcpy(eversion1, "02000000");
coinbase.cpp:141:		strcat(templ->coinb2, "06");
coinbase.cpp:153:		strcat(templ->coinb2, "00000000"); // locktime
coinbase.cpp:198:		strcat(templ->coinb2, payees);
coinbase.cpp:199:		if (templ->has_segwit_txs) strcat(templ->coinb2, commitment);
coinbase.cpp:202:		strcat(templ->coinb2, echarity_amount);
coinbase.cpp:207:		strcat(templ->coinb2, coinb2_len);
coinbase.cpp:208:		strcat(templ->coinb2, coinb2_part);
coinbase.cpp:220:		strcat(templ->coinb2, "00000000"); // locktime
coinbase.cpp:244:			strcat(templ->coinb2, "03"); // 3 outputs (nulldata + fees + miner)
coinbase.cpp:245:			strcat(templ->coinb2, commitment);
coinbase.cpp:247:			strcat(templ->coinb2, "02");
coinbase.cpp:251:		strcat(templ->coinb2, "00000000"); // locktime
coinbase.cpp:279:				strcat(templ->coinb2, "02");
coinbase.cpp:282:				strcat(templ->coinb2, "00000000"); // locktime
coinbase.cpp:362:		strcat(templ->coinb2, payees);
coinbase.cpp:363:		if (templ->has_segwit_txs) strcat(templ->coinb2, commitment);
coinbase.cpp:364:		strcat(templ->coinb2, script_dests);
coinbase.cpp:366:		strcat(templ->coinb2, "00000000"); // locktime
coinbase.cpp:407:		strcat(templ->coinb2, payees);
coinbase.cpp:408:		strcat(templ->coinb2, script_dests);
coinbase.cpp:410:		strcat(templ->coinb2, "00000000"); // locktime
coinbase.cpp:450:		strcat(templ->coinb2, payees);
coinbase.cpp:451:		strcat(templ->coinb2, script_dests);
coinbase.cpp:453:		strcat(templ->coinb2, "00000000"); // locktime
coinbase.cpp:502:			strcat(templ->coinb2, payees);
coinbase.cpp:503:			strcat(templ->coinb2, script_dests);
coinbase.cpp:505:			strcat(templ->coinb2, "00000000"); // locktime
coinbase.cpp:517:				strcat(templ->coinb2, "03"); // 3 outputs (nulldata + node + miner)
coinbase.cpp:518:				strcat(templ->coinb2, commitment);
coinbase.cpp:520:				strcat(templ->coinb2, "02"); // 2 outputs
coinbase.cpp:527:			strcat(templ->coinb2, "01");
coinbase.cpp:532:		strcat(templ->coinb2, "02");
coinbase.cpp:533:		strcat(templ->coinb2, commitment);
coinbase.cpp:535:		strcat(templ->coinb2, "01");
coinbase.cpp:541:	//	strcat(templ->coinb2, "00");
coinbase.cpp:543:	strcat(templ->coinb2, "00000000"); // locktime

coind_aux.cpp:19:	memset(templ->auxs, 0, sizeof(templ->auxs));
coind_aux.cpp:38:				memset(templ->auxs, 0, sizeof(templ->auxs));
coind_aux.cpp:60:			memset(hash_be, 0, 1024);

coind.cpp:140:	strcpy(coind->pubkey, p ? p : "");
coind.cpp:143:	if (acc) strcpy(coind->account, acc);
coind.cpp:154:			strcpy(coind->script_pubkey, &pk[6]);
coind.cpp:173:	strcpy(account, coind->account);
coind.cpp:200:		strcpy(coind->wallet, json->u.object.values[0].value->u.string.ptr);
coind.cpp:203:		strcpy(coind->wallet, "");

coind_submit.cpp:35:		memset(timestamp, 0, sizeof(timestamp));

coind_template.cpp:26:	if(p) strcpy(coind->aux.target, p);
coind_template.cpp:29:	if(p) strcpy(coind->aux.hash, p);
coind_template.cpp:59:	memset(templ, 0, sizeof(YAAMP_JOB_TEMPLATE));
coind_template.cpp:66:	strcpy(templ->nbits, json_get_string(json_result, "bits"));
coind_template.cpp:67:	strcpy(templ->prevhash_hex, json_get_string(json_result, "previousblockhash"));
coind_template.cpp:139:	memcpy(templ->header, &header, sizeof(header));
coind_template.cpp:189:	memset(templ, 0, sizeof(YAAMP_JOB_TEMPLATE));
coind_template.cpp:237:	if(!strcmp(coind->symbol, "PPC")) strcpy(params, "[]");
coind_template.cpp:238:	else if(g_stratum_segwit) strcpy(params, "[{\"rules\":[\"segwit\"]}]");
coind_template.cpp:266:				strcpy(coind->witness_magic, "aa21a9ed");
coind_template.cpp:268:					strncpy(coind->witness_magic, &commitment[4], 8);
coind_template.cpp:296:	memset(templ, 0, sizeof(YAAMP_JOB_TEMPLATE));
coind_template.cpp:305:	strcpy(templ->nbits, bits ? bits : "");
coind_template.cpp:307:	strcpy(templ->prevhash_hex, prev ? prev : "");
coind_template.cpp:309:	strcpy(templ->flags, flags ? flags : "");
coind_template.cpp:313:		strcpy(templ->accumulatorcheckpoint_hex, accumulator ? accumulator : "");
coind_template.cpp:319:		strcpy(templ->claim_hex, claim);
coind_template.cpp:336:			strcpy(templ->claim_hex, claim);
coind_template.cpp:345:		strcpy(&templ->extradata_hex[ 0], sc_root); // 32-bytes hash (64 in hexa)
coind_template.cpp:346:		strcpy(&templ->extradata_hex[64], sc_utxo); // 32-bytes hash too
coind_template.cpp:380://	strcpy(target, json_get_string(json_result, "target"));
coind_template.cpp:592:	memset(coind->job, 0, sizeof(YAAMP_JOB));

db.cpp:68:	if (strstr(string, "script")) strcpy(string, "");
db.cpp:211:			memset(coind, 0, sizeof(YAAMP_COIND));
db.cpp:221:		strcpy(coind->name, row[1]);
db.cpp:222:		strcpy(coind->symbol, row[20]);
db.cpp:234:		if(row[7]) strcpy(coind->wallet, row[7]);
db.cpp:235:		if(row[6]) strcpy(coind->rpcencoding, row[6]);
db.cpp:244:			strcpy(buffer, row[2]);
db.cpp:247:				strcpy(buffer, row[2] + 8);
db.cpp:250:					strcpy(cert, buffer); cert[p] = '\0';
db.cpp:251:					strcpy(buffer, row[2] + 8 + p + 1);
db.cpp:253:					strcpy(cert, "yiimp");
db.cpp:258:			strcpy(coind->rpc.cert, "");
db.cpp:259:			strcpy(coind->rpc.host, buffer);
db.cpp:280:		if(row[16]) strcpy(coind->charity_address, row[16]);
db.cpp:295:		if(row[26]) strcpy(coind->algo, row[26]);
db.cpp:296:		if(row[27]) strcpy(coind->symbol2, row[27]); // if pool + aux, prevent double submit
db.cpp:300:		if(row[30]) strcpy(coind->rpc.cert, row[30]);
db.cpp:302:		if(row[31]) strcpy(coind->account, row[31]);
db.cpp:312:			strcpy(coind->rpcencoding, "DCR");
db.cpp:398:			memset(remote, 0, sizeof(YAAMP_REMOTE));
db.cpp:411:		strcpy(remote->host, row[2]);
db.cpp:413:		strcpy(remote->username, row[4]);
db.cpp:414:		strcpy(remote->password, row[5]);
db.cpp:528:			memset(renter, 0, sizeof(YAAMP_RENTER));

job.cpp:56:			strcpy(client->extranonce1, remote->nonce1);
job.cpp:89:		strcpy(client->extranonce1, client->extranonce1_default);
job.cpp:94:			memset(client->extranonce1, '0', sizeof(client->extranonce1));
job.cpp:95:			memcpy(&client->extranonce1[16], client->extranonce1_default, 8);
job.cpp:114:			strcpy(client->extranonce1_reconnect, client->extranonce1);
job.cpp:117:			strcpy(client->extranonce1, client->extranonce1_default);
job.cpp:130:			strcpy(client->extranonce1_last, client->extranonce1);

job_send.cpp:210://		strcpy(name, job->coind->symbol);

json.cpp:236:   memcpy (&state.settings, settings, sizeof (json_settings));
json.cpp:244:   memset (&state.uint_max, 0xFF, sizeof (state.uint_max));
json.cpp:245:   memset (&state.ulong_max, 0xFF, sizeof (state.ulong_max));
json.cpp:884:   strcpy (error, "Memory allocation failure");
json.cpp:897:         strcpy (error_buf, error);
json.cpp:899:         strcpy (error_buf, "Unknown error");

remote.cpp:184:			strncpy(remote->nonce1_next, json_result->u.array.values[1]->u.string.ptr, 16);
remote.cpp:234:				strncpy(remote->nonce1_next, json_params->u.array.values[0]->u.string.ptr, 16);
remote.cpp:247:				strncpy(remote->jobid, json_params->u.array.values[0]->u.string.ptr, 16);
remote.cpp:254:					strncpy(remote->nonce1, remote->nonce1_next, 16);

remote_template.cpp:63:	memset(templ, 0, sizeof(YAAMP_JOB_TEMPLATE));
remote_template.cpp:65:	strncpy(templ->prevhash_be, json_params->u.array.values[1]->u.string.ptr, sizeof(templ->prevhash_be)-1);
remote_template.cpp:66:	strncpy(templ->coinb1, json_params->u.array.values[2]->u.string.ptr, 1023);
remote_template.cpp:67:	strncpy(templ->coinb2, json_params->u.array.values[3]->u.string.ptr, 1023);
remote_template.cpp:69:	strncpy(templ->version, json_params->u.array.values[5]->u.string.ptr, 16);
remote_template.cpp:70:	strncpy(templ->nbits, json_params->u.array.values[6]->u.string.ptr, 16);
remote_template.cpp:71:	strncpy(templ->ntime, json_params->u.array.values[7]->u.string.ptr, 16);
remote_template.cpp:81:		if(i>0) strcat(templ->txmerkles, ",");
remote_template.cpp:90:	memset(remote->job, 0, sizeof(YAAMP_JOB));
remote_template.cpp:93:	if(remote->nonce2size == 2) strcat(remote->job->name, "*");

rpc.cpp:111:	memcpy(rpc->buffer + rpc->bufpos, buffer, bytes);
rpc.cpp:212:	memcpy(databuf, p+4, bufpos+1);

rpc_curl.cpp:53:	memset(db, 0, sizeof(*db));
rpc_curl.cpp:73:	memcpy((char*)db->buf + oldlen, ptr, len);
rpc_curl.cpp:74:	memcpy((char*)db->buf + newlen, &zero, 1);	/* null terminate */
rpc_curl.cpp:88:		memcpy(ptr, (char*)ub->buf + ub->pos, len);
rpc_curl.cpp:136:	memcpy(key, ptr, slen);		/* store & nul term key */
rpc_curl.cpp:146:	memcpy(val, rem, remlen);	/* store value, trim trailing ws */
rpc_curl.cpp:288:		strcpy(curl_last_err, "rpc warning: no data received");
rpc_curl.cpp:392:	strcpy(curl_last_err, "");

share.cpp:53:		memset(worker, 0, sizeof(YAAMP_WORKER));
share.cpp:100:	memset(share, 0, sizeof(YAAMP_SHARE));
share.cpp:103:	strcpy(share->extranonce2, extranonce2);
share.cpp:104:	strcpy(share->ntime, ntime);
share.cpp:105:	strcpy(share->nonce, nonce);
share.cpp:106:	strcpy(share->nonce1, client->extranonce1);
share.cpp:151:		if(count) strcat(buffer, ",");
share.cpp:166:			strcpy(buffer, "insert into shares (userid, workerid, coinid, jobid, pid, valid, extranonce1, difficulty, share_diff, time, algo, error) values ");
share.cpp:217:		if(count) strcat(buffer, ",");
share.cpp:233:	memset(block, 0, sizeof(YAAMP_BLOCK));
share.cpp:244:	strcpy(block->hash1, h1);
share.cpp:245:	strcpy(block->hash2, h2);
share.cpp:316:				strncpy(block->hash, blockhash, 65);
share.cpp:330:	memset(submit, 0, sizeof(YAAMP_SUBMIT));
share.cpp:351:		if(count) strcat(buffer, ",");
share.cpp:359:			strcpy(buffer, "insert into jobsubmits (jobid, valid, difficulty, time, algo, status) values ");
socket.cpp:21:		memcmp(&hdr.v2, v2sig, 12) == 0 &&
socket.cpp:40:		memset(&name, 0, len);
socket.cpp:57:	memset(s, 0, sizeof(YAAMP_SOCKET));
socket.cpp:70:		memset(&name, 0, len);
socket.cpp:183:		memset(s->buffer, 0, YAAMP_SOCKET_BUFSIZE);
stratum.cpp:243:	strcpy(g_tcp_server, iniparser_getstring(ini, "TCP:server", NULL));
stratum.cpp:244:	strcpy(g_tcp_password, iniparser_getstring(ini, "TCP:password", NULL));
stratum.cpp:246:	strcpy(g_sql_host, iniparser_getstring(ini, "SQL:host", NULL));
stratum.cpp:247:	strcpy(g_sql_database, iniparser_getstring(ini, "SQL:database", NULL));
stratum.cpp:248:	strcpy(g_sql_username, iniparser_getstring(ini, "SQL:username", NULL));
stratum.cpp:249:	strcpy(g_sql_password, iniparser_getstring(ini, "SQL:password", NULL));
stratum.cpp:254:	strcpy(g_stratum_coin_include, coin_filter ? coin_filter : "");
stratum.cpp:256:	strcpy(g_stratum_coin_exclude, coin_filter ? coin_filter : "");
stratum.cpp:258:	strcpy(g_stratum_algo, iniparser_getstring(ini, "STRATUM:algo", NULL));

user.cpp:29:			strcpy(symbol, row[0]);
user.cpp:48:	if(p) strncpy(symbol, p+2, 15);
user.cpp:69:				if (!strlen(client->worker)) strcpy(client->worker, client->username);
user.cpp:70:				strcpy(client->username, coind->wallet);
user.cpp:71:				if (!strcmp(client->username, "benchmark")) strcat(client->password, ",stats");
user.cpp:161:	strncpy(password, client->password, 64);
user.cpp:162:	strncpy(version, client->version, 64);
user.cpp:163:	strncpy(worker, client->worker, 64);
util.cpp:193:	strcpy(hex+strlen(hex), "\n");
util.cpp:313:		strncpy(value, p, 1024);
util.cpp:317:	strncpy(value, p, min(1024, p2 - p));
util.cpp:377:	memset(decoding_tab, 255, 256);
util.cpp:450:	strcpy(buffer, tmp);
util.cpp:458:	memset(s, 0, 32);
util.cpp:459:	memset(a, 0, 32);
util.cpp:476:		strcat(a, tmp);
util.cpp:486:			memcpy(output + i*8 + (6-j), input + i*8 + j, 2);
util.cpp:492:		memcpy(output + i*8, input + (len-i-1)*8, 8);
util.cpp:500:		memcpy(output + (len-i-1)*2, input + i*2, 2);
util.cpp:506:	strcpy(s2, s);
util.cpp:511:		memcpy(s + (len-i-1)*2, s2 + i*2, 2);
