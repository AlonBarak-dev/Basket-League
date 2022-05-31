#pragma once 
#include "team.hpp"
#include <iomanip>
#include <map>
#include <random>
#include <cmath>

class Game{

    private:
        Team* home_team;
        Team* away_team;
        int home_team_points;
        int away_team_points;
        std::string winner;
        std::random_device rd{};
        std::mt19937 gen{rd()};
        // values near the mean are the most likely
        // standard deviation affects the dispersion of generated values from the mean
        std::normal_distribution<> distro{75,20};
    
    public:

        Game(Team* home, Team* away);
        Game();

        ~Game(){}

        Team* get_home_team();
        Team* get_away_team();
        Team* get_winner();

};