#include "game.hpp"

using namespace std;


Game::Game(Team* home, Team* away){

    this->home_team = home;
    this->away_team = away;
    // need to calculate points base on Normal distrobution.
    int tmp;
    while(true){
        tmp = std::round(this->distro(this->gen));
        if (tmp <= 100 && tmp >= 55)
        {
            this->home_team_points = tmp;
            // add points base on talent
            this->home_team_points += this->home_team->get_talent()*10;
            this->home_team->set_points_scored(this->home_team_points);
            break;
        }
    }
    while(true){
        tmp = std::round(this->distro(this->gen));
        if (tmp <= 100 && tmp >= 50)
        {
            this->away_team_points = tmp;
            // add points base on talent
            this->away_team_points += this->away_team->get_talent()*10;
            this->away_team->set_points_scored(this->away_team_points);
            break;
        }
    }
    // add points against for each team
    this->away_team->set_points_against(this->home_team_points);
    this->home_team->set_points_against(this->away_team_points);

    // spot the winner
    if (this->home_team_points > this->away_team_points)
    {
        // home team won
        this->winner = this->home_team->get_name();
        this->home_team->add_win();
    }
    else if (this->home_team_points < this->away_team_points)
    {
        // away team won
        this->winner = this->away_team->get_name();
        this->away_team->add_win();
    }
    else{
        // its a tie, will be decide base on talent level
        if (this->home_team->get_talent() > this->away_team->get_talent())
        {
            // home team won
            this->winner = this->home_team->get_name();
            this->home_team->add_win();
        }
        else{
            // away team won
            this->winner = this->away_team->get_name();
            this->away_team->add_win();
        }
    }
    
    
}

// default ctor
Game::Game() = default;

Team* Game::get_home_team(){return this->home_team;}

Team* Game::get_away_team(){return this->away_team;}

Team* Game::get_winner(){

    if (this->home_team_points > this->away_team_points)
    {
        return this->home_team;
    }
    return this->away_team;
}