//
// Created by Sean Hakmon on 05/01/2022.
//

#ifndef HW4_MARKET_H
#define HW4_MARKET_H
#include <exception>
#include <vector>
#include "Farm.h"
#include <iostream>
#include <string>
using namespace std;
class Market
{
    int year;
    vector<Farm*> Farms;

public:
    Market();

    void CreateNewFarms();
    void TradingDay();
    void nextYear();
    void fastForwardYears();
    void printMarketFarms();

    int getYear() const;
    virtual ~Market();

};

class CowExp : public exception
{
public:
    const char* what() const throw() override
    {
        return "Insert valid number of cow farms";
    }
};

class ChickExp : public exception
{
public:
    const char* what() const throw() override
    {
        return "Insert valid number of chicken farms";
    }
};

class SheepExp : public exception
{
public:
    const char* what() const throw() override
    {
        return "Insert valid number of sheep farms";
    }
};





#endif //HW4_MARKET_H
