#pragma once
#include <string>
#include <stdlib.h>
#include <stdexcept>

class Team{

    private:
        std::string team_name;
        float talent_level;
        int num_of_wins;
        int num_of_points_scored;
        int num_of_points_against;
        int max_win_streak;
        int max_loss_streak;
        int win_streak;
        int loss_streak;

    public:

        Team(const std::string& name, const float& talent) : team_name(name),
                                               talent_level(talent), 
                                               num_of_wins(0), 
                                               num_of_points_against(0), 
                                               num_of_points_scored(0),
                                               win_streak(0),
                                               loss_streak(0),
                                               max_win_streak(0),
                                               max_loss_streak(0){
                                                   if (talent > 1)
                                                   {
                                                       throw std::invalid_argument("talent level should be between 0 to 1");
                                                   }
                                                   
                                               }

        Team(Team* other){
            this->team_name = other->team_name;
            this->talent_level = other->talent_level;
            this->num_of_wins = other->num_of_wins;
            this->num_of_points_against = other->num_of_points_against;
            this->num_of_points_scored = other->num_of_points_scored;
            this->win_streak = other->win_streak;
            this->loss_streak = other->loss_streak;
            this->max_win_streak = other->max_win_streak;
            this->max_loss_streak = other->max_loss_streak;
        }

        Team();
        
        ~Team(){}


        std::string get_name();
        float get_talent();
        int get_wins();
        int get_points_scored();
        int get_points_against();
        void set_points_scored(int points);
        void set_points_against(int points);
        void add_win();
        void add_loss();
        int get_win_streak();
        int get_loss_streak();
        friend bool operator<(const Team&, const Team&);

};