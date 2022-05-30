#include "team.hpp"

using namespace std;


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
}