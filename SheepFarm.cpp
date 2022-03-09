//
// Created by Sean Hakmon on 05/01/2022.
//

#include "SheepFarm.h"
#include "CowFarm.h"
#include "Farm.h"

/// Default constructor
SheepFarm::SheepFarm()
{
    Animals.push_back(new Sheep);
    Animals.push_back(new Sheep);
    Animals.push_back(new Sheep);
    this->numOfAnimals = 3;
    this->Products = "Wool";
}


/// Using all the money the specific farm has to buy as much as much animals as possible.
void SheepFarm::BuyAnimals()
{
    int counter = 0;
    while (this->Money >= 5)
    {
        this->Money -= 5;
        this->numOfAnimals += 1;
        this->Animals.push_back(new Sheep);
        counter ++;
    }
    if (counter != 0)
    {
        cout << "Sheep farm(" << this->ID << ") bought " << counter << " sheeps for " << 5 * counter << " dollars"
             << endl;
    }
}


/// Allowing the farm that OBSERVES this specific Farm to buy from it products until they are out of money.
void SheepFarm::BuyProducts()
{
    int flag = 0;
    for (int i = 0; i < Peasants.size(); ++i)
    {
        int counter = 0;
        while (Farm::Peasants[i]->getMoney() >= 2 && this->Wool > 0)
        {
            Farm::Peasants[i]->setWool(1);
            this->Wool --;
            Farm::Peasants[i]->setMoney(-2);
            this->Money += 2;
            counter ++;
            flag = 1;
        }
        if (flag == 1 && counter != 0)
        {
            cout << "Chicken farm(" << Peasants[i]->getID() << ") bought " << counter << " wool for " << counter*2
            << " dollars " << "from Sheep farm(" << this->ID << ")" << endl;
        }
    }
}

/// Printing the specific farm.
void SheepFarm::PrintFarm()
{
    cout << "Farm Id: " << this->ID << ", type: Sheep farm, Money: " << this->Money << ", Animals: "
    << this->numOfAnimals << " sheep, Products: " << "Milk[" << this->Milk << "], Wool[" << this->Wool << "], Eggs[" <<
    this->Egg << "]" << endl;
}

/// Increaseing the number of products by calculation of all animals by thier age.
void SheepFarm::UpdateProd()
{
    for (int i = 0; i < this->Animals.size(); ++i)
    {
        Farm::Wool += Animals[i]->getAge();
    }
}

/// Polymorphism
bool SheepFarm::BuyFromChick() {return false;}
bool SheepFarm::BuyFromSheep() {return false;}
bool SheepFarm::BuyFromCow() {return true;}

void SheepFarm::AddPeasantsCow(Farm* farm){}

void SheepFarm::AddPeasantsSheep(Farm* farm){}

void SheepFarm::AddPeasantsChick(Farm* farm)
{
    if (!(PeasantsContains(farm->getID())) && farm->BuyFromSheep())
    {
        Farm::Peasants.push_back(farm);
        cout << "Sheep farm(" << this->ID << ") Added Chicken farm(" << farm->getID() << ") to his client list" << endl;
    }
}

void SheepFarm::setNumOfAnimals() {this->numOfAnimals--;}
