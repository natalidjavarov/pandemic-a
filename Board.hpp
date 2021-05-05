#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>

namespace pandemic
{

    class Board
    {
        std::map<City, int> disease_level;

    public:
        Board();
        int &operator[](City c);
        bool is_clean();
        void remove_cures();
        friend std::ostream &operator<<(std::ostream &out, Board &b);
    };
}
