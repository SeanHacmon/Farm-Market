//
// Created by Sean Hakmon on 05/01/2022.
//

#ifndef HW4_SHEEPFARM_H
#define HW4_SHEEPFARM_H
#include "Farm.h"
#include "Animal.h"
#include "Sheep.h"
class SheepFarm : public Farm
{
    int numOfAnimals;
    std::string Products;

public:
    SheepFarm();
    void BuyAnimals() override;
    void PrintFarm() override;
    void BuyProducts() override;
    virtual ~SheepFarm()= default;

    void UpdateProd() override;

    void AddPeasantsCow(Farm*) override;
    void AddPeasantsSheep(Farm*) override;
    void AddPeasantsChick(Farm*) override;

    bool BuyFromChick() override;
    bool BuyFromSheep() override;
    bool BuyFromCow() override;

    void setNumOfAnimals() override;

};


#endif //HW4_SHEEPFARM_H
