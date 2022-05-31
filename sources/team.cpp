#include "team.hpp"

using namespace std;

Team::Team(){
    // generate random name
    string name = "";
    int var;
    char random_char;
    for (size_t i = 0; i < 6; i++)
    {
        var = rand()%25 +1;
        random_char = 65 + var;
        name += random_char;
    }
    this->team_name = name;
    this->talent_level = (float) rand() / RAND_MAX;
    this->num_of_wins = 0;
    this->num_of_points_against = 0;
    this->num_of_points_scored = 0;
    this->win_streak = 0;
    this->loss_streak = 0;
    this->max_win_streak = 0;
    this->max_loss_streak = 0;

}

string Team::get_name(){return this->team_name;}

float Team::get_talent(){return this->talent_level;}

int Team::get_wins(){return this->num_of_wins;}

int Team::get_points_scored(){return this->num_of_points_scored;}

int Team::get_points_against(){return this->num_of_points_against;}

void Team::set_points_scored(int points){
    this->num_of_points_scored += points;
}

void Team::set_points_against(int points){
    this->num_of_points_against += points;
}

void Team::add_win(){
    this->num_of_wins++;
    this->win_streak++;
    if (this->loss_streak > this->max_loss_streak)
    {
        this->max_loss_streak = this->loss_streak;
    }
    this->loss_streak = 0;
}

void Team::add_loss(){
    this->loss_streak++;
    if (this->win_streak > this->max_win_streak)
    {
        this->max_win_streak = this->win_streak;
    }
    this->win_streak = 0;
}

int Team::get_loss_streak() {return this->max_loss_streak;}

int Team::get_win_streak() {return this->max_win_streak;}



bool operator<(const Team& team1, const Team& team2){

    if (team1.num_of_wins == team2.num_of_wins)
    {
        int diff1 = team1.num_of_points_scored - team1.num_of_points_against;
        int diff2 = team2.num_of_points_scored - team2.num_of_points_against;
        return diff1 < diff2;
    }
    return team1.num_of_wins < team2.num_of_wins;
}