//
// Created by Sean Hakmon on 05/01/2022.
//

#include "ChickenFarm.h"
#include "SheepFarm.h"
//#include "Sheep.h"


ChickenFarm::ChickenFarm()
{

    this->numOfAnimals = 3;
    Animals.push_back(new Chicken);
    Animals.push_back(new Chicken);
    Animals.push_back(new Chicken);
    this->Products = "Egg";


}

void ChickenFarm:: BuyAnimals()
{
    int counter = 0;
    while (this->Money >= 3)
    {
        this->Money -= 3;
        this->numOfAnimals+= 1;
        this->Animals.push_back(new Chicken);
        counter ++;
    }
    if (counter != 0)
    {
        cout << "Chicken farm(" << this->ID << ") bought " << counter << " chickens for " << 3*counter
        << " dollars" << endl;
    }
}

void ChickenFarm::BuyProducts()
{
    int flag = 0;
    int counter = 0;
    for (int i = 0; i < Peasants.size(); ++i)
    {
        while (Farm::Peasants[i]->getMoney() >= 1 && this->Egg > 0)
        {
            Farm::Peasants[i]->setEgg(1);
            Farm::Peasants[i]->setMoney(-1);
            this->Egg --;
            counter ++;
            flag = 1;
        }
        if (flag == 1 && counter != 0)
        {
            cout << "Cow farm(" << Peasants[i]->getID() << ") bought " << counter << " eggs for " << counter
            << " dollars "<< "from Chicken farm(" << this->ID << ")" << endl;
        }
        this->Money += counter;
        counter = 0;
    }
}

void ChickenFarm::PrintFarm()
{
    cout << "Farm Id: " << this->ID << ", type: Chicken Farm, Money: " << this->Money << ", Animals: "
         << this->numOfAnimals << " chickens, Products: " << "Milk[" << this->Milk << "], Wool[" << this->Wool
         << "], Eggs[" << this->Egg << "]" << endl;
}

void ChickenFarm::UpdateProd()
{
    for (int i = 0; i < this->Animals.size(); ++i)
    {
        Farm::Egg += Animals[i]->getAge();
    }
}


bool ChickenFarm::BuyFromChick() {return false;}
bool ChickenFarm::BuyFromSheep() {return true;}
bool ChickenFarm::BuyFromCow() {return false;}

void ChickenFarm::AddPeasantsCow(Farm* farm)
{
    if (!(PeasantsContains(farm->getID())) && farm->BuyFromChick() )
    {
        Farm::Peasants.push_back(farm);
        cout << "Chicken farm(" << this->ID << ") Added Cow farm(" << farm->getID() << ") to his client list" << endl;
    }
}

void ChickenFarm::AddPeasantsSheep(Farm* farm){}

void ChickenFarm::AddPeasantsChick(Farm* farm) {}

void ChickenFarm::setNumOfAnimals() {this->numOfAnimals--;}
