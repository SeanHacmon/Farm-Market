//
// Created by Sean Hakmon on 05/01/2022.
//
#include "ChickenFarm.h"
#include "CowFarm.h"

/// Default constructor
CowFarm::CowFarm()
{
    this->numOfAnimals = 3;
    this->Animals.push_back(new Cow);
    this->Animals.push_back(new Cow);
    this->Animals.push_back(new Cow);
    this->Products = "Milk";
}

/// Using all the money the specific farm has to buy as much as much animals as possible.
void CowFarm::BuyAnimals()
{
    int counter = 0;
    while (this->Money >= 10)
    {
        this->Money -= 10;
        this->numOfAnimals += 1;
        this->Animals.push_back(new Cow);
        counter ++;
    }
    if (counter != 0)
    {
        cout << "Cow farm(" << this->ID << ") bought " << counter << " cows for " << 10*counter << " dollars" << endl;

    }
}

/// Allowing the farm that OBSERVES this specific Farm to buy from it products until they are out of money.
void CowFarm::BuyProducts()
{
    int flag = 0;
    for (int i = 0; i < Peasants.size(); ++i)
    {
        int counter = 0;
        while (Farm::Peasants[i]->getMoney() >= 3 && this->Milk > 0)
        {
            Farm::Peasants[i]->setMilk(1);
            this->Milk --;
            Farm::Peasants[i]->setMoney(-3);
            this->Money += 3;
            counter ++;
            flag = 1;
        }
        if (flag == 1 && counter != 0)
        {
            cout << "Sheep farm(" << Peasants[i]->getID() << ") bought " << counter << " milk for " << counter*3
            << " dollars " << "from Cow farm(" << this->ID << ")" << endl;
        }

    }

}

/// Printing the farm Data.
void CowFarm::PrintFarm()
{
    cout << "Farm Id: " << this->ID << ", type: Cow farm, Money: " << this->Money << ", Animals: "
         << this->numOfAnimals << " cows, Products: " << "Milk[" << this->Milk << "], Wool[" << this->Wool
         << "], Eggs[" << this->Egg << "]" << endl;
}

/// Increaseing the number of products by calculation of all animals by thier age.
void CowFarm::UpdateProd()
{
    for (int i = 0; i < this->Animals.size(); ++i)
    {
        Farm::Milk += Animals[i]->getAge();
    }
}


/// Polymorphism
bool CowFarm::BuyFromChick() {return true;}
bool CowFarm::BuyFromSheep() {return false;}
bool CowFarm::BuyFromCow() {return false;}

void CowFarm::AddPeasantsCow(Farm* farm){}

void CowFarm::AddPeasantsSheep(Farm* farm)
{
    if (!(PeasantsContains(farm->getID())) && farm->BuyFromCow())
    {
        Farm::Peasants.push_back(farm);
        cout << "Cow farm(" << this->ID << ") Added Sheep farm(" << farm->getID() << ") to his client list" << endl;
    }
}

void CowFarm::AddPeasantsChick(Farm* farm){}

void CowFarm::setNumOfAnimals() {this->numOfAnimals--;}
