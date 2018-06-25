/*
 * Copyright (c) 2018 The Tank Core developers
 * Distributed under the MIT software license, see the accompanying
 * file COPYING or http://www.opensource.org/licenses/mit-license.php.
 * 
 * DonationPayment.cpp
 *
 *  Created on: Jun 24, 2018
 *      Author: Tri Nguyen
 */

#include "DonationPayment.h"
//#include "standard.h";
#include "util.h"
CAmount DonationPayment::getDonationPaymentAmount(int blockHeight, CAmount blockReward) {
	 if (blockHeight < 1160){
		 return 0;
	 }
	 return blockReward * 0.01;
}

void DonationPayment::FillDonationPayment(CMutableTransaction& txNew, int nBlockHeight, CAmount blockReward) {
    // make sure it's not filled yet
	//CTxOut txoutDonationRet();

    CScript payee;
    // fill payee with the donation address
    payee = GetScriptForDestination(donationAddress.Get());

    // GET DONATION PAYMENT VARIABLES SETUP
    CAmount donationPayment = getDonationPaymentAmount(nBlockHeight, blockReward);
    // split reward between miner ...
    txNew.vout[0].nValue -= donationPayment;
    // ... and masternode
    CTxOut txoutDonationRet(donationPayment, payee);
    txNew.vout.push_back(txoutDonationRet);
    LogPrintf("CMasternodePayments::FillDonationPayment -- Donation payment %lld to %s\n", donationPayment, donationAddress.ToString());
}



