#ifndef MAIN_STRUCT_H
#define MAIN_STRUCT_H

struct COrphanBlock {
    uint256 hashBlock;
    uint256 hashPrev;
    std::pair<COutPoint, unsigned int> stake;
    vector<unsigned char> vchBlock;
};

#endif // MAIN_STRUCT_H