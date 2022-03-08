//
// Created by Sean Hakmon on 05/01/2022.
//

#ifndef HW4_CHICKENFARM_H
#define HW4_CHICKENFARM_H

#include "Chicken.h"
#include "Animal.h"
#include "Farm.h"

class ChickenFarm: public Farm
{
    int numOfAnimals;
    std::string Products;

public:
    ChickenFarm();
    void BuyAnimals() override;
    void PrintFarm() override;
    void BuyProducts() override;
    ~ChickenFarm() override = default;

    void UpdateProd() override;

    void AddPeasantsCow(Farm*) override;
    void AddPeasantsSheep(Farm*) override;
    void AddPeasantsChick(Farm*) override;
//
    bool BuyFromChick() override;
    bool BuyFromSheep() override;
    bool BuyFromCow() override;

    void setNumOfAnimals() override;

};



#endif //HW4_CHICKENFARM_H
