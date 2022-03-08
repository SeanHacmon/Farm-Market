//
// Created by Sean Hakmon on 05/01/2022.
//

#ifndef HW4_COW_H
#define HW4_COW_H

#include "Animal.h"
#include <string>
#include "iostream"
using namespace std;

class Cow: public Animal
{
    std::string product;
public:
    Cow() : Animal() {deathAge=10, age=0, BuyPrice=10;}
    std::string ProductType() override;
    virtual ~Cow(){};
};


#endif //HW4_COW_H
