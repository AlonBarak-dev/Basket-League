#include "doctest.h"
#include "league.hpp"
#include <iostream>
using namespace std;

TEST_CASE("BUILD"){
/**
 * @brief in this test case we confirm that all 3 ways of
 * creating a League are working.
 */

    // Full Random Build
    League full_random;

    CHECK(full_random.get_table().size() == 20);
    CHECK_FALSE(full_random.get_leaders(1).empty());
    

    // Half Random Build
    vector<Team*> team_vec;
    Team* t1 = new Team{"Maccabi TLV", 0.9};
    Team* t2 = new Team{"Hapoel TLV", 0.1};
    Team* t3 = new Team{"Maccabi Rishon", 0.5};
    Team* t4 = new Team{"Maccabi Holon", 0.7};
    Team* t5 = new Team{"Maccabi Ashdod", 0.6};
    Team* t6 = new Team{"Maccabi Miami", 0.9};
    Team* t7 = new Team{"FC Barcelona", 0.8};
    Team* t8 = new Team{"FC Real Madrid", 0.0001};
    Team* t9 = new Team{"Lakers", 1.0};
    Team* t10 = new Team{"Maccabi Ariel", 0.4};
    team_vec.push_back(t1);
    team_vec.push_back(t2);
    team_vec.push_back(t3);
    team_vec.push_back(t4);
    team_vec.push_back(t5);
    team_vec.push_back(t6);
    team_vec.push_back(t7);
    team_vec.push_back(t8);
    team_vec.push_back(t9);
    team_vec.push_back(t10);
    cout << "pass" << endl;
    League half_random{team_vec};
    
    CHECK(half_random.get_table().size() == 20);
    CHECK_FALSE(half_random.get_leaders(1).empty());


    // No Random team

    vector<Team*> team_vec2;
    Team* team1 = new Team{"Maccabi TLV", 0.9};
    Team* team2 = new Team{"Hapoel TLV", 0.1};
    Team* team3 = new Team{"Maccabi Rishon", 0.5};
    Team* team4 = new Team{"Maccabi Holon", 0.7};
    Team* team5 = new Team{"Maccabi Ashdod", 0.6};
    Team* team6 = new Team{"Maccabi Miami", 0.9};
    Team* team7 = new Team{"FC Barcelona", 0.8};
    Team* team8 = new Team{"FC Real Madrid", 0.0001};
    Team* team9 = new Team{"Lakers", 1.0};
    Team* team10 = new Team{"Maccabi Ariel", 0.4};
    Team* team11 = new Team{"Maccabi TLV B", 0.9};
    Team* team12 = new Team{"Hapoel TLV B", 0.1};
    Team* team13 = new Team{"Maccabi Rishon B", 0.5};
    Team* team14 = new Team{"Maccabi Holon B", 0.7};
    Team* team15 = new Team{"Maccabi Ashdod B", 0.6};
    Team* team16 = new Team{"Maccabi Miami B", 0.9};
    Team* team17 = new Team{"FC Barcelona B", 0.8};
    Team* team18 = new Team{"FC Real Madrid B", 0.0001};
    Team* team19 = new Team{"Lakers B", 1.0};
    Team* team20 = new Team{"Maccabi Ariel B", 0.4};
    team_vec2.push_back(team1);
    team_vec2.push_back(team2);
    team_vec2.push_back(team3);
    team_vec2.push_back(team4);
    team_vec2.push_back(team5);
    team_vec2.push_back(team6);
    team_vec2.push_back(team7);
    team_vec2.push_back(team8);
    team_vec2.push_back(team9);
    team_vec2.push_back(team10);
    team_vec2.push_back(team11);
    team_vec2.push_back(team12);
    team_vec2.push_back(team13);
    team_vec2.push_back(team14);
    team_vec2.push_back(team15);
    team_vec2.push_back(team16);
    team_vec2.push_back(team17);
    team_vec2.push_back(team18);
    team_vec2.push_back(team19);
    team_vec2.push_back(team20);

    League no_random{team_vec2};

    CHECK(no_random.get_table().size() == 20);
    CHECK_FALSE(no_random.get_leaders(1).empty());



}