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
}