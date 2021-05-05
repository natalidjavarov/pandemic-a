#include <iostream>
#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"
#include "map"
using namespace std;
using namespace pandemic;

namespace pandemic
{
    Board::Board()
    {
        std::map<City, int> disease_level;
    }

    int &Board::operator[](City c)
    {
        return disease_level[c];
    }

    bool Board::is_clean()
    {
        return true;
    }

    void Board::remove_cures() {}

    ostream &operator<<(ostream &out, Board &b)
    {
        return out;
    }
}