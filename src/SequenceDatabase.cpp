#include "SequenceDatabase.h"
#include <algorithm>

void SequenceDatabase::loadFile(std::string path, double minSupport) {

}

void SequenceDatabase::addSequence(long timestamp, std::vector<std::vector<int> *> *integers) {
    auto *sequence = new std::map<long, std::vector<Item *> *>;

    for (auto &integer : *integers) {
        auto *itemset = new std::vector<Item *>;
        for (auto &id : *integer) {
            EquivalenceClass *ec = (*std::find_if(frequentItems->begin(), frequentItems->end(), [id](std::pair<Item* const, EquivalenceClass*> pair) {
                return pair.first->getId() == id;
            })).second;
            IdList *idList = nullptr;
            if (ec == nullptr) {
                idList = new IdList();
                auto *item = new Item(id, false);
                ec = new EquivalenceClass(new Pattern(new std::vector<Item*>({item})), idList);
                frequentItems->insert({item, ec});
            }
            idList = ec->getIdList();
            auto *item = new Item(id, true);
            itemset->push_back(item);
        }
        sequence->insert({timestamp, itemset});
        timestamp++;
    }
    sequences->push_back(sequence);
}
