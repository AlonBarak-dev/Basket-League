#include "schedule.hpp"

using namespace std;


int Schedule::find_round(Team* team1, Team* team2, std::unordered_map<int, std::vector<Game*>>* schedule){

    if (team1 == team2)
    {
        // one team cant play itself
        return -1;
    }
    int available_idx = 0;
    bool found;
    for(auto& it : *schedule){
        found = true;
        for(Game* g : it.second){
            // check if the teams already play in this round
            if (g->get_home_team() == team1 || g->get_home_team() == team2 || 
                g->get_away_team() == team1 || g->get_away_team() == team2)
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            // both teams aren't play in the round
            return available_idx;
        }
        available_idx++;
    }
    return 0;
}

void Schedule::create_schedule(std::unordered_map<Team*, int>& league){

    this->schedule_table = new unordered_map<int, vector<Game*>>;

    for (int j = 0; j < 38; j++)
    {
        // initialize the map of games
        vector<Game*> round;
        this->schedule_table->insert({j, round});
    }


    // for each round create 10 different games s.t. in 1 season, each 2 teams play each other twice.
    for(auto& it : league){
        for(auto& it2 : league){

            Team* team1 = it.first;
            Team* team2 = it2.first;
            // find an avaliable round for the match
            int available_round = this->find_round(team1, team2, this->schedule_table);
            if (available_round != -1)
            {
                // team1 != team2
                // create a new Game
                Game* match = new Game{team1, team2};
                // insert the game to the schedule
                this->schedule_table->at(available_round).push_back(match);
            }
        }

    }
    
}