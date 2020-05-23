#include "Spade.h"
#include "EquivalenceClass.h"
#include "FrequentPatternEnumeration.h"
#include "SequenceDatabase.h"

int Spade::run(int arg) {
    auto *db = new SequenceDatabase();
    auto *cg = new CandidateGenerator();
    auto sup = 0.1;

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