#include "league.hpp"
#include <iostream>

using namespace std;


int main(){

    League l1;

    cout << l1; // prints the league

    vector<Team*> vec = l1.get_leaders(10);
    for(Team* t : vec){
        cout << t->get_name() << endl;
    }

    cout << "Win Streak: " <<l1.win_streak() << endl;
    cout << "Loss Streak: " << l1.loss_streak() << endl;
    
    
    return 0;
}