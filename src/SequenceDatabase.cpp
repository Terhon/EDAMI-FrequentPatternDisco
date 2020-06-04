#include "SequenceDatabase.h"
#include <algorithm>
#include <sstream>
#include <fstream>


void SequenceDatabase::loadFile(std::string path, double minSupport) {
    std::ifstream file(path);
    std::string line;
    //fileline structure: timestamp item1 item2 , item1 item3
    //example: 10 1 2 , 1 3
    auto data = new std::vector<std::vector<int> *>;
    while(std::getline(file, line)) {
        //TODO
        std::istringstream tokenizer(line);
        long timestamp;
        do {
            std::string subline;
            std::getline(tokenizer, subline, ',');
        } while (false);
        //
        addSequence(timestamp, data);
    }
    double support = minSupport * sequences->size();

    auto *itemsToRemove = new std::vector<Item*>;
    for(auto& pair : *frequentItems) {
        if(pair.second->getIdList()->getSupport() < support) {
            itemsToRemove->push_back(pair.first);
        } else {
            pair.second->getIdList()->setAppearingSequences(pair.second->getClassIdentifier());
        }
    }
    for(auto &item : *itemsToRemove) {
        frequentItems->erase(item);
    }

}

void SequenceDatabase::addSequence(long timestamp, std::vector<std::vector<int> *> *integers) {
    auto *sequence = new std::map<long, std::vector<Item *> *>;

    for (auto &integer : *integers) {
        auto *itemset = new std::vector<Item *>;
        for (auto &id : *integer) {
            auto existing = std::find_if(frequentItems->begin(), frequentItems->end(), [id](std::pair<Item* const, EquivalenceClass*> pair) {
                return pair.first->getId() == id;
            });
            EquivalenceClass *ec = *existing == *(frequentItems->end()) ? nullptr : existing->second;
            IdList *idList = nullptr;
            if (ec == nullptr) {
                idList = new IdList();
                auto *item = new Item(id, false);
                ec = new EquivalenceClass(new Pattern(new std::vector<Item*>({item})), idList);
                frequentItems->insert({item, ec});
            }
            //idList = ec->getIdList();
            auto *item = new Item(id, true);
            itemset->push_back(item);
        }
        sequence->insert({timestamp, itemset});
        timestamp++;
    }
    sequences->push_back(sequence);
}

void SequenceDatabase::reduceDatabase(std::vector<Item *> *items) {

    for(auto &s : *sequences) {
        auto itemset = s->begin();
        while(itemset != s->end()) {
            auto item = (*itemset).second->begin();
            while(item != (*itemset).second->end()) {
                if(std::find(items->begin(),items->end(),*item) == items->end()) {
                    (*itemset).second->erase(item);
                } else {
                    item++;
                }
            }
        }
        if((*itemset).second->empty()) {
            s->erase(itemset);
        } else {
            itemset++;
        }
    }
}
