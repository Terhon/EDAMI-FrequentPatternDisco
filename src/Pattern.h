#ifndef SPADE_PATTERN_H
#define SPADE_PATTERN_H

#include <vector>
#include "Item.h"

class Pattern {
    std::vector<Item*> *elements = new std::vector<Item*>;
    std::vector<bool> *appearingIn = new std::vector<bool>;

public:
    bool isPrefix(Pattern *p) {
        bool output = false;
        std::vector<Item*> *pElements = p->getElements();
        pElements->pop_back();
        if (pElements->back() == elements->back())
            output = true;
        return output;
    }

    std::vector<Item*> *getElements() {
        return elements;
    }

    Item* getLastElement() {
        if (elements->empty())
            return nullptr;
        return elements->back();
    }

    void setAppearingIn(std::vector<bool> *appearingIn) {
        this->appearingIn = appearingIn;
    }

    std::vector<bool> *getAppearingIn() {
        return appearingIn;
    }

    void add(Item* item) {
        elements->push_back(item);
    }

    Pattern *clonePattern(){
        //TODO
    }

    int compareTo(Pattern *p){
        //TODO
    }
};


#endif //SPADE_PATTERN_H
