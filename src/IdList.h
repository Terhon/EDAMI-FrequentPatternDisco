#ifndef SPADE_IDLIST_H
#define SPADE_IDLIST_H

#include "Pattern.h"
#include <map>

class IdList {
    std::map<int, std::vector<int> *> *entries = new std::map<int, std::vector<int> *>();
    std::vector<bool> *sequences = new std::vector<bool>;//TODO: size

    std::vector<int> *equalOperation(int sid, std::vector<int> *transAppereances);
    std::vector<int> *laterOperation(int sid, std::vector<int> *transAppereances);

public:
    IdList(std::map<int, std::vector<int> *> *entries) : entries(entries) {}

    int getSupport() {
        return sequences->size();
    }

    void setAppearingSequences(Pattern *pattern) {
        pattern->setAppearingIn(sequences);
    }

    IdList *join(IdList *idList, bool equals, int minSupport);
};


#endif //SPADE_IDLIST_H
