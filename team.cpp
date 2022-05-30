#include "team.hpp"

using namespace std;


string Team::get_name(){return this->team_name;}

float Team::get_talent(){return this->talent_level;}

int Team::get_wins(){return this->num_of_wins;}

int Team::get_points_scored(){return this->num_of_points_scored;}

int Team::get_points_against(){return this->num_of_points_against;}