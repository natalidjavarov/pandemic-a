#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "doctest.h"
#include "Player.hpp"

#include "OperationsExpert.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include "Dispatcher.hpp"
#include "GeneSplicer.hpp"

using namespace pandemic;

#include <iostream>
#include <stdexcept>
using namespace std;

TEST_CASE("ligall & iligal"){
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
    
	board[City::Lima] = 3;      // put 3 yellow disease cubes in Kinshasa.
	board[City::MexicoCity] = 3;    // put 3 yellow disease cubes in MexicoCity.
	board[City::Bogota] = 1; // put 1 yellow disease cube in Bogota.
	board[City::NewYork] = 1;       // put 1 blue disease cube in NewYork.
    
	OperationsExpert player {board, City::Atlanta};  // initialize an "operations expert" player on the given board, in Atlanta.
    
    player.take_card(City::Johannesburg);
	player.take_card(City::Khartoum);
	player.take_card(City::SaoPaulo);
	player.take_card(City::BuenosAires);
	player.take_card(City::HoChiMinhCity);
    
     CHECK_NOTHROW(player.drive(City::Madrid));
     CHECK_NOTHROW(player.drive(City::Washington));
     CHECK_THROWS(player.drive(City::Madrid));
     CHECK_NOTHROW(player.fly_direct(City::Johannesburg));
     CHECK_THROWS(player.fly_direct(City::Taipei));
     CHECK_THROWS(player.treat(City::Delhi));
     CHECK_THROWS(player.treat(City::Manila));
     CHECK_THROWS(player.treat(City::Cairo));
     CHECK_THROWS(player.treat(City::London));
     CHECK_THROWS(player.treat(City::Santiago));
     CHECK_THROWS(player.treat(City::Bogota));
     CHECK_THROWS(player.treat(City::Santiago));
     CHECK_THROWS(player.treat(City::NewYork));
     CHECK_THROWS(player.treat(City::Washington));
     CHECK_THROWS(player.fly_charter(City::Seoul));
     CHECK_THROWS(player.drive(City::LosAngeles));
     CHECK_THROWS(player.fly_shuttle(City::LosAngeles));
     CHECK_NOTHROW(player.drive(City::Chicago));
     CHECK_NOTHROW(player.drive(City::Miami));
     CHECK_NOTHROW(player.discover_cure(Color::Blue));
     CHECK_THROWS(player.discover_cure(Color::Black));
     CHECK_THROWS(player.discover_cure(Color::Red));

 }





