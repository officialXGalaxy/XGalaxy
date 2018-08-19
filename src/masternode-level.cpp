/*
 * Copyright (c) 2018 The Phase Core developers
 * Distributed under the MIT software license, see the accompanying
 * file COPYING or http://www.opensource.org/licenses/mit-license.php.
 * masternode-level.h
 *
 *  Created on: Jun 19, 2018
 *      Author: Tri Nguyen-Pham
 */

#include "masternode-level.h"

bool isValidMasternode(CAmount value) {
	int totalLevel = COLLATERALS.size();
	for(int i = 0; i < totalLevel; i++) {
		MasternodeLevel level = COLLATERALS[i];
		if(level.getCollateral() == value) {
			return true;
		}
	}
	return false;

}
Level getMasternodeLevel(CAmount value) {
	int totalLevel = COLLATERALS.size();
	for(int i = 0; i < totalLevel; i++) {
		MasternodeLevel level = COLLATERALS[i];
		if(level.getCollateral() == value) {
			return level.getLevel();
		}
	}
	return NULL_LEVEL;
}

CAmount getMinimumCollateral(){
	MasternodeLevel level = COLLATERALS[0];
	return level.getCollateral();

}

int getMnRewardMultiplier(Level level, const int height) {
	if(level == NULL_LEVEL || level >= COLLATERALS.size()) {
		return 0;
	}
	MasternodeLevel mnLevel = COLLATERALS[level];
	if(mnLevel.getStopHeight() < 0) {
		return 1;
	}
	if(height <= mnLevel.getStopHeight()) {
		return 1;
	}
	return 0;
}
