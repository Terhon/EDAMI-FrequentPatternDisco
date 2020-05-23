#ifndef SPADE_SPADE_HPP
#define SPADE_SPADE_HPP

#include <vector>
#include "EquivalenceClass.h"
#include "Pattern.h"

class Spade {
    std::vector<EquivalenceClass *> *frequentItems;

    std::vector<Pattern *> *getPatterns(std::vector<EquivalenceClass *> *frequentItems);

    int frequentPatternCount;

    int joinCount;

public:
    int run(int arg);

};


#endif //SPADE_SPADE_HPP
