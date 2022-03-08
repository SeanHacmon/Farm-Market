//
// Created by Sean Hakmon on 05/01/2022.
//

#ifndef HW4_ANIMAL_H
#define HW4_ANIMAL_H
#include <iostream>
#include <string>
using namespace std;
class Animal
{
protected:
    int age;
    int BuyPrice;
    int deathAge;
public:
    Animal(){age=0, BuyPrice = 0, deathAge=0;}
    virtual std :: string ProductType()=0;
    virtual ~Animal(){};

    int getAge() const;
    int getDeathAge() const;
    int getBuyPrice() const;

    void setAge(int add);

};








#endif //HW4_ANIMAL_H
