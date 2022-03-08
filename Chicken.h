//
// Created by Sean Hakmon on 05/01/2022.
//

#ifndef HW4_CHICKEN_H
#define HW4_CHICKEN_H
#include "Animal.h"
#include <string>
#include "iostream"
using namespace std;

class Chicken : public Animal
{
    std :: string product;
public:
    Chicken(): Animal() {age=0, deathAge=3, BuyPrice=3;}
    std:: string ProductType() override;
    virtual ~Chicken(){};
};




#endif //HW4_CHICKEN_H
