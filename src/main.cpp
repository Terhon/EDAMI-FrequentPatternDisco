#include <iostream>
#include "Spade.h"

int main()
{
    auto *s = new Spade();
    std::cout << s->run(10);
}