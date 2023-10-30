#ifndef BOATS_H
#define BOATS_H

#include <string.h>
#include <iostream>

class boats
{
public:
    int boatsize;
    std::string boatname;
    //mogelijk nog special ability ma das detail;
};

class Carrier : public boats
{
public:
    Carrier(int size, std::string name);
};

//---------------------------------------------------
class Battleship : public boats
{
public:
    Battleship(int size, std::string name);
};

//---------------------------------------------------
class Cruiser : public boats
{
public:
    Cruiser(int size, std::string name);
};

//---------------------------------------------------
class Submarine : public boats
{
public:
    Submarine(int size, std::string name);
};

//---------------------------------------------------
class Destroyer : public boats
{
public:
    Destroyer(int size, std::string name);
};

#endif // BOATS_H
