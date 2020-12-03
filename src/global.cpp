/**
	Extern Global variables:
		Global variables needs to be allocated in the project inside a cpp file.
		This way the addresses are defined in the project where the global.h header is referencing to.
*/
#include "script.h"
#include "txmempool.h"

#include "global.h"

/** Constant stuff for coinbase transactions we create: */
CScript COINBASE_FLAGS;
CCriticalSection cs_main;
CTxMemPool mempool;
std::map<uint256, CBlockIndex*> mapBlockIndex;
std::set<std::pair<COutPoint, unsigned int> > setStakeSeen;
CBlockIndex* pindexGenesisBlock = NULL;
unsigned int nNodeLifespan;
int nBestHeight = -1;
uint256 nBestChainTrust = 0;
uint256 nBestInvalidTrust = 0;
uint256 hashBestChain = 0;
CBlockIndex* pindexBest = NULL;
uint64_t nLastBlockTx;
uint64_t nLastBlockSize;
int64_t nLastCoinStakeSearchInterval;
const std::string strMessageMagic = "DigitalNote Signed Message:\n";
int64_t nTimeBestReceived = 0;
bool fImporting = false;
bool fReindex = false;
std::map<uint256, COrphanBlock*> mapOrphanBlocks;
bool fHaveGUI = false;

bool fUseFastIndex;
unsigned int nDerivationMethodIndex;



