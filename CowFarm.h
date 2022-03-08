//
// Created by Sean Hakmon on 05/01/2022.
//

#ifndef HW4_COWFARM_H
#define HW4_COWFARM_H

#include "Cow.h"
#include "Farm.h"
#include "Animal.h"

class CowFarm : public Farm
{
    int numOfAnimals;
    std::string Products;

public:
    CowFarm();
    void BuyAnimals() override;
    void PrintFarm() override;
    void BuyProducts() override;
    virtual ~CowFarm()= default;

    void UpdateProd() override;

    void AddPeasantsCow(Farm*) override;
    void AddPeasantsSheep(Farm*) override;
    void AddPeasantsChick(Farm*) override;

    bool BuyFromChick() override;
    bool BuyFromSheep() override;
    bool BuyFromCow() override;

    void setNumOfAnimals() override;

};
#endif //HW4_COWFARM_H
