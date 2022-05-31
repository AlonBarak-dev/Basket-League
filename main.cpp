#include "league.hpp"
#include <iostream>

using namespace std;

int main(){

    while(true){
        cout << "--------- NEW LEAGUE ----------" << endl;
        int num_of_teams = 0;
        string input;
        string name;
        float talent;
        bool non_random;
        vector<Team*> teams_vec;

        while(num_of_teams < 20){
            
            cout << "Wish to stop here and generate random teams ?" << endl;
            cin >> input;
            non_random = (input == "true");
            if (non_random)
            {
                break;
            }
            cout << "Enter team name:" << endl;
            cin >> name;
            cout << "Enter Talent level (0,1):" << endl;
            cin >> talent;
            Team* t = new Team{name, talent};
            teams_vec.push_back(t);
            num_of_teams++;
        }
        while(num_of_teams < 20){
            Team* t = new Team;
            teams_vec.push_back(t);
            num_of_teams++;
        }
        League league{teams_vec};

        cout << "~~ LEAGUE TABLE: " << endl;
        cout << league;

        int top;
        cout << "Enter number of leaders to present: " << endl;
        cin >> top;
        cout << "~~ TOP TEAMS: " << endl;
        vector<Team*> leaders = league.get_leaders(top);
        for(Team* t : leaders){
            cout << t->get_name() << endl;
        }

        cout << "~~ Number of efficient teams: " << league.num_of_efficient_teams() << endl;
        cout << "~~ Longest win streak: " << league.win_streak() << endl;
        cout << "~~ Longest loss streak: " << league.loss_streak() << endl;
        cout << "~~ Scored Most points: " << league.scored_most()->get_name() 
            << " Points: " << league.scored_most()->get_points_scored() << endl;
        cout << "~~ Conceded least points: " << league.least_scored_against()->get_name() 
            << " Points: " << league.least_scored_against()->get_points_against() << endl;


    }












    return 0;
}