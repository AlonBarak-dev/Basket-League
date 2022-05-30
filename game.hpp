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

        Game(Team* home, Team* away){

            this->home_team = home;
            this->away_team = away;
            // need to calculate points base on Normal distrobution.
            int tmp;
            while(true){
                tmp = std::round(this->distro(this->gen));
                if (tmp <= 100 && tmp >= 55)
                {
                    this->home_team_points = tmp;
                    // add points base on talent
                    this->home_team_points += this->home_team->get_talent()*10;
                    this->home_team->set_points_scored(this->home_team_points);
                    break;
                }
            }
            while(true){
                tmp = std::round(this->distro(this->gen));
                if (tmp <= 100 && tmp >= 50)
                {
                    this->away_team_points = tmp;
                    // add points base on talent
                    this->away_team_points += this->away_team->get_talent()*10;
                    this->away_team->set_points_scored(this->away_team_points);
                    break;
                }
            }
            // add points against for each team
            this->away_team->set_points_against(this->home_team_points);
            this->home_team->set_points_against(this->away_team_points);
        }

        ~Game(){}

        Team* get_home_team();
        Team* get_away_team();
        Team* get_winner();

};