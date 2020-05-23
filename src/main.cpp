#include <iostream>
#include "Spade.h"

int main() {
    //auto *s = new Spade();
    //std::cout << s->run(10);
    auto l = new std::list<int>;
    l->push_back(1);
    l->push_back(2);
    l->push_back(3);
    /*for (auto it = l->crbegin(); it != l->crend(); it++) {
        if (*it == 2) {
            l->erase(std::next(it).base());
        }
    }*/
    for (auto it = l->crbegin(); it != l->crend(); it++) {
        for(auto jt = it; jt != l->crend(); jt++)
            std::cout << *jt;
        std::cout << ' ';
    }
}