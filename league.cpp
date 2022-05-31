#include "league.hpp"

using namespace std;

League::League(vector<Team*> teams){
    
    // number of teams that should be randomly created
    int new_teams = 20 - teams.size();

    if (new_teams == 0)
    {
        // no need for random teams
        for(Team* t : teams){
            // initialize the league table
            this->league_table.insert({t,0});
            this->names.push_back(t->get_name());
        }
    }
    else{
        while(new_teams > 0){
            Team* tmp = new Team();
            this->league_table.insert({tmp,0});
            this->names.push_back(tmp->get_name());
            new_teams--;
        }
    }
    // create a schedule for the league
    this->schedule->create_schedule(this->league_table);
}

unordered_map<Team*, int> League::get_table(){
    return this->league_table;
}


void League::sort_table(){

    // initialize an array with the League's teams
    Team* list[20];
    int index = 0;
    for(auto& it : this->league_table){
        list[index] = it.first;
        index++;
    }


    





}