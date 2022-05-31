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
    
    
    return 0;
}