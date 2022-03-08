//
// Created by Sean Hakmon on 05/01/2022.
//

#ifndef HW4_SHEEP_H
#define HW4_SHEEP_H
#include "Animal.h"
#include <string>
#include "iostream"
using namespace std;

class Sheep : public Animal
{
    std :: string product;
public:
    Sheep() : Animal() {age=0, deathAge=5, BuyPrice=5;}
    std::string ProductType() override;
    virtual ~Sheep(){};
};





#endif //HW4_SHEEP_H
