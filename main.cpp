#include "league.hpp"
#include <iostream>

using namespace std;


int main(){

    League l1;
    cout << "LEAGUE TABLE: \n"; 
    cout << l1; // prints the league
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "TOP 5: \n";
    vector<Team*> vec = l1.get_leaders(5);
    int idx = 1;
    for(Team* t : vec){
        cout << idx << ". " <<t->get_name() << endl;
        idx++;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Win Streak: " <<l1.win_streak() << endl;
    cout << "Loss Streak: " << l1.loss_streak() << endl;
    cout << "Number of Efficient Teams: " << l1.num_of_efficient_teams() << endl;

    cout << "The team with the most points scored: " << l1.scored_most()->get_name()<< " Points: "
         << l1.scored_most()->get_points_scored()<< endl;

    cout << "The team that least scored againts: " << l1.least_scored_against()->get_name() << " Points: "
    << l1.least_scored_against()->get_points_against()<< endl;
    
    return 0;
}