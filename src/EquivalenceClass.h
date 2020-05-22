#ifndef SPADE_EQUIVALENCECLASS_H
#define SPADE_EQUIVALENCECLASS_H

#include <vector>

class EquivalenceClass {

    std::vector<EquivalenceClass*> *members = new std::vector<EquivalenceClass*>;
public:
    void addMember(EquivalenceClass *eqClass) {members->push_back(eqClass);}
};


#endif //SPADE_EQUIVALENCECLASS_H
