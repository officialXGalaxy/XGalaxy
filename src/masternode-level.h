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
	LEVEL4,
	LEVEL5,
	NULL_LEVEL
};

static const vector<string> MN_LEVEL_STRS = {
		"1",
		"2",
		"3",
		"4",
		"5",
		"N/A"
};

class MasternodeLevel {
public:
	MasternodeLevel(Level level, CAmount levelCollateral) {
		this->level = level;
		this->levelCollateral = levelCollateral;
	}
	Level getLevel(){
		return this->level;
	}
	CAmount getCollateral() {
		return this->levelCollateral;
	}
private:
	Level level;
	CAmount levelCollateral;
};
static const vector<MasternodeLevel> COLLATERALS = {
		MasternodeLevel(LEVEL1, 1000*COIN),
		MasternodeLevel(LEVEL2, 3000*COIN),
		MasternodeLevel(LEVEL3, 5000*COIN),
		MasternodeLevel(LEVEL4, 10000*COIN),
		MasternodeLevel(LEVEL5, 20000*COIN)
};

extern bool isValidMasternode(CAmount value);
extern Level getMasternodeLevel(CAmount value);
extern CAmount getMinimumCollateral();


#endif /* SRC_MASTERNODE_LEVEL_H_ */
