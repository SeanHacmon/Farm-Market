cmake_minimum_required(VERSION 3.21)
project(Hw4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hw4 farmMarket.cpp Animal.cpp Animal.h Farm.cpp Farm.h Market.cpp Market.h Cow.cpp Cow.h Sheep.cpp Sheep.h Chicken.cpp Chicken.h ChickenFarm.cpp ChickenFarm.h SheepFarm.cpp SheepFarm.h CowFarm.cpp CowFarm.h)
