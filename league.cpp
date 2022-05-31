#include "league.hpp"
#include <bits/stdc++.h>

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

    // sort the table base on results
    this->sort_table();
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
    
    int i, j;
    for (i = 0; i < 20; i++){
 
        // Last i elements are already
        // in place
        for (j = 0; j < 19; j++){
            if (*list[j] < *list[j + 1]){
                swap(*list[j], *list[j + 1]);
            }
        }
    }

}

std::ostream &operator<<(std::ostream& output, const League& l1){
    /**
     * @brief this method print the league table after the season ends
     */
    
    for(auto& it : l1.league_table){
        output << it.first->get_name() << "--" <<it.first->get_wins()<< endl;
    }
    return output;
}

vector<Team*> League::get_leaders(int number_of_teams){
    /**
     * @brief this method return the number_of_teams that are the leaders 
     * of the league.
     */

    vector<Team*> leaders_vec;

    for(auto& it : this->league_table){
        if(number_of_teams == 0){
            break;
        }
        leaders_vec.push_back(it.first);
        number_of_teams--;
    }

    return leaders_vec;
}


int League::win_streak(){

    int max_streak = 0;
    for(auto& it : this->league_table){
        if(it.first->get_win_streak() > max_streak){
            max_streak = it.first->get_win_streak();
        }
    }
    return max_streak;
}

int League::loss_streak(){
    
    int loss_streak = 0;
    for(auto& it : this->league_table){
        if(it.first->get_loss_streak() > loss_streak){
            loss_streak = it.first->get_loss_streak();
        }
    }
    return loss_streak;
}