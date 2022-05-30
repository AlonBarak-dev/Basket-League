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

        Team(std::string name, float talent) : team_name(name),
                                               talent_level(talent), 
                                               num_of_wins(0), 
                                               num_of_points_against(0), 
                                               num_of_points_scored(0){}
        
        ~Team(){}


        std::string get_name();
        float get_talent();
        int get_wins();
        int get_points_scored();
        int get_points_against();

};