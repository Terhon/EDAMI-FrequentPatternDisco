#ifndef SPADE_SPADE_HPP
#define SPADE_SPADE_HPP

#include <iostream>
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

    void printResults() {
        std::cout << "frequentPatternCount:" << frequentPatternCount << std::endl;
        std::cout << "joinCount:" << joinCount << std::endl;
        for(auto &item : *frequentItems) {
            for(auto &el : *item->getClassIdentifier()->getElements()) {
                std::cout << el->getId() << ", ";
            }
            std::cout << std::endl;
        }
    }
};


#endif //SPADE_SPADE_HPP
