#ifndef SPADE_IDLIST_H
#define SPADE_IDLIST_H

#include "Pattern.h"

class IdList {
    std::vector<bool> *sequences = new std::vector<bool>;

public:
    int getSupport() {
        return sequences->size();
    }
    void setAppearingSequences(Pattern *pattern) {
        pattern->setAppearingIn(sequences);
    }

    IdList *join(IdList *idList, bool equals, int minSupport) {
        //TODO
    }
};


#endif //SPADE_IDLIST_H
