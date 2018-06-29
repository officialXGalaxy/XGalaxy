/*
 * hashSelection.h
 *
 *  Created on: Jun 15, 2018
 *      Author: tri
 */

#ifndef SRC_HASHSELECTION_H_
#define SRC_HASHSELECTION_H_

#include "uint256.h"
#include <string>
using namespace std;

extern int GetSelection(uint256 blockHash, int index);
extern bool isScrambleHash(uint256 blockHash);
extern uint256 scrambleHash(uint256 blockHash);
extern string getHashSelectionsString(uint256 hash);



#endif /* SRC_HASHSELECTION_H_ */
