//
// Created by Sean Hakmon on 05/01/2022.
//

#include "Market.h"
#include "SheepFarm.h"
#include "Farm.h"
#include "CowFarm.h"
#include "ChickenFarm.h"
#include <iostream>
using namespace std;


Market::Market()
{
    this->year = 0;
}

void Market::CreateNewFarms()
{
    cout << "----Creating new farms----" << endl;

    bool flag = true;
    int num1, num2, num3;
    ///// Adding Cow Farms.
    while (flag) {
        flag = false;
        try
        {
            cout << "How many new cow farms will be added this year?" << endl;
            scanf("%d", &num1);

            if (num1 < 0)
            {
                flag = true;
                throw CowExp();
            }
        }
        catch (CowExp &ec) { std::cout << ec.what() << endl; continue; }
        try
        {
            cout << "How many new sheep farms will be added this year?" << endl;
            scanf("%d", &num2);

            if (num2 < 0) {
                flag = true;
                throw SheepExp();
            }
        }
        catch (SheepExp &es) { std::cout << es.what() << endl; continue; }
        try {
            cout << "How many new chicken farms will be added this year?" << endl;
            scanf("%d", &num3);

            if (num3 < 0) {
                flag = true;
                throw ChickExp();
            }
        }
        catch (ChickExp &ec) { cout << ec.what() << endl; continue;}
    }
    for (int i = 0; i < num1; ++i) {
        this->Farms.push_back(new CowFarm);
    }

    ///// Adding Sheep Farms.
    for (int i = 0; i < num2; ++i)
    {
        this->Farms.push_back(new SheepFarm);
    }
    ///// Adding Chicken Farms.
    for (int i = 0; i < num3; ++i)
    {
        this->Farms.push_back(new ChickenFarm);
    }

    cout << "----Adding new farms to market----" << endl;

    for (int i = 0; i < Farms.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            Farms[i]->AddPeasantsChick(Farms[j]);
            Farms[j]->AddPeasantsSheep(Farms[i]);
            Farms[j]->AddPeasantsCow(Farms[i]);
            Farms[j]->AddPeasantsChick(Farms[i]);


            Farms[i]->AddPeasantsSheep(Farms[j]);
            Farms[i]->AddPeasantsCow(Farms[j]);
        }

    }

}

void Market::TradingDay()
{
    cout << "----Begin Market----" << endl;
    for (int i = 0; i < this->Farms.size(); ++i)
    {
        this->Farms[i]->BuyProducts();
    }
    cout << "----Buy Animals----" << endl;
    for (int i = 0; i < this->Farms.size(); ++i)
    {
        this->Farms[i]->BuyAnimals();
    }
}

void Market::nextYear()
{
    CreateNewFarms();
    for (int i = 0; i < this->Farms.size(); ++i)
    {
        this->Farms[i]->productProductivity(); /// each farm gets productivity by age
    }
    TradingDay();
    for (int i = 0; i < this->Farms.size(); ++i)
    {
        this->Farms[i]->AgeInc(); /// increase age of each farm by 1.
        this->Farms[i]->setMoney(10); /// adds 10$ to each farm.
    }
    this->year += 1;
}

void Market::fastForwardYears()
{
    int num;
    cout << "How many years to fast forward?" << endl;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i)
    {
        for (int i = 0; i < this->Farms.size() ; ++i)
        {
            this->Farms[i]->productProductivity(); /// each farm gets productivity by age
        }
        TradingDay();
        for (int i = 0; i < this->Farms.size(); ++i)
        {
            this->Farms[i]->AgeInc(); /// increase age of each farm by 1.
            this->Farms[i]->setMoney(10); /// adds 10$ to each farm.
        }
        this->year += 1;
    }

}

void Market::printMarketFarms()
{
    cout << "----Market Farms----" << "\n";
    for (int i = 0; i < this->Farms.size(); ++i)
    {
        Farms[i]->PrintFarm();
    }
}

int Market::getYear() const {return this->year;}

Market::~Market()
{
    for (vector<Farm*>::iterator it = this->Farms.begin() ; it != Farms.end() ; ++it)
    {
        delete *it;
//        Farms.erase(it);
    }
}

