#pragma once
#include "game.hpp"
#include "schedule.hpp"
#include <unordered_map>
#include <vector>

#define NUM_OF_TEAMS 20;

class League{

    private:
        std::unordered_map<Team*, int> league_table;
        std::vector<std::string> names;
        Schedule* schedule;
    
    public:

        League(std::vector<Team*> teams = {});

        ~League(){
            for(auto& it : this->league_table){
                delete it.first;
            }
        }


        std::unordered_map<Team*, int> get_table();
        void sort_table();
        friend std::ostream &operator<<(std::ostream& output, const League& l1);
        std::vector<Team*> get_leaders(int);
        int win_streak();
        int loss_streak();
        int num_of_efficient_teams();
        Team* scored_most();
        Team* least_scored_against();

};