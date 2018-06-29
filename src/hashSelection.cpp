/*
 * hashSelection.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: tri
 */

#include "hashSelection.h"
#include <vector>


static vector<string> ALGOS_HASHES = {
		"Blake",
		"Bmw",
		"Groestl",
		"Jh",
		"Keccak",
		"Skein",
		"Luffa",
		"Cube",
		"Shavite",
		"Simd",
		"Echo",
		"Hamsi",
		"Fugue",
		"Shabal",
		"Whirl",
		"Sha",
		"Haval"
};
uint256 scrambleHash(uint256 blockHash) {
	// Cliffnotes: use last 34 of PrevBlockHash to shuffle
	// a list of all algos and append that to PrevBlockHash and pass to hasher
	//////

	string hashString = blockHash.GetHex(); // uint256 to string
	string list = "0123456789abcdef";
	string order = list;
	string order2 = list;

	string hashFront = hashString.substr(0,30); // preserve first 30 chars
	string sixteen2 = hashString.substr(30,46); // extract last 34 chars
	string sixteen = hashString.substr(46,62); // extract last 34 chars
	string last2 = hashString.substr(62,64); // extract last 34 chars
	for(int i=0; i<16; i++){
	  int offset = list.find(sixteen[i]); // find offset of 16 char

	  order.insert(0, 1, order[offset]); // insert the nth character at the beginning
	  order.erase(offset+1, 1);  // erase the n+1 character (was nth)
	}

	for(int j=0; j<16; j++){
	  int offset = list.find(sixteen2[j]); // find offset of 16 char

	  order2.insert(0, 1, order[offset]); // insert the nth character at the beginning
	  order2.erase(offset+1, 1);  // erase the n+1 character (was nth)
	}
	int offset = list.find(last2[0]); // find offset of 16 char
	order2.insert(0, 1, order[offset]);
	offset = list.find(last2[1]); // find offset of 16 char
	order2.insert(0, 1, order[offset]);
	uint256 scrambleHash = uint256S(hashFront + order2 + order); // uint256 with length of hash and shuffled last seventeen
	return scrambleHash;
}

bool isScrambleHash(uint256 blockHash) {
	#define START_OF_LAST_35_NIBBLES_OF_HASH 29
	int last35Nibble = blockHash.GetNibble(START_OF_LAST_35_NIBBLES_OF_HASH);
	return (last35Nibble % 2 == 0);
}

int GetSelection(uint256 blockHash, int index) {
	assert(index >= 0);
	assert(index < 17);

	#define START_OF_LAST_17_NIBBLES_OF_HASH 47
	int hashSelection = blockHash.GetNibble(START_OF_LAST_17_NIBBLES_OF_HASH + index);
	#define START_OF_LAST_34_NIBBLES_OF_HASH 30
	int additionalSelection = blockHash.GetNibble(START_OF_LAST_34_NIBBLES_OF_HASH + index);
	hashSelection += (additionalSelection % 2);
	return(hashSelection);
}

 string getHashSelectionsString(uint256 hash){
	uint256 blockHash;
	if(isScrambleHash(hash)) {
		blockHash = scrambleHash(hash);
	} else {
		blockHash = hash;
	}
	string hashSelections = "";
	for(int i = 0; i < 17; i++) {
		int hashSelected = GetSelection(blockHash, i);
		hashSelections += ALGOS_HASHES[hashSelected];
	}
	return hashSelections;
}


