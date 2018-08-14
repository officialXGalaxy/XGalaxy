/*
 * Copyright (c) 2018 The XGalaxy Core developers
 * Distributed under the MIT software license, see the accompanying
 * file COPYING or http://www.opensource.org/licenses/mit-license.php.
 * 
 * FounderPayment.cpp
 *
 *  Created on: Jun 24, 2018
 *      Author: Tri Nguyen
 */

#include "FounderPayment.h"
//#include "standard.h";
#include "util.h"
#include "chainparams.h"
#include <boost/foreach.hpp>

CAmount FounderPayment::getFounderPaymentAmount(int blockHeight, CAmount blockReward) {
	 if (blockHeight <= 1){
		 return 0;
	 }
	 return blockReward * 0.05;
}

void FounderPayment::FillFounderPayment(CMutableTransaction& txNew, int nBlockHeight, CAmount blockReward, CTxOut& txoutFounderRet) {
    // make sure it's not filled yet
	txoutFounderRet = CTxOut();

    CScript payee;
    // fill payee with the founder address
    payee = GetScriptForDestination(founderAddress.Get());

    // GET FOUNDER PAYMENT VARIABLES SETUP
    CAmount founderPayment = getFounderPaymentAmount(nBlockHeight, blockReward);
    // split reward between miner ...
    txNew.vout[0].nValue -= founderPayment;
    txoutFounderRet = CTxOut(founderPayment, payee);
    txNew.vout.push_back(txoutFounderRet);
    LogPrintf("CMasternodePayments::FillFounderPayment -- Founder payment %lld to %s\n", founderPayment, founderAddress.ToString());
}

bool FounderPayment::IsBlockPayeeValid(const CTransaction& txNew, const int height, const CAmount blockReward) {
	CScript payee;
	// fill payee with the founder address
	payee = GetScriptForDestination(founderAddress.Get());
	const CAmount founderReward = getFounderPaymentAmount(height, blockReward);
	BOOST_FOREACH(const CTxOut& out, txNew.vout) {
		if(out.scriptPubKey == payee && out.nValue >= founderReward) {
			return true;
		}
	}

	return false;
}



