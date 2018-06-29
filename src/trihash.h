/*
* Copyright (c) 2018 The Tank Core developers
* Distributed under the MIT software license, see the accompanying
* file COPYING or http://www.opensource.org/licenses/mit-license.php.
 * trihash.h
 *
 *  Created on: Jun 12, 2018
 *      Author: Tri Nguyen-Pham
 */

#ifndef SRC_TRIHASH_H_
#define SRC_TRIHASH_H_

#include <iostream>
#include <chrono>

#include "uint256.h"
#include "hashSelection.h"

#include "crypto/sph_blake.h"
#include "crypto/sph_bmw.h"
#include "crypto/sph_groestl.h"
#include "crypto/sph_jh.h"
#include "crypto/sph_keccak.h"
#include "crypto/sph_skein.h"
#include "crypto/sph_luffa.h"
#include "crypto/sph_cubehash.h"
#include "crypto/sph_shavite.h"
#include "crypto/sph_simd.h"
#include "crypto/sph_echo.h"
#include "crypto/sph_hamsi.h"
#include "crypto/sph_fugue.h"
#include "crypto/sph_shabal.h"
#include "crypto/sph_whirlpool.h"
#include "crypto/sph_haval.h"

extern "C" {
#include "crypto/sph_sha2.h"
}
#include <vector>

using namespace std;

//extern static vector<string> ALGOS_HASHES;

class TriHash {
private:
	sph_blake512_context     ctx_blake;      //0
	sph_bmw512_context       ctx_bmw;        //1
	sph_groestl512_context   ctx_groestl;    //2
	sph_jh512_context        ctx_jh;         //3
	sph_keccak512_context    ctx_keccak;     //4
	sph_skein512_context     ctx_skein;      //5
	sph_luffa512_context     ctx_luffa;      //6
	sph_cubehash512_context  ctx_cubehash;   //7
	sph_shavite512_context   ctx_shavite;    //8
	sph_simd512_context      ctx_simd;       //9
	sph_echo512_context      ctx_echo;       //A
	sph_hamsi512_context     ctx_hamsi;      //B
	sph_fugue512_context     ctx_fugue;      //C
	sph_shabal512_context    ctx_shabal;     //D
	sph_whirlpool_context    ctx_whirlpool;  //E
	sph_sha512_context       ctx_sha512;     //F
	sph_haval256_5_context   ctx_haval;
	uint256 PrevBlockHash;
public:
	TriHash(uint256 blockHash) {
		this->PrevBlockHash = blockHash;
	};
	~TriHash() {};
	uint256 hash(const char* pbegin, const char* pend);
	int GetHashSelection(uint256 blockHash, int index);
	bool isScramble();
	uint256 scramble();
};



#endif /* SRC_TRIHASH_H_ */
