#ifndef GLOBAL_H
#define GLOBAL_H

#include <set>
#include <map>

#include "sync.h"
#include "chain.h"
#include "script.h"
#include "main.h"

/**
	Used structs and classes
*/
struct COrphanBlock;
class CScript;
class CTxMemPool;
class uint256;
class CBlockIndex;
//class COutPoint;

/**
	Extern Global variables:
		These are global variables that are accessible from everywhere.
*/
extern CScript COINBASE_FLAGS;
extern CCriticalSection cs_main;
extern CTxMemPool mempool;
extern std::map<uint256, CBlockIndex*> mapBlockIndex;
extern std::set<std::pair<COutPoint, unsigned int> > setStakeSeen;
extern CBlockIndex* pindexGenesisBlock;
extern unsigned int nNodeLifespan;
extern int nBestHeight;
extern uint256 nBestChainTrust;
extern uint256 nBestInvalidTrust;
extern uint256 hashBestChain;
extern CBlockIndex* pindexBest;
extern uint64_t nLastBlockTx;
extern uint64_t nLastBlockSize;
extern int64_t nLastCoinStakeSearchInterval;
extern const std::string strMessageMagic;
extern int64_t nTimeBestReceived;
extern bool fImporting;
extern bool fReindex;
extern std::map<uint256, COrphanBlock*> mapOrphanBlocks;
extern bool fHaveGUI;

// Settings
extern bool fUseFastIndex;
extern unsigned int nDerivationMethodIndex;
extern bool fLargeWorkForkFound;
extern bool fLargeWorkInvalidChainFound;

#endif // GLOBAL_H