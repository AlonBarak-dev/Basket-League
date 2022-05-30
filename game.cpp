#include "game.hpp"

using namespace std;


Team* Game::get_home_team(){return this->home_team;}

Team* Game::get_away_team(){return this->away_team;}

Team* Game::get_winner(){

    if (this->home_team_points > this->away_team_points)
    {
        return this->home_team;
    }
    return this->away_team;
}