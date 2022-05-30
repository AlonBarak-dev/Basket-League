#pragma once
#include <string>

class Team{

    private:
        std::string team_name;
        float talent_level;
        int num_of_wins;
        int num_of_points_scored;
        int num_of_points_against;

    public:

        Team(const std::string& name, const float& talent) : team_name(name),
                                               talent_level(talent), 
                                               num_of_wins(0), 
                                               num_of_points_against(0), 
                                               num_of_points_scored(0){}

        Team(const Team& other){
            this->team_name = other.team_name;
            this->talent_level = other.talent_level;
            this->num_of_wins = other.num_of_wins;
            this->num_of_points_against = other.num_of_points_against;
            this->num_of_points_scored = other.num_of_points_scored;
        }
        
        ~Team(){}


        std::string get_name();
        float get_talent();
        int get_wins();
        int get_points_scored();
        int get_points_against();

};