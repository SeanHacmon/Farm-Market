//
// Created by Sean Hakmon on 05/01/2022.
//
#include "Market.h"
#include "Farm.h"
int Farm:: NumOfFarms = 0;
Farm ::Farm()
{
    NumOfFarms ++;
    this->ID = NumOfFarms;
    this->Money = 10;
    this->Milk = 0;
    this->Wool = 0;
    this->Egg = 0;
}

/// Increases the whole farm products by it's Age of animals.
void Farm::productProductivity()
{
    this->UpdateProd();
}

/// Increaseing the age of all animals in a specific farm by 1 & If an animal has got to it's death age we remove it.
void Farm::AgeInc()
{
    for (int i = 0; i < this->Animals.size(); ++i)
    {
        this->Animals[i]->setAge(1);
        if (this->Animals[i]->getAge() >= this->Animals[i]->getDeathAge())
        {
            delete this->Animals[i];
            this->setNumOfAnimals();
            this->Animals.erase(Animals.begin()+ i);
            i --;
        }
    }
}

//// Getters & Setters.

int Farm::getMoney() const {return this->Money;}

void Farm::setMoney(int add) {this->Money += add;}

int Farm::getNumOfFarms() {return NumOfFarms;}

int Farm::getID() const {return this->ID;}

int Farm::getMilk() const {return this->Milk;}

int Farm::getWool() const {return this->Wool;}

int Farm::getEgg() const {return this->Egg;}

void Farm::setMilk(int add) {this->Milk += add;}

void Farm::setWool(int add) {this->Wool += add;}

void Farm::setEgg(int add) {this->Egg += add;}

void Farm::setNumOfFarms() {NumOfFarms++;}

bool Farm::PeasantsContains(int id)
{
    for (int i = 0; i < Peasants.size(); ++i)
    {
        if (Peasants[i]->ID == id)
            return true;
    }
    return false;
}

/// Distractor
Farm::~Farm()
{
    for (vector<Animal*>::iterator it = this->Animals.begin() ; it != Animals.end() ; ++it)
    {
        delete *it;
    }


}




