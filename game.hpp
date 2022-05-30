#pragma once 
#include "team.hpp"


class Game{

    private:
        Team* home_team;
        Team* away_team;
        int home_team_points;
        int away_team_points;
        std::string winner;
    
    public:

        Game(Team& home, Team& away) : home_team(home), away_team(away){
            // need to calculate points base on Normal distrobution.
            this->home_team_points = 0;
            this->away_team_points = 0;

            this->winner = home_team.get_name();
        }

        ~Game(){}

        Team* get_home_team();
        Team* get_away_team();
        Team* get_winner();

}