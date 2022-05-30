#include "league.hpp"

using namespace std;

League::League(vector<Team*> teams = {}){
    
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
            Team tmp = new Team();
            this->league_table.insert({&tmp,0});
            this->names.push_back(tmp.get_name());
            new_teams--;
        }
    }
}

unordered_map<Team*, int> League::get_table(){
    return this->league_table;
}