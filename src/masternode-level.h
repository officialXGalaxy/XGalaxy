/*
 * Copyright (c) 2018 The Phase Core developers
 * Distributed under the MIT software license, see the accompanying
 * file COPYING or http://www.opensource.org/licenses/mit-license.php.
 * masternode-level.h
 *
 *  Created on: Jun 19, 2018
 *      Author: Tri Nguyen-Pham
 */

#ifndef SRC_MASTERNODE_LEVEL_H_
#define SRC_MASTERNODE_LEVEL_H_

#include "amount.h"
#include <vector>
#include <string>

using namespace std;
enum Level {
	LEVEL1,
	LEVEL2,
	LEVEL3,
	NULL_LEVEL
};

static const vector<string> MN_LEVEL_STRS = {
		"1",
		"2",
		"3",
		"N/A"
};

class MasternodeLevel {
public:
	MasternodeLevel(Level level, CAmount levelCollateral, int stopHeight = -1) {
		this->level = level;
		this->levelCollateral = levelCollateral;
		this->stopHeight = stopHeight;
	}
	Level getLevel(){
		return this->level;
	}
	CAmount getCollateral() {
		return this->levelCollateral;
	}
	int getStopHeight() {
		return this->stopHeight;
	}
private:
	Level level;
	CAmount levelCollateral;
	int stopHeight;
};
static const vector<MasternodeLevel> COLLATERALS = {
		MasternodeLevel(LEVEL1, 1000*COIN, 200000),
		MasternodeLevel(LEVEL2, 3000*COIN, 204400),
//		MasternodeLevel(LEVEL3, 5000*COIN, 400000),
//		MasternodeLevel(LEVEL4, 10000*COIN, 500000),
		MasternodeLevel(LEVEL3, 20000*COIN)
};

extern bool isValidMasternode(CAmount value, int height);
extern Level getMasternodeLevel(CAmount value, int height);
extern CAmount getMinimumCollateral(int height);
extern int getMnRewardMultiplier(Level level, const int nHeight);


#endif /* SRC_MASTERNODE_LEVEL_H_ */
