#ifndef SPADE_SEQUENCEDATABASE_H
#define SPADE_SEQUENCEDATABASE_H

#include <vector>
#include "EquivalenceClass.h"

class SequenceDatabase {

public:
    std::vector<EquivalenceClass*>* getFrequentItems();
};


#endif //SPADE_SEQUENCEDATABASE_H
