/*
 * Copyright (c) 2018 The Tank Core developers
 * Distributed under the MIT software license, see the accompanying
 * file COPYING or http://www.opensource.org/licenses/mit-license.php.
 * 
 * DonationPayment.h
 *
 *  Created on: Jun 24, 2018
 *      Author: Tri Nguyen
 */

#ifndef SRC_DONATIONPAYMENT_H_
#define SRC_DONATIONPAYMENT_H_
#include <string>
#include "amount.h"
#include "primitives/transaction.h"
#include "base58.h"
using namespace std;

static const char* DEFAULT_DONATION_ADDRESS = "ThczW323Y5QN44r5a94NQopSu5S1NnGvR4";

class DonationPayment {
public:
	DonationPayment(const char* address = DEFAULT_DONATION_ADDRESS) {
		donationAddress.SetString(address);
	}
	~DonationPayment(){};
	CAmount getDonationPaymentAmount(int blockHeight, CAmount blockReward);
	void FillDonationPayment(CMutableTransaction& txNew, int nBlockHeight, CAmount blockReward, CTxOut& txoutDonationRet);
	bool IsBlockPayeeValid(const CTransaction& txNew, const int height, const CAmount blockReward);
private:
	CBitcoinAddress donationAddress;
};



#endif /* SRC_DONATIONPAYMENT_H_ */
