#ifndef SPADE_SEQUENCEDATABASE_H
#define SPADE_SEQUENCEDATABASE_H

#include <string>
#include <vector>
#include "EquivalenceClass.h"

class SequenceDatabase {

    std::map<Item*, EquivalenceClass*> *frequentItems = new std::map<Item*, EquivalenceClass*>;
    std::vector<std::map<long, std::vector<Item*>*>*> *sequences = new std::vector<std::map<long, std::vector<Item*>*>*>;

public:
    void loadFile(std::string path, double minSupport);

    void addSequence(long timestamp, std::vector<std::vector<int>*>* integers);

    std::vector<EquivalenceClass*>* getFrequentItems() {
        auto* items = new std::vector<EquivalenceClass*>;
        for (auto &frequentItem : *frequentItems) {
            items->push_back(frequentItem.second);
        }
        return items;
    }

    void reduceDatabase(std::vector<Item*> *items);
};


#endif //SPADE_SEQUENCEDATABASE_H
