#ifndef SPADE_SPADE_HPP
#define SPADE_SPADE_HPP

#include <vector>
#include "EquivalenceClass.h"
#include "Pattern.h"

class Spade {

public:
    int run(int arg);

private:
    std::vector<EquivalenceClass*> *frequentItems;
    std::vector<Pattern*> *getPatterns(std::vector<EquivalenceClass*> *frequentItems);
};


#endif //SPADE_SPADE_HPP
