#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>

namespace pandemic{

    class Player {

        protected:
            std::set<City> cards;
            Board board;
            City city;
            std::string job;

        public:
            Player(Board& b, City c, std::string j): board(b), city(c), job(j){}

        Player& take_card(City c);
        Player& drive(City c);
        Player& fly_direct(City c);
        Player& fly_charter(City c);
        Player& fly_shuttle(City c);
        Player& build();
        Player& discover_cure(Color c);
        Player& treat(City c);
        std::string role();
           
    };
}