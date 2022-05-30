#pragma once
#include "game.hpp"
#include <unordered_map>


class Schedule{

    private:
        std::unordered_map<int, Game[10]> schedule_table;

    public:

        Schedule(){}
        ~Schedule(){}

        std::unordered_map<int, Game[10]> create_schedule(std::unordered_map<Team*, int>&);
};