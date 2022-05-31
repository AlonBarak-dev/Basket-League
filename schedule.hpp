#pragma once
#include "game.hpp"
#include <unordered_map>


class Schedule{

    private:
        std::unordered_map<int, std::vector<Game*>>* schedule_table;

    public:

        Schedule(){}
        ~Schedule(){}

        void create_schedule(std::unordered_map<Team*, int>&);
        int find_round(Team* , Team*, std::unordered_map<int, std::vector<Game*>>*);
};