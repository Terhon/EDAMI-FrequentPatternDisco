#include "Spade.h"
#include "EquivalenceClass.h"
#include "FrequentPatternEnumeration.h"
#include "SequenceDatabase.h"

int Spade::run(int arg) {
    auto *db = new SequenceDatabase();
    db->addSequence(10, new std::vector<std::vector<int>*>({new std::vector<int>({2,2,2,4}), new std::vector<int>({1,2,2,4})}));
    db->addSequence(20, new std::vector<std::vector<int>*>({new std::vector<int>({3,4,4})}));

    auto *cg = new CandidateGenerator();
    auto sup = 5;

    frequentItems = db->getFrequentItems();
    auto *patterns = getPatterns(frequentItems);
    auto *rootClass = new EquivalenceClass();

    for(auto frequentItem : *frequentItems) {
        rootClass->addMember(frequentItem);
    }

    auto frequentPatternEnumeration = new FrequentPatternEnumeration(cg,sup);
    frequentPatternEnumeration->setFrequentPatterns(frequentItems->size());
    frequentPatternEnumeration->execute(rootClass, true, nullptr, nullptr);

    frequentPatternCount = frequentPatternEnumeration->getFrequentPatterns();
    joinCount = frequentPatternEnumeration->getJoinCount();

    return arg;
}

std::vector<Pattern*> *Spade::getPatterns(std::vector<EquivalenceClass*> *frequentItems) {
    auto *patterns = new std::vector<Pattern*>;
    for(auto frequentItem : *frequentItems) {
        patterns->push_back(frequentItem->getClassIdentifier());
    }
    return patterns;
}