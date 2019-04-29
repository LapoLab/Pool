#client.cpp#-547-		}
#client.cpp#-548-
#client.cpp#-549-		json_value *json = socket_nextjson(client->sock, client);
#client.cpp#-550-		if(!json)
#client.cpp#-551-		{
#client.cpp#-552-//			clientlog(client, "bad json");
#client.cpp#-553-			break;
#client.cpp#-554-		}
#client.cpp#-555-
#client.cpp#-556-		client->id_int = json_get_int(json, "id");
#client.cpp#:557:		client->id_str = json_get_string(json, "id");
#client.cpp#-558-		if (client->id_str && strlen(client->id_str) > 32) {
#client.cpp#-559-			clientlog(client, "bad id");
#client.cpp#-560-			break;
#client.cpp#-561-		}
#client.cpp#-562-
#client.cpp#:563:		const char *method = json_get_string(json, "method");
#client.cpp#-564-
#client.cpp#-565-		if (!method && client->stats && client->id_int == client->reqid)
#client.cpp#-566-		{
#client.cpp#-567-			json_value *result = json_get_object(json, "result");
#client.cpp#-568-			if (result) client_store_stats(client, result);
#client.cpp#-569-			json_value_free(json);
#client.cpp#-570-			continue;
#client.cpp#-571-		}
#client.cpp#-572-
#client.cpp#-573-		if(!method)
--
client.cpp-547-		}
client.cpp-548-
client.cpp-549-		json_value *json = socket_nextjson(client->sock, client);
client.cpp-550-		if(!json)
client.cpp-551-		{
client.cpp-552-//			clientlog(client, "bad json");
client.cpp-553-			break;
client.cpp-554-		}
client.cpp-555-
client.cpp-556-		client->id_int = json_get_int(json, "id");
client.cpp:557:		client->id_str = json_get_string(json, "id");
client.cpp-558-		if (client->id_str && strlen(client->id_str) > 32) {
client.cpp-559-			clientlog(client, "bad id");
client.cpp-560-			break;
client.cpp-561-		}
client.cpp-562-
client.cpp:563:		const char *method = json_get_string(json, "method");
client.cpp-564-
client.cpp-565-		if (!method && client->stats && client->id_int == client->reqid)
client.cpp-566-		{
client.cpp-567-			json_value *result = json_get_object(json, "result");
client.cpp-568-			if (result) client_store_stats(client, result);
client.cpp-569-			json_value_free(json);
client.cpp-570-			continue;
client.cpp-571-		}
client.cpp-572-
client.cpp-573-		if(!method)
--
coinbase.cpp-164-			sprintf(coind->charity_address, "Dcur2mcGjmENx4DhNqDctW5wJCVyT3Qeqkx");
coinbase.cpp-165-	}
coinbase.cpp-166-	else if(strcmp(coind->symbol, "STAK") == 0) {
coinbase.cpp-167-		char script_payee[512] = { 0 };
coinbase.cpp-168-		char payees[4];
coinbase.cpp-169-		int npayees = (templ->has_segwit_txs) ? 2 : 1;
coinbase.cpp-170-		bool masternode_payments = json_get_bool(json_result, "masternode_payments");
coinbase.cpp-171-		bool masternodes_enabled = json_get_bool(json_result, "enforce_masternode_payments");
coinbase.cpp-172-
coinbase.cpp-173-		if (masternodes_enabled && masternode_payments) {
coinbase.cpp:174:			const char *payee = json_get_string(json_result, "payee");
coinbase.cpp-175-			json_int_t amount = json_get_int(json_result, "payee_amount");
coinbase.cpp-176-			if (payee && amount)
coinbase.cpp-177-				++npayees;
coinbase.cpp-178-		}
coinbase.cpp-179-
coinbase.cpp-180-		//treasury 5% @ 10 STAK per block
coinbase.cpp-181-		json_int_t charity_amount = 50000000;
coinbase.cpp-182-		//testnet
coinbase.cpp-183-		//sprintf(coind->charity_address, "93ASJtDuVYVdKXemH9BrtSMscznvsp9stD");
coinbase.cpp-184-		switch (templ->height % 4) {
--
coinbase.cpp-201-		encode_tx_value(echarity_amount, charity_amount);
coinbase.cpp-202-		strcat(templ->coinb2, echarity_amount);
coinbase.cpp-203-		char coinb2_part[1024] = { 0 };
coinbase.cpp-204-		char coinb2_len[3] = { 0 };
coinbase.cpp-205-		sprintf(coinb2_part, "a9%02x%s87", (unsigned int)(strlen(script_payee) >> 1) & 0xFF, script_payee);
coinbase.cpp-206-		sprintf(coinb2_len, "%02x", (unsigned int)(strlen(coinb2_part) >> 1) & 0xFF);
coinbase.cpp-207-		strcat(templ->coinb2, coinb2_len);
coinbase.cpp-208-		strcat(templ->coinb2, coinb2_part);
coinbase.cpp-209-		if (masternodes_enabled && masternode_payments) {
coinbase.cpp-210-			//duplicated: revisit ++todo
coinbase.cpp:211:			const char *payee = json_get_string(json_result, "payee");
coinbase.cpp-212-			json_int_t amount = json_get_int(json_result, "payee_amount");
coinbase.cpp-213-			if (payee && amount) {
coinbase.cpp-214-				available -= amount;
coinbase.cpp-215-				base58_decode(payee, script_payee);
coinbase.cpp-216-				job_pack_tx(coind, templ->coinb2, amount, script_payee);
coinbase.cpp-217-			}
coinbase.cpp-218-		}
coinbase.cpp-219-		job_pack_tx(coind, templ->coinb2, available, NULL);
coinbase.cpp-220-		strcat(templ->coinb2, "00000000"); // locktime
coinbase.cpp-221-
coinbase.cpp-222-		coind->reward = (double)available / 100000000 * coind->reward_mul;
coinbase.cpp-223-		return;
coinbase.cpp-224-	}
coinbase.cpp-225-
coinbase.cpp-226-	// 2 txs are required on these coins, one for foundation (dev fees)
coinbase.cpp-227-	if(coind->charity_percent && !coind->hasmasternodes)
coinbase.cpp-228-	{
coinbase.cpp-229-		char script_payee[1024];
coinbase.cpp-230-		char charity_payee[256] = { 0 };
coinbase.cpp:231:		const char *payee = json_get_string(json_result, "payee");
coinbase.cpp-232-		if (payee) snprintf(charity_payee, 255, "%s", payee);
coinbase.cpp-233-		else sprintf(charity_payee, "%s", coind->charity_address);
coinbase.cpp-234-		if (strlen(charity_payee) == 0)
coinbase.cpp-235-			stratumlog("ERROR %s has no charity_address set!\n", coind->name);
coinbase.cpp-236-
coinbase.cpp-237-		base58_decode(charity_payee, script_payee);
coinbase.cpp-238-
coinbase.cpp-239-		json_int_t charity_amount = (available * coind->charity_percent) / 100;
coinbase.cpp-240-		available -= charity_amount;
coinbase.cpp-241-		coind->charity_amount = charity_amount;
--
coinbase.cpp-259-		stratumlog("ERROR %s should not use coinbase (getwork only)!\n", coind->symbol);
coinbase.cpp-260-		coind->reward = (double)available/100000000;
coinbase.cpp-261-		return;
coinbase.cpp-262-	}
coinbase.cpp-263-
coinbase.cpp-264-	if(strcmp(coind->symbol, "XVC") == 0)
coinbase.cpp-265-	{
coinbase.cpp-266-		char charity_payee[256];
coinbase.cpp-267-		json_value* incentive = json_get_object(json_result, "incentive");
coinbase.cpp-268-		if (incentive) {
coinbase.cpp:269:			const char* payee = json_get_string(incentive, "address");
coinbase.cpp-270-			if (payee) snprintf(charity_payee, 255, "%s", payee);
coinbase.cpp-271-			else sprintf(charity_payee, "%s", coind->charity_address);
coinbase.cpp-272-
coinbase.cpp-273-			bool enforced = json_get_bool(incentive, "enforced");
coinbase.cpp-274-			json_int_t charity_amount = json_get_int(incentive, "amount");
coinbase.cpp-275-			if (enforced && charity_amount && strlen(charity_payee)) {
coinbase.cpp-276-				char script_payee[1024];
coinbase.cpp-277-				base58_decode(charity_payee, script_payee);
coinbase.cpp-278-
coinbase.cpp-279-				strcat(templ->coinb2, "02");
--
coinbase.cpp-301-		bool superblocks_enabled = json_get_bool(json_result, "superblocks_enabled");
coinbase.cpp-302-		json_value* superblock = json_get_array(json_result, "superblock");
coinbase.cpp-303-		json_value* masternode = json_get_object(json_result, "masternode");
coinbase.cpp-304-		if(!masternode && json_get_bool(json_result, "masternode_payments")) {
coinbase.cpp-305-			coind->oldmasternodes = true;
coinbase.cpp-306-			debuglog("%s is using old masternodes rpc keys\n", coind->symbol);
coinbase.cpp-307-			return;
coinbase.cpp-308-		}
coinbase.cpp-309-		if(coind->charity_percent) {
coinbase.cpp-310-            		char charity_payee[256] = { 0 };
coinbase.cpp:311:            		const char *payee = json_get_string(json_result, "payee");
coinbase.cpp-312-            		if (payee) snprintf(charity_payee, 255, "%s", payee);
coinbase.cpp-313-            		else sprintf(charity_payee, "%s", coind->charity_address);
coinbase.cpp-314-            		if (strlen(charity_payee) == 0)
coinbase.cpp-315-                		stratumlog("ERROR %s has no charity_address set!\n", coind->name);
coinbase.cpp-316-            		json_int_t charity_amount = (available * coind->charity_percent) / 100;
coinbase.cpp-317-            		npayees++;
coinbase.cpp-318-            		available -= charity_amount;
coinbase.cpp-319-            		coind->charity_amount = charity_amount;
coinbase.cpp-320-            		base58_decode(charity_payee, script_payee);
coinbase.cpp-321-           		job_pack_tx(coind, script_dests, charity_amount, script_payee);
coinbase.cpp-322-        	}
coinbase.cpp-323-		// smart contracts balance refund, same format as DASH superblocks
coinbase.cpp-324-		json_value* screfund = json_get_array(json_result, "screfund");
coinbase.cpp-325-		if(screfund && screfund->u.array.length) {
coinbase.cpp-326-			superblocks_enabled = true;
coinbase.cpp-327-			superblock = screfund;
coinbase.cpp-328-		}
coinbase.cpp-329-		if(superblocks_enabled && superblock) {
coinbase.cpp-330-			for(int i = 0; i < superblock->u.array.length; i++) {
coinbase.cpp:331:				const char *payee = json_get_string(superblock->u.array.values[i], "payee");
coinbase.cpp-332-				json_int_t amount = json_get_int(superblock->u.array.values[i], "amount");
coinbase.cpp-333-				if (payee && amount) {
coinbase.cpp-334-					npayees++;
coinbase.cpp-335-					available -= amount;
coinbase.cpp-336-					base58_decode(payee, script_payee);
coinbase.cpp-337-					bool superblock_use_p2sh = (strcmp(coind->symbol, "MAC") == 0);
coinbase.cpp-338-					if(superblock_use_p2sh)
coinbase.cpp-339-						p2sh_pack_tx(coind, script_dests, amount, script_payee);
coinbase.cpp-340-					else
coinbase.cpp-341-						job_pack_tx(coind, script_dests, amount, script_payee);
coinbase.cpp-342-					//debuglog("%s superblock %s %u\n", coind->symbol, payee, amount);
coinbase.cpp-343-				}
coinbase.cpp-344-			}
coinbase.cpp-345-		}
coinbase.cpp-346-		if (masternode_enabled && masternode) {
coinbase.cpp-347-			bool started = json_get_bool(json_result, "masternode_payments_started");
coinbase.cpp:348:			const char *payee = json_get_string(masternode, "payee");
coinbase.cpp-349-			json_int_t amount = json_get_int(masternode, "amount");
coinbase.cpp-350-			if (payee && amount && started) {
coinbase.cpp-351-				npayees++;
coinbase.cpp-352-				available -= amount;
coinbase.cpp-353-				base58_decode(payee, script_payee);
coinbase.cpp-354-				bool masternode_use_p2sh = (strcmp(coind->symbol, "MAC") == 0);
coinbase.cpp-355-				if(masternode_use_p2sh)
coinbase.cpp-356-					p2sh_pack_tx(coind, script_dests, amount, script_payee);
coinbase.cpp-357-				else
coinbase.cpp-358-					job_pack_tx(coind, script_dests, amount, script_payee);
--
coinbase.cpp-375-		char script_dests[2048] = { 0 };
coinbase.cpp-376-		char script_payee[128] = { 0 };
coinbase.cpp-377-		char payees[4];
coinbase.cpp-378-		int npayees = 1;
coinbase.cpp-379-		bool masternode_enabled = json_get_bool(json_result, "goldminenode_payments_enforced");
coinbase.cpp-380-		bool superblocks_enabled = json_get_bool(json_result, "superblocks_enabled");
coinbase.cpp-381-		json_value* superblock = json_get_array(json_result, "superblock");
coinbase.cpp-382-		json_value* masternode = json_get_object(json_result, "goldminenode");
coinbase.cpp-383-		if(superblocks_enabled && superblock) {
coinbase.cpp-384-			for(int i = 0; i < superblock->u.array.length; i++) {
coinbase.cpp:385:				const char *payee = json_get_string(superblock->u.array.values[i], "payee");
coinbase.cpp-386-				json_int_t amount = json_get_int(superblock->u.array.values[i], "amount");
coinbase.cpp-387-				if (payee && amount) {
coinbase.cpp-388-					npayees++;
coinbase.cpp-389-					available -= amount;
coinbase.cpp-390-					base58_decode(payee, script_payee);
coinbase.cpp-391-					job_pack_tx(coind, script_dests, amount, script_payee);
coinbase.cpp-392-					//debuglog("%s superblock %s %u\n", coind->symbol, payee, amount);
coinbase.cpp-393-				}
coinbase.cpp-394-			}
coinbase.cpp-395-		}
coinbase.cpp-396-		if (masternode_enabled && masternode) {
coinbase.cpp:397:			const char *payee = json_get_string(masternode, "payee");
coinbase.cpp-398-			json_int_t amount = json_get_int(masternode, "amount");
coinbase.cpp-399-			if (payee && amount) {
coinbase.cpp-400-				npayees++;
coinbase.cpp-401-				available -= amount;
coinbase.cpp-402-				base58_decode(payee, script_payee);
coinbase.cpp-403-				job_pack_tx(coind, script_dests, amount, script_payee);
coinbase.cpp-404-			}
coinbase.cpp-405-		}
coinbase.cpp-406-		sprintf(payees, "%02x", npayees);
coinbase.cpp-407-		strcat(templ->coinb2, payees);
--
coinbase.cpp-418-		char script_dests[2048] = { 0 };
coinbase.cpp-419-		char script_payee[128] = { 0 };
coinbase.cpp-420-		char payees[4];
coinbase.cpp-421-		int npayees = 1;
coinbase.cpp-422-		bool masternode_enabled = json_get_bool(json_result, "eternitynode_payments_enforced");
coinbase.cpp-423-		bool superblocks_enabled = json_get_bool(json_result, "superblocks_enabled");
coinbase.cpp-424-		json_value* superblock = json_get_array(json_result, "superblock");
coinbase.cpp-425-		json_value* masternode = json_get_object(json_result, "eternitynode");
coinbase.cpp-426-		if(superblocks_enabled && superblock) {
coinbase.cpp-427-			for(int i = 0; i < superblock->u.array.length; i++) {
coinbase.cpp:428:				const char *payee = json_get_string(superblock->u.array.values[i], "payee");
coinbase.cpp-429-				json_int_t amount = json_get_int(superblock->u.array.values[i], "amount");
coinbase.cpp-430-				if (payee && amount) {
coinbase.cpp-431-					npayees++;
coinbase.cpp-432-					available -= amount;
coinbase.cpp-433-					base58_decode(payee, script_payee);
coinbase.cpp-434-					job_pack_tx(coind, script_dests, amount, script_payee);
coinbase.cpp-435-					//debuglog("%s superblock %s %u\n", coind->symbol, payee, amount);
coinbase.cpp-436-				}
coinbase.cpp-437-			}
coinbase.cpp-438-		}
coinbase.cpp-439-		if (masternode_enabled && masternode) {
coinbase.cpp:440:			const char *payee = json_get_string(masternode, "payee");
coinbase.cpp-441-			json_int_t amount = json_get_int(masternode, "amount");
coinbase.cpp-442-			if (payee && amount) {
coinbase.cpp-443-				npayees++;
coinbase.cpp-444-				available -= amount;
coinbase.cpp-445-				base58_decode(payee, script_payee);
coinbase.cpp-446-				job_pack_tx(coind, script_dests, amount, script_payee);
coinbase.cpp-447-			}
coinbase.cpp-448-		}
coinbase.cpp-449-		sprintf(payees, "%02x", npayees);
coinbase.cpp-450-		strcat(templ->coinb2, payees);
--
coinbase.cpp-453-		strcat(templ->coinb2, "00000000"); // locktime
coinbase.cpp-454-		coind->reward = (double)available/100000000*coind->reward_mul;
coinbase.cpp-455-		//debuglog("%s %d dests %s\n", coind->symbol, npayees, script_dests);
coinbase.cpp-456-		return;
coinbase.cpp-457-	}
coinbase.cpp-458-
coinbase.cpp-459-
coinbase.cpp-460-	else if(coind->hasmasternodes && coind->oldmasternodes) /* OLD DASH style */
coinbase.cpp-461-	{
coinbase.cpp-462-		char charity_payee[256] = { 0 };
coinbase.cpp:463:		const char *payee = json_get_string(json_result, "payee");
coinbase.cpp-464-		if (payee) snprintf(charity_payee, 255, "%s", payee);
coinbase.cpp-465-
coinbase.cpp-466-		json_int_t charity_amount = json_get_int(json_result, "payee_amount");
coinbase.cpp-467-		bool charity_payments = json_get_bool(json_result, "masternode_payments");
coinbase.cpp-468-		bool charity_enforce = json_get_bool(json_result, "enforce_masternode_payments");
coinbase.cpp-469-
coinbase.cpp-470-		if(strcmp(coind->symbol, "CRW") == 0)
coinbase.cpp-471-		{
coinbase.cpp-472-			char script_dests[2048] = { 0 };
coinbase.cpp-473-			char script_payee[128] = { 0 };
coinbase.cpp-474-			char payees[4];
coinbase.cpp-475-			int npayees = 1;
coinbase.cpp-476-			bool masternodes_enabled = json_get_bool(json_result, "enforce_masternode_payments");
coinbase.cpp-477-			bool systemnodes_enabled = json_get_bool(json_result, "enforce_systemnode_payments");
coinbase.cpp-478-			bool systemnodes = json_get_bool(json_result, "systemnodes");
coinbase.cpp-479-			bool masternodes = json_get_bool(json_result, "masternodes");
coinbase.cpp-480-			if(systemnodes_enabled && systemnodes) {
coinbase.cpp:481:				const char *payeeSN = json_get_string(json_result, "payeeSN");
coinbase.cpp-482-				json_int_t payeeSN_amount = json_get_int(json_result, "payeeSN_amount");
coinbase.cpp-483-				if (payeeSN && payeeSN_amount) {
coinbase.cpp-484-					npayees++;
coinbase.cpp-485-					available -= payeeSN_amount;
coinbase.cpp-486-					base58_decode(payeeSN, script_payee);
coinbase.cpp-487-					job_pack_tx(coind, script_dests, payeeSN_amount, script_payee);
coinbase.cpp-488-					//debuglog("%s systemnode %s %u\n", coind->symbol, payeeSN, payeeSN_amount);
coinbase.cpp-489-				}
coinbase.cpp-490-			}
coinbase.cpp-491-			if (masternodes_enabled && masternodes) {
coinbase.cpp:492:				const char *payee = json_get_string(json_result, "payee");
coinbase.cpp-493-				json_int_t amount = json_get_int(json_result, "amount");
coinbase.cpp-494-				if (payee && amount) {
coinbase.cpp-495-					npayees++;
coinbase.cpp-496-					available -= amount;
coinbase.cpp-497-					base58_decode(payee, script_payee);
coinbase.cpp-498-					job_pack_tx(coind, script_dests, amount, script_payee);
coinbase.cpp-499-				}
coinbase.cpp-500-			}
coinbase.cpp-501-			sprintf(payees, "%02x", npayees);
coinbase.cpp-502-			strcat(templ->coinb2, payees);
--
#coind.cpp#-129-		return false;
#coind.cpp#-130-	}
#coind.cpp#-131-
#coind.cpp#-132-	bool isvalid = getaddressinfo || json_get_bool(json_result, "isvalid");
#coind.cpp#-133-	if(!isvalid) stratumlog("%s wallet %s is not valid.\n", coind->name, coind->wallet);
#coind.cpp#-134-
#coind.cpp#-135-	bool ismine = json_get_bool(json_result, "ismine");
#coind.cpp#-136-	if(!ismine) stratumlog("%s wallet %s is not mine.\n", coind->name, coind->wallet);
#coind.cpp#-137-	else isvalid = ismine;
#coind.cpp#-138-
#coind.cpp#:139:	const char *p = json_get_string(json_result, "pubkey");
#coind.cpp#-140-	strcpy(coind->pubkey, p ? p : "");
#coind.cpp#-141-
#coind.cpp#:142:	const char *acc = json_get_string(json_result, "account");
#coind.cpp#-143-	if (acc) strcpy(coind->account, acc);
#coind.cpp#-144-
#coind.cpp#-145-	if (!base58_decode(coind->wallet, coind->script_pubkey))
#coind.cpp#-146-		stratumlog("Warning: unable to decode %s %s script pubkey\n", coind->symbol, coind->wallet);
#coind.cpp#-147-
#coind.cpp#-148-	coind->p2sh_address = json_get_bool(json_result, "isscript");
#coind.cpp#-149-
#coind.cpp#-150-	// if base58 decode fails
#coind.cpp#-151-	if (!strlen(coind->script_pubkey)) {
#coind.cpp#:152:		const char *pk = json_get_string(json_result, "scriptPubKey");
#coind.cpp#-153-		if (pk && strlen(pk) > 10) {
#coind.cpp#-154-			strcpy(coind->script_pubkey, &pk[6]);
#coind.cpp#-155-			coind->script_pubkey[strlen(pk)-6-4] = '\0';
#coind.cpp#-156-			stratumlog("%s %s extracted script pubkey is %s\n", coind->symbol, coind->wallet, coind->script_pubkey);
#coind.cpp#-157-		} else {
#coind.cpp#-158-			stratumlog("%s wallet addr '%s' seems incorrect!'", coind->symbol, coind->wallet);
#coind.cpp#-159-		}
#coind.cpp#-160-	}
#coind.cpp#-161-	json_value_free(json);
#coind.cpp#-162-
--
coind.cpp-129-		return false;
coind.cpp-130-	}
coind.cpp-131-
coind.cpp-132-	bool isvalid = getaddressinfo || json_get_bool(json_result, "isvalid");
coind.cpp-133-	if(!isvalid) stratumlog("%s wallet %s is not valid.\n", coind->name, coind->wallet);
coind.cpp-134-
coind.cpp-135-	bool ismine = json_get_bool(json_result, "ismine");
coind.cpp-136-	if(!ismine) stratumlog("%s wallet %s is not mine.\n", coind->name, coind->wallet);
coind.cpp-137-	else isvalid = ismine;
coind.cpp-138-
coind.cpp:139:	const char *p = json_get_string(json_result, "pubkey");
coind.cpp-140-	strcpy(coind->pubkey, p ? p : "");
coind.cpp-141-
coind.cpp:142:	const char *acc = json_get_string(json_result, "account");
coind.cpp-143-	if (acc) strcpy(coind->account, acc);
coind.cpp-144-
coind.cpp-145-	if (!base58_decode(coind->wallet, coind->script_pubkey))
coind.cpp-146-		stratumlog("Warning: unable to decode %s %s script pubkey\n", coind->symbol, coind->wallet);
coind.cpp-147-
coind.cpp-148-	coind->p2sh_address = json_get_bool(json_result, "isscript");
coind.cpp-149-
coind.cpp-150-	// if base58 decode fails
coind.cpp-151-	if (!strlen(coind->script_pubkey)) {
coind.cpp:152:		const char *pk = json_get_string(json_result, "scriptPubKey");
coind.cpp-153-		if (pk && strlen(pk) > 10) {
coind.cpp-154-			strcpy(coind->script_pubkey, &pk[6]);
coind.cpp-155-			coind->script_pubkey[strlen(pk)-6-4] = '\0';
coind.cpp-156-			stratumlog("%s %s extracted script pubkey is %s\n", coind->symbol, coind->wallet, coind->script_pubkey);
coind.cpp-157-		} else {
coind.cpp-158-			stratumlog("%s wallet addr '%s' seems incorrect!'", coind->symbol, coind->wallet);
coind.cpp-159-		}
coind.cpp-160-	}
coind.cpp-161-	json_value_free(json);
coind.cpp-162-
--
coind_submit.cpp-129-
coind_submit.cpp-130-	sprintf(params, "[\"%s\"]", block);
coind_submit.cpp-131-	json_value *json = rpc_call(&coind->rpc, "submitblock", params);
coind_submit.cpp-132-
coind_submit.cpp-133-	free(params);
coind_submit.cpp-134-	NULLRETFALSE(json, "ERROR submitblock returned NULL");
coind_submit.cpp-135-
coind_submit.cpp-136-	json_value *json_error = json_get_object(json, "error");
coind_submit.cpp-137-	if(json_error && json_error->type != json_null)
coind_submit.cpp-138-	{
coind_submit.cpp:139:		const char *p = json_get_string(json_error, "message");
coind_submit.cpp-140-		if(p) { 
coind_submit.cpp-141-			cdslog("ERROR %s %s %s\n", coind->name, p, __func__);
coind_submit.cpp-142-			the_log.write("ERROR: ");
coind_submit.cpp-143-			the_log.write(p);
coind_submit.cpp-144-			the_log.write("\n", true);
coind_submit.cpp-145-		} else {
coind_submit.cpp-146-			the_log.write("unidentified error...\n", true);
coind_submit.cpp-147-		}
coind_submit.cpp-148-	//	job_reset();
coind_submit.cpp-149-		json_value_free(json);
coind_submit.cpp-150-
coind_submit.cpp-151-		return false;
coind_submit.cpp-152-	}
coind_submit.cpp-153-
coind_submit.cpp-154-	json_value *json_result = json_get_object(json, "result");
coind_submit.cpp-155-
coind_submit.cpp-156-	bool b = json_result && json_result->type == json_null;
coind_submit.cpp-157-
coind_submit.cpp-158-	if (json_result) {
coind_submit.cpp:159:		const char *p = json_get_string(json_result, "message");
coind_submit.cpp-160-		if (p) {
coind_submit.cpp-161-			the_log.write("MESSAGE: ");
coind_submit.cpp-162-			the_log.write(p);
coind_submit.cpp-163-			the_log.write("\n", true);
coind_submit.cpp-164-		} else {
coind_submit.cpp-165-			the_log.write("NO MESSAGE\n", true);
coind_submit.cpp-166-		}
coind_submit.cpp-167-	}
coind_submit.cpp-168-
coind_submit.cpp-169-	json_value_free(json);
--
coind_submit.cpp-180-
coind_submit.cpp-181-	sprintf(params, "[{\"mode\": \"submit\", \"data\": \"%s\"}]", block);
coind_submit.cpp-182-	json_value *json = rpc_call(&coind->rpc, "getblocktemplate", params);
coind_submit.cpp-183-
coind_submit.cpp-184-	free(params);
coind_submit.cpp-185-	NULLRETFALSE(json, "ERROR submitblock returned NULL");
coind_submit.cpp-186-
coind_submit.cpp-187-	json_value *json_error = json_get_object(json, "error");
coind_submit.cpp-188-	if(json_error && json_error->type != json_null)
coind_submit.cpp-189-	{
coind_submit.cpp:190:		const char *p = json_get_string(json_error, "message");
coind_submit.cpp-191-		if(p) cdslog("ERROR %s %s %s\n", coind->name, p, __func__);
coind_submit.cpp-192-
coind_submit.cpp-193-	//	job_reset();
coind_submit.cpp-194-		json_value_free(json);
coind_submit.cpp-195-
coind_submit.cpp-196-		return false;
coind_submit.cpp-197-	}
coind_submit.cpp-198-
coind_submit.cpp-199-	json_value *json_result = json_get_object(json, "result");
coind_submit.cpp-200-
--
coind_submit.cpp-227-
coind_submit.cpp-228-	sprintf(params, "[\"%s\",\"%s\"]", hash, block);
coind_submit.cpp-229-	json_value *json = rpc_call(&coind->rpc, "getauxblock", params);
coind_submit.cpp-230-
coind_submit.cpp-231-	free(params);
coind_submit.cpp-232-	if(!json) return false;
coind_submit.cpp-233-
coind_submit.cpp-234-	json_value *json_error = json_get_object(json, "error");
coind_submit.cpp-235-	if(json_error && json_error->type != json_null)
coind_submit.cpp-236-	{
coind_submit.cpp:237:		const char *p = json_get_string(json_error, "message");
coind_submit.cpp-238-		if(p) stratumlog("ERROR %s %s\n", coind->name, p);
coind_submit.cpp-239-
coind_submit.cpp-240-	//	job_reset();
coind_submit.cpp-241-		json_value_free(json);
coind_submit.cpp-242-
coind_submit.cpp-243-		return false;
coind_submit.cpp-244-	}
coind_submit.cpp-245-
coind_submit.cpp-246-	json_value *json_result = json_get_object(json, "result");
coind_submit.cpp-247-	bool b = json_result && json_result->type == json_boolean && json_result->u.boolean;
--
coind_template.cpp-15-	json_value *json_result = json_get_object(json, "result");
coind_template.cpp-16-	if(!json_result)
coind_template.cpp-17-	{
coind_template.cpp-18-		coind_error(coind, "coind_getauxblock");
coind_template.cpp-19-		return;
coind_template.cpp-20-	}
coind_template.cpp-21-
coind_template.cpp-22-//	coind->aux.height = coind->height+1;
coind_template.cpp-23-	coind->aux.chainid = json_get_int(json_result, "chainid");
coind_template.cpp-24-
coind_template.cpp:25:	const char *p = json_get_string(json_result, "target");
coind_template.cpp-26-	if(p) strcpy(coind->aux.target, p);
coind_template.cpp-27-
coind_template.cpp:28:	p = json_get_string(json_result, "hash");
coind_template.cpp-29-	if(p) strcpy(coind->aux.hash, p);
coind_template.cpp-30-
coind_template.cpp-31-//	if(strcmp(coind->symbol, "UNO") == 0)
coind_template.cpp-32-//	{
coind_template.cpp-33-//		string_be1(coind->aux.target);
coind_template.cpp-34-//		string_be1(coind->aux.hash);
coind_template.cpp-35-//	}
coind_template.cpp-36-
coind_template.cpp-37-	json_value_free(json);
coind_template.cpp-38-}
--
coind_template.cpp-56-	}
coind_template.cpp-57-
coind_template.cpp-58-	YAAMP_JOB_TEMPLATE *templ = new YAAMP_JOB_TEMPLATE;
coind_template.cpp-59-	memset(templ, 0, sizeof(YAAMP_JOB_TEMPLATE));
coind_template.cpp-60-
coind_template.cpp-61-	templ->created = time(NULL);
coind_template.cpp-62-	templ->value = json_get_int(json_result, "coinbasevalue");
coind_template.cpp-63-//	templ->height = json_get_int(json_result, "height");
coind_template.cpp-64-	sprintf(templ->version, "%08x", (unsigned int)json_get_int(json_result, "version"));
coind_template.cpp-65-	sprintf(templ->ntime, "%08x", (unsigned int)json_get_int(json_result, "time"));
coind_template.cpp:66:	strcpy(templ->nbits, json_get_string(json_result, "bits"));
coind_template.cpp:67:	strcpy(templ->prevhash_hex, json_get_string(json_result, "previousblockhash"));
coind_template.cpp-68-
coind_template.cpp-69-	json_value_free(json);
coind_template.cpp-70-
coind_template.cpp-71-	json = rpc_call(&coind->rpc, "getmininginfo", "[]");
coind_template.cpp-72-	if(!json || json->type == json_null)
coind_template.cpp-73-	{
coind_template.cpp-74-		coind_error(coind, "coind getmininginfo");
coind_template.cpp-75-		return NULL;
coind_template.cpp-76-	}
coind_template.cpp-77-
--

===================


coind_template.cpp-161-		return NULL;
coind_template.cpp-162-	}
coind_template.cpp-163-	json_value *gwr = json_get_object(gw, "result");
coind_template.cpp-164-	if(!gwr) {
coind_template.cpp-165-		debuglog("%s no getwork json result!\n", coind->symbol);
coind_template.cpp-166-		return NULL;
coind_template.cpp-167-	}
coind_template.cpp-168-	else if (json_is_null(gwr)) {
coind_template.cpp-169-		json_value *jr = json_get_object(gw, "error");
coind_template.cpp-170-		if (!jr || json_is_null(jr)) return NULL;
coind_template.cpp:171:		const char *err = json_get_string(jr, "message");
coind_template.cpp-172-		if (err && !strcmp(err, "internal error")) {
coind_template.cpp-173-			usleep(500*YAAMP_MS); // not enough voters (testnet)
coind_template.cpp-174-			if (--retry_cnt > 0) {
coind_template.cpp-175-				goto retry;
coind_template.cpp-176-			}
coind_template.cpp-177-			debuglog("%s getwork failed after %d tries: %s\n",
coind_template.cpp-178-				coind->symbol, GETWORK_RETRY_MAX, err);
coind_template.cpp-179-		}
coind_template.cpp-180-		return NULL;
coind_template.cpp-181-	}
coind_template.cpp:182:	const char *header_hex = json_get_string(gwr, "data");
coind_template.cpp-183-	if (!header_hex || !strlen(header_hex)) {
coind_template.cpp-184-		debuglog("%s no getwork data!\n", coind->symbol);
coind_template.cpp-185-		return NULL;
coind_template.cpp-186-	}
coind_template.cpp-187-
coind_template.cpp-188-	YAAMP_JOB_TEMPLATE *templ = new YAAMP_JOB_TEMPLATE;
coind_template.cpp-189-	memset(templ, 0, sizeof(YAAMP_JOB_TEMPLATE));
coind_template.cpp-190-
coind_template.cpp-191-	templ->created = time(NULL);
coind_template.cpp-192-
--
coind_template.cpp-206-	templ->txcount = txhashes.size();
coind_template.cpp-207-	templ->txsteps = merkle_steps(txhashes);
coind_template.cpp-208-	txhashes.clear();
coind_template.cpp-209-
coind_template.cpp-210-	return templ;
coind_template.cpp-211-}
coind_template.cpp-212-
coind_template.cpp-213-// for future decred real stratum
coind_template.cpp-214-static void decred_fix_template(YAAMP_COIND *coind, YAAMP_JOB_TEMPLATE *templ, json_value *json)
coind_template.cpp-215-{
coind_template.cpp:216:	const char *header_hex = json_get_string(json, "header");
coind_template.cpp-217-	if (!header_hex || !strlen(header_hex)) {
coind_template.cpp-218-		stratumlog("decred error, no block header in json!\n");
coind_template.cpp-219-		return;
coind_template.cpp-220-	}
coind_template.cpp-221-
coind_template.cpp-222-	// todo ?
coind_template.cpp-223-	//  "mintime": 1455511962,
coind_template.cpp-224-	//  "maxtime": 1455522081,
coind_template.cpp-225-
coind_template.cpp-226-	decred_parse_header(templ, header_hex, false);
--
coind_template.cpp-255-		json_value_free(json);
coind_template.cpp-256-		return NULL;
coind_template.cpp-257-	}
coind_template.cpp-258-
coind_template.cpp-259-	// segwit rule
coind_template.cpp-260-	json_value *json_rules = json_get_array(json_result, "rules");
coind_template.cpp-261-	if(json_rules && !strlen(coind->witness_magic) && json_rules->u.array.length) {
coind_template.cpp-262-		for (int i=0; i<json_rules->u.array.length; i++) {
coind_template.cpp-263-			json_value *val = json_rules->u.array.values[i];
coind_template.cpp-264-			if(!strcmp(val->u.string.ptr, "segwit")) {
coind_template.cpp:265:				const char *commitment = json_get_string(json_result, "default_witness_commitment");
coind_template.cpp-266-				strcpy(coind->witness_magic, "aa21a9ed");
coind_template.cpp-267-				if (commitment && strlen(commitment) > 12) {
coind_template.cpp-268-					strncpy(coind->witness_magic, &commitment[4], 8);
coind_template.cpp-269-					coind->witness_magic[8] = '\0';
coind_template.cpp-270-				}
coind_template.cpp-271-				coind->usesegwit |= g_stratum_segwit;
coind_template.cpp-272-				if (coind->usesegwit)
coind_template.cpp-273-					debuglog("%s segwit enabled, magic %s\n", coind->symbol, coind->witness_magic);
coind_template.cpp-274-				break;
coind_template.cpp-275-			}
--
coind_template.cpp-294-
coind_template.cpp-295-	YAAMP_JOB_TEMPLATE *templ = new YAAMP_JOB_TEMPLATE;
coind_template.cpp-296-	memset(templ, 0, sizeof(YAAMP_JOB_TEMPLATE));
coind_template.cpp-297-
coind_template.cpp-298-	templ->created = time(NULL);
coind_template.cpp-299-	templ->value = json_get_int(json_result, "coinbasevalue");
coind_template.cpp-300-	templ->height = json_get_int(json_result, "height");
coind_template.cpp-301-	sprintf(templ->version, "%08x", (unsigned int)json_get_int(json_result, "version"));
coind_template.cpp-302-	sprintf(templ->ntime, "%08x", (unsigned int)json_get_int(json_result, "curtime"));
coind_template.cpp-303-
coind_template.cpp:304:	const char *bits = json_get_string(json_result, "bits");
coind_template.cpp-305-	strcpy(templ->nbits, bits ? bits : "");
coind_template.cpp:306:	const char *prev = json_get_string(json_result, "previousblockhash");
coind_template.cpp-307-	strcpy(templ->prevhash_hex, prev ? prev : "");
coind_template.cpp:308:	const char *flags = json_get_string(json_coinbaseaux, "flags");
coind_template.cpp-309-	strcpy(templ->flags, flags ? flags : "");
coind_template.cpp-310-
coind_template.cpp-311-	if (strstr(coind->symbol, "LAX")) {
coind_template.cpp:312:		const char *accumulator = json_get_string(json_result, "accumulatorcheckpoint");
coind_template.cpp-313-		strcpy(templ->accumulatorcheckpoint_hex, accumulator ? accumulator : "");
coind_template.cpp-314-	}	
coind_template.cpp-315-
coind_template.cpp-316-	// LBC Claim Tree (with wallet gbt patch)
coind_template.cpp:317:	const char *claim = json_get_string(json_result, "claimtrie");
coind_template.cpp-318-	if (claim) {
coind_template.cpp-319-		strcpy(templ->claim_hex, claim);
coind_template.cpp-320-		// debuglog("claimtrie: %s\n", templ->claim_hex);
coind_template.cpp-321-	}
coind_template.cpp-322-	else if (strcmp(coind->symbol, "LBC") == 0) {
coind_template.cpp-323-		json_value *json_claim = rpc_call(&coind->rpc, "getclaimtrie");
coind_template.cpp-324-		if (!json_claim || json_claim->type != json_object)
coind_template.cpp-325-			return NULL;
coind_template.cpp-326-		json_value *json_cls = json_get_array(json_claim, "result");
coind_template.cpp-327-		if (!json_cls || !json_is_array(json_cls))
coind_template.cpp-328-			return NULL;
coind_template.cpp-329-		// get first claim "", seems the root
coind_template.cpp-330-		// if empty need 0000000000000000000000000000000000000000000000000000000000000001
coind_template.cpp-331-		json_value *json_obj = json_cls->u.array.values[0];
coind_template.cpp-332-		if (!json_obj || json_claim->type != json_object)
coind_template.cpp-333-			return NULL;
coind_template.cpp:334:		claim = json_get_string(json_obj, "hash");
coind_template.cpp-335-		if (claim) {
coind_template.cpp-336-			strcpy(templ->claim_hex, claim);
coind_template.cpp-337-			debuglog("claim_hex: %s\n", templ->claim_hex);
coind_template.cpp-338-		}
coind_template.cpp-339-	}
coind_template.cpp-340-
coind_template.cpp:341:	const char *sc_root = json_get_string(json_result, "stateroot");
coind_template.cpp:342:	const char *sc_utxo = json_get_string(json_result, "utxoroot");
coind_template.cpp-343-	if (sc_root && sc_utxo) {
coind_template.cpp-344-		// LUX Smart Contracts, 144-bytes block headers
coind_template.cpp-345-		strcpy(&templ->extradata_hex[ 0], sc_root); // 32-bytes hash (64 in hexa)
coind_template.cpp-346-		strcpy(&templ->extradata_hex[64], sc_utxo); // 32-bytes hash too
coind_template.cpp-347-
coind_template.cpp-348-		// same weird byte order as previousblockhash field
coind_template.cpp-349-		ser_string_be2(sc_root, &templ->extradata_be[ 0], 8);
coind_template.cpp-350-		ser_string_be2(sc_utxo, &templ->extradata_be[64], 8);
coind_template.cpp-351-	}
coind_template.cpp-352-
--
coind_template.cpp-363-	if (!strcmp(coind->symbol, "MBL")) { // MBL: chainid in version
coind_template.cpp-364-		unsigned int nVersion = (unsigned int)json_get_int(json_result, "version");
coind_template.cpp-365-		if (nVersion & 0xFFFF0000UL == 0) {
coind_template.cpp-366-			nVersion |= (0x16UL << 16);
coind_template.cpp-367-			debuglog("%s version %s >> %08x\n", coind->symbol, templ->version, nVersion);
coind_template.cpp-368-		}
coind_template.cpp-369-		sprintf(templ->version, "%08x", nVersion);
coind_template.cpp-370-	}
coind_template.cpp-371-
coind_template.cpp-372-//	debuglog("%s ntime %s\n", coind->symbol, templ->ntime);
coind_template.cpp:373://	uint64_t target = decode_compact(json_get_string(json_result, "bits"));
coind_template.cpp-374-//	coind->difficulty = target_to_diff(target);
coind_template.cpp-375-
coind_template.cpp-376-//	string_lower(templ->ntime);
coind_template.cpp-377-//	string_lower(templ->nbits);
coind_template.cpp-378-
coind_template.cpp-379-//	char target[1024];
coind_template.cpp:380://	strcpy(target, json_get_string(json_result, "target"));
coind_template.cpp-381-//	uint64_t coin_target = decode_compact(templ->nbits);
coind_template.cpp-382-//	debuglog("nbits %s\n", templ->nbits);
coind_template.cpp-383-//	debuglog("target %s\n", target);
coind_template.cpp-384-//	debuglog("0000%016llx\n", coin_target);
coind_template.cpp-385-
coind_template.cpp-386-	if(coind->isaux)
coind_template.cpp-387-	{
coind_template.cpp-388-		json_value_free(json);
coind_template.cpp-389-		coind_getauxblock(coind);
coind_template.cpp-390-		return templ;
--
coind_template.cpp-397-	txhashes.push_back("");
coind_template.cpp-398-	txids.push_back("");
coind_template.cpp-399-
coind_template.cpp-400-	templ->has_segwit_txs = false;
coind_template.cpp-401-
coind_template.cpp-402-	templ->has_filtered_txs = false;
coind_template.cpp-403-	templ->filtered_txs_fee = 0;
coind_template.cpp-404-
coind_template.cpp-405-	for(int i = 0; i < json_tx->u.array.length; i++)
coind_template.cpp-406-	{
coind_template.cpp:407:		const char *p = json_get_string(json_tx->u.array.values[i], "hash");
coind_template.cpp-408-		char hash_be[256] = { 0 };
coind_template.cpp-409-
coind_template.cpp-410-		if (templ->has_filtered_txs) {
coind_template.cpp-411-			templ->filtered_txs_fee += json_get_int(json_tx->u.array.values[i], "fee");
coind_template.cpp-412-			continue;
coind_template.cpp-413-		}
coind_template.cpp-414-
coind_template.cpp-415-		string_be(p, hash_be);
coind_template.cpp-416-		txhashes.push_back(hash_be);
coind_template.cpp-417-
coind_template.cpp:418:		const char *txid = json_get_string(json_tx->u.array.values[i], "txid");
coind_template.cpp-419-		if(txid && strlen(txid)) {
coind_template.cpp-420-			char txid_be[256] = { 0 };
coind_template.cpp-421-			string_be(txid, txid_be);
coind_template.cpp-422-			txids.push_back(txid_be);
coind_template.cpp-423-			if (strcmp(hash_be, txid_be)) {
coind_template.cpp-424-				templ->has_segwit_txs = true; // if not, its useless to generate a segwit block, bigger
coind_template.cpp-425-			}
coind_template.cpp-426-		} else {
coind_template.cpp-427-			templ->has_segwit_txs = false; // force disable if not supported (no txid fields)
coind_template.cpp-428-		}
coind_template.cpp-429-
coind_template.cpp:430:		const char *d = json_get_string(json_tx->u.array.values[i], "data");
coind_template.cpp-431-		templ->txdata.push_back(d);
coind_template.cpp-432-
coind_template.cpp-433-		// if wanted, we can limit the count of txs to include
coind_template.cpp-434-		if (g_limit_txs_per_block && i >= g_limit_txs_per_block-2) {
coind_template.cpp-435-			debuglog("limiting block to %d first txs (of %d)\n", g_limit_txs_per_block, json_tx->u.array.length);
coind_template.cpp-436-			templ->has_filtered_txs = true;
coind_template.cpp-437-		}
coind_template.cpp-438-	}
coind_template.cpp-439-
coind_template.cpp-440-	if (templ->has_filtered_txs) {
--
coind_template.cpp-466-		mt_verify.clear();
coind_template.cpp-467-		witness_mt = witness_mt + "0000000000000000000000000000000000000000000000000000000000000000";
coind_template.cpp-468-
coind_template.cpp-469-		binlify((unsigned char *)bin, witness_mt.c_str());
coind_template.cpp-470-		sha256_double_hash_hex(bin, witness, YAAMP_HASHLEN_BIN*2);
coind_template.cpp-471-
coind_template.cpp-472-		int clen = (int) (strlen(coind->witness_magic) + strlen(witness)); // 4 + 32 = 36 = 0x24
coind_template.cpp-473-		sprintf(coind->commitment, "6a%02x%s%s", clen/2, coind->witness_magic, witness);
coind_template.cpp-474-		*/
coind_template.cpp-475-		// default commitment is already computed correctly
coind_template.cpp:476:		const char *commitment = json_get_string(json_result, "default_witness_commitment");
coind_template.cpp-477-		if (commitment) {
coind_template.cpp-478-			sprintf(coind->commitment, "%s", commitment);
coind_template.cpp-479-		} else {
coind_template.cpp-480-			templ->has_segwit_txs = false;
coind_template.cpp-481-		}
coind_template.cpp-482-	}
coind_template.cpp-483-
coind_template.cpp-484-	txhashes.clear();
coind_template.cpp-485-	txids.clear();
coind_template.cpp-486-
--
grepout.c-109-coind.cpp:154:			strcpy(coind->script_pubkey, &pk[6]);
grepout.c-110-coind.cpp:173:	strcpy(account, coind->account);
grepout.c-111-coind.cpp:200:		strcpy(coind->wallet, json->u.object.values[0].value->u.string.ptr);
grepout.c-112-coind.cpp:203:		strcpy(coind->wallet, "");
grepout.c-113-
grepout.c-114-coind_submit.cpp:35:		memset(timestamp, 0, sizeof(timestamp));
grepout.c-115-
grepout.c-116-coind_template.cpp:26:	if(p) strcpy(coind->aux.target, p);
grepout.c-117-coind_template.cpp:29:	if(p) strcpy(coind->aux.hash, p);
grepout.c-118-coind_template.cpp:59:	memset(templ, 0, sizeof(YAAMP_JOB_TEMPLATE));
grepout.c:119:coind_template.cpp:66:	strcpy(templ->nbits, json_get_string(json_result, "bits"));
grepout.c:120:coind_template.cpp:67:	strcpy(templ->prevhash_hex, json_get_string(json_result, "previousblockhash"));
grepout.c-121-coind_template.cpp:139:	memcpy(templ->header, &header, sizeof(header));
grepout.c-122-coind_template.cpp:189:	memset(templ, 0, sizeof(YAAMP_JOB_TEMPLATE));
grepout.c-123-coind_template.cpp:237:	if(!strcmp(coind->symbol, "PPC")) strcpy(params, "[]");
grepout.c-124-coind_template.cpp:238:	else if(g_stratum_segwit) strcpy(params, "[{\"rules\":[\"segwit\"]}]");
grepout.c-125-coind_template.cpp:266:				strcpy(coind->witness_magic, "aa21a9ed");
grepout.c-126-coind_template.cpp:268:					strncpy(coind->witness_magic, &commitment[4], 8);
grepout.c-127-coind_template.cpp:296:	memset(templ, 0, sizeof(YAAMP_JOB_TEMPLATE));
grepout.c-128-coind_template.cpp:305:	strcpy(templ->nbits, bits ? bits : "");
grepout.c-129-coind_template.cpp:307:	strcpy(templ->prevhash_hex, prev ? prev : "");
grepout.c-130-coind_template.cpp:309:	strcpy(templ->flags, flags ? flags : "");
grepout.c-131-coind_template.cpp:313:		strcpy(templ->accumulatorcheckpoint_hex, accumulator ? accumulator : "");
grepout.c-132-coind_template.cpp:319:		strcpy(templ->claim_hex, claim);
grepout.c-133-coind_template.cpp:336:			strcpy(templ->claim_hex, claim);
grepout.c-134-coind_template.cpp:345:		strcpy(&templ->extradata_hex[ 0], sc_root); // 32-bytes hash (64 in hexa)
grepout.c-135-coind_template.cpp:346:		strcpy(&templ->extradata_hex[64], sc_utxo); // 32-bytes hash too
grepout.c:136:coind_template.cpp:380://	strcpy(target, json_get_string(json_result, "target"));
grepout.c-137-coind_template.cpp:592:	memset(coind->job, 0, sizeof(YAAMP_JOB));
grepout.c-138-
grepout.c-139-db.cpp:68:	if (strstr(string, "script")) strcpy(string, "");
grepout.c-140-db.cpp:211:			memset(coind, 0, sizeof(YAAMP_COIND));
grepout.c-141-db.cpp:221:		strcpy(coind->name, row[1]);
grepout.c-142-db.cpp:222:		strcpy(coind->symbol, row[20]);
grepout.c-143-db.cpp:234:		if(row[7]) strcpy(coind->wallet, row[7]);
grepout.c-144-db.cpp:235:		if(row[6]) strcpy(coind->rpcencoding, row[6]);
grepout.c-145-db.cpp:244:			strcpy(buffer, row[2]);
grepout.c-146-db.cpp:247:				strcpy(buffer, row[2] + 8);
--
remote.cpp-165-			continue;
remote.cpp-166-		}
remote.cpp-167-
remote.cpp-168-		if(remote->status == YAAMP_REMOTE_TERMINATE)
remote.cpp-169-		{
remote.cpp-170-			json_value_free(json);
remote.cpp-171-			break;
remote.cpp-172-		}
remote.cpp-173-
remote.cpp-174-		int id = json_get_int(json, "id");
remote.cpp:175:		const char *method = json_get_string(json, "method");
remote.cpp-176-
remote.cpp-177-		json_value *json_params = json_get_array(json, "params");
remote.cpp-178-		json_value *json_result = json_get_array(json, "result");
remote.cpp-179-
remote.cpp-180-		if(id == 1)
remote.cpp-181-		{
remote.cpp-182-			remote->status = YAAMP_REMOTE_AUTHORIZE;
remote.cpp-183-
remote.cpp-184-			strncpy(remote->nonce1_next, json_result->u.array.values[1]->u.string.ptr, 16);
remote.cpp-185-			remote->nonce2size_next = json_result->u.array.values[2]->u.integer;
--
share.cpp-268-			json_value *json = rpc_call(&coind->rpc, "getblock", params);
share.cpp-269-			if(!json) {
share.cpp-270-				debuglog("%s: error getblock, no answer\n", __func__);
share.cpp-271-				break;
share.cpp-272-			}
share.cpp-273-			json_value *json_res = json_get_object(json, "result");
share.cpp-274-			if(!json_res) {
share.cpp-275-				debuglog("%s: error getblock, no result\n", __func__);
share.cpp-276-				break;
share.cpp-277-			}
share.cpp:278:			const char *h1 = json_get_string(json_res, "pow_hash"); // DGB, MYR, J
share.cpp:279:			const char *h2 = json_get_string(json_res, "mined_hash"); // XVG
share.cpp:280:			const char *h3 = json_get_string(json_res, "phash"); // XSH
share.cpp-281-			if (h1) snprintf(hash, 161, "%s", h1);
share.cpp-282-			else if (h2) snprintf(hash, 161, "%s", h2);
share.cpp-283-			else if (h3) snprintf(hash, 161, "%s", h3);
share.cpp-284-			//debuglog("%s: getblock %s -> pow %s\n", __func__, blockhash, hash);
share.cpp-285-			json_value_free(json);
share.cpp-286-			break;
share.cpp-287-		} else if (strcmp(coind->symbol,"ORB") == 0) {
share.cpp-288-			char params[192];
share.cpp-289-			sprintf(params, "[\"%s\"]", blockhash);
share.cpp-290-			json_value *json = rpc_call(&coind->rpc, "getblock", params);
share.cpp-291-			if(!json) {
share.cpp-292-				debuglog("%s: error getblock, no answer\n", __func__);
share.cpp-293-				break;
share.cpp-294-			}
share.cpp-295-			json_value *json_res = json_get_object(json, "result");
share.cpp-296-			if(!json_res) {
share.cpp-297-				debuglog("%s: error getblock, no result\n", __func__);
share.cpp-298-				break;
share.cpp-299-			}
share.cpp:300:			const char *h = json_get_string(json_res, "proofhash");
share.cpp-301-			if (h) snprintf(hash, 161, "%s", h);
share.cpp-302-			json_value_free(json);
share.cpp-303-			break;
share.cpp-304-		}
share.cpp-305-	}
share.cpp-306-	g_list_coind.Leave();
share.cpp-307-
share.cpp-308-	for(CLI li = g_list_block.first; li; li = li->next)
share.cpp-309-	{
share.cpp-310-		YAAMP_BLOCK *block = (YAAMP_BLOCK *)li->data;
--
#util.cpp#-31-{
#util.cpp#-32-	for(int i=0; i<json->u.object.length; i++)
#util.cpp#-33-	{
#util.cpp#-34-		if(!strcmp(json->u.object.values[i].name, name))
#util.cpp#-35-			return json->u.object.values[i].value->u.dbl;
#util.cpp#-36-	}
#util.cpp#-37-
#util.cpp#-38-	return 0;
#util.cpp#-39-}
#util.cpp#-40-
#util.cpp#:41:const char *json_get_string(json_value *json, const char *name)
#util.cpp#-42-{
#util.cpp#-43-	for(int i=0; i<json->u.object.length; i++)
#util.cpp#-44-	{
#util.cpp#-45-		if(!strcmp(json->u.object.values[i].name, name))
#util.cpp#-46-			return json->u.object.values[i].value->u.string.ptr;
#util.cpp#-47-	}
#util.cpp#-48-
#util.cpp#-49-	return NULL;
#util.cpp#-50-}
#util.cpp#-51-
--
util.cpp-31-{
util.cpp-32-	for(int i=0; i<json->u.object.length; i++)
util.cpp-33-	{
util.cpp-34-		if(!strcmp(json->u.object.values[i].name, name))
util.cpp-35-			return json->u.object.values[i].value->u.dbl;
util.cpp-36-	}
util.cpp-37-
util.cpp-38-	return 0;
util.cpp-39-}
util.cpp-40-
util.cpp:41:const char *json_get_string(json_value *json, const char *name)
util.cpp-42-{
util.cpp-43-	for(int i=0; i<json->u.object.length; i++)
util.cpp-44-	{
util.cpp-45-		if(!strcmp(json->u.object.values[i].name, name))
util.cpp-46-			return json->u.object.values[i].value->u.string.ptr;
util.cpp-47-	}
util.cpp-48-
util.cpp-49-	return NULL;
util.cpp-50-}
util.cpp-51-
--
util.h-41-};
util.h-42-
util.h-43-void CommonLock(pthread_mutex_t *mutex);
util.h-44-void CommonUnlock(pthread_mutex_t *mutex);
util.h-45-
util.h-46-//////////////////////////////////////////////////////////////////////////
util.h-47-
util.h-48-bool json_get_bool(json_value *json, const char *name);
util.h-49-json_int_t json_get_int(json_value *json, const char *name);
util.h-50-double json_get_double(json_value *json, const char *name);
util.h:51:const char *json_get_string(json_value *json, const char *name);
util.h-52-json_value *json_get_array(json_value *json, const char *name);
util.h-53-json_value *json_get_object(json_value *json, const char *name);
util.h-54-
util.h-55-void yaamp_create_mutex(pthread_mutex_t *mutex);
util.h-56-bool yaamp_error(char const *message);
util.h-57-
util.h-58-const char *header_value(const char *data, const char *search, char *value);
util.h-59-
util.h-60-void initlog(const char *algo);
util.h-61-void closelogs();
