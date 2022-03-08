//
// Created by Sean Hakmon on 05/01/2022.
//

#ifndef HW4_FARM_H
#define HW4_FARM_H

#include "Animal.h"
#include <vector>
class Farm
{
protected:
    int Milk;
    int Wool;
    int Egg;
    static int NumOfFarms;
    int ID;
    int Money;
    vector<Animal*> Animals;
public:
    vector<Farm*> Peasants;
    Farm();
    virtual void BuyAnimals()=0;
    virtual void PrintFarm()=0;
    virtual void productProductivity();
    virtual void AgeInc();
    virtual void BuyProducts()=0;
    virtual ~Farm();

    virtual void UpdateProd()=0;

    virtual void AddPeasantsCow(Farm*)=0;
    virtual void AddPeasantsSheep(Farm*)=0;
    virtual void AddPeasantsChick(Farm*)=0;

    virtual bool BuyFromChick()=0;
    virtual bool BuyFromSheep()=0;
    virtual bool BuyFromCow()=0;

    bool PeasantsContains(int id);

    int getMilk() const;
    int getWool() const;
    int getEgg() const;
    int getID() const;
    int getMoney() const;
    static int getNumOfFarms() ;

    void setMilk(int add);
    void setWool(int add);
    void setEgg(int add);
    void setMoney(int add);
    static void setNumOfFarms();

    virtual void setNumOfAnimals()=0;

};







#endif //HW4_FARM_H
//{
//ID ++;
//Money=10;
//Products=animalType->ProductType();
//numOfProducts = 0;
//numOfAnimals=3;
//}
//int Money;
//Animal* animalType;
//std::string Products;
//int numOfAnimals;
//int numOfProducts;