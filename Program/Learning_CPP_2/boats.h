#ifndef BOATS_H
#define BOATS_H


class boats
{
public:
    int boatsize;
    //mogelijk nog special ability ma das detail;
};

class Carrier : public boats
{
public:
    Carrier(int size);
};
//---------------------------------------------------
class Battleship : public boats
{
public:
    Battleship(int size);
};
//---------------------------------------------------
class Cruiser : public boats
{
public:
    Cruiser(int size);
};
//---------------------------------------------------
class Submarine : public boats
{
public:
    Submarine(int size);
};
//---------------------------------------------------
class Destroyer : public boats
{
public:
    Destroyer(int size);
};
#endif // BOATS_H
