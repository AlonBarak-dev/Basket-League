#include "league.hpp"
#include <bits/stdc++.h>

using namespace std;

League::League(vector<Team*> teams){
    
    // number of teams that should be randomly created
    int new_teams = 20 - teams.size();
    for(Team* t : teams){
        for(string name : this->names){
            if(t->get_name() == name){
                throw invalid_argument("2 Teams cannot share same name");
            }
        }
        // initialize the league table
        this->league_table.insert({t,0});
        this->names.push_back(t->get_name());
    }
    while(new_teams > 0){
        Team* tmp = new Team();
        this->league_table.insert({tmp,0});
        this->names.push_back(tmp->get_name());
        new_teams--;
    }
    
    // create a schedule for the league
    this->schedule = new Schedule;
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
    // bubble sort the array
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
    int idx = 1;
    for(auto& it : l1.league_table){
        output << idx << ". " << it.first->get_name() << "--" <<it.first->get_wins()<< endl;
        idx++;
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
    /**
     * @brief this method return the longest win streak in the League
     */

    int max_streak = 0;
    for(auto& it : this->league_table){
        if(it.first->get_win_streak() > max_streak){
            max_streak = it.first->get_win_streak();
        }
    }
    return max_streak;
}

int League::loss_streak(){
    /**
     * @brief this method return th elongest loss atreak in the league
     */
    
    int loss_streak = 0;
    for(auto& it : this->league_table){
        if(it.first->get_loss_streak() > loss_streak){
            loss_streak = it.first->get_loss_streak();
        }
    }
    return loss_streak;
}

int League::num_of_efficient_teams(){
    /**
     * @brief this method return the number of teams that scored more than 
     * conceded
     */
    int counter = 0;
    for(auto& it : this->league_table){
        if(it.first->get_points_scored() - it.first->get_points_against() > 0){
            counter++;
        }
    }
    return counter;
}

Team* League::scored_most(){
    /**
     * @brief this method return the team that scored the most points in the season
     * 
     */

    Team* best_team;
    int score = 0;
    for(auto& it : this->league_table){
        if(it.first->get_points_scored() > score){
            best_team = it.first;
            score = best_team->get_points_scored();
        }
    }
    return best_team;
}

Team* League::least_scored_against(){
    /**
     * @brief this method return the team that conceded the least points in the season
     * 
     */

    Team* best_team;
    int score = 38000;      // maximum

    for(auto& it : this->league_table){
        if(it.first->get_points_against() < score){
            best_team = it.first;
            score = best_team->get_points_against();
        }
    }
    return best_team;
}