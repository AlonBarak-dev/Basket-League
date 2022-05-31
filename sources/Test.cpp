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





}