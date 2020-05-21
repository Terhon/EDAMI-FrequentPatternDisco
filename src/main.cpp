#include <iostream>
#include "Spade.hpp"

int main()
{
    auto *s = new Spade();
    std::cout << s->run(10);
}