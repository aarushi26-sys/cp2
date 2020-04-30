#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include "players.h"
#include "player.h"

using namespace std;

void showGameRules()
{
    cout<<"Welcome to the game of SPARTANS "<<endl;
    cout<<"Created by Mithil and Aarushi!"<<endl;
    cout<<"Press enter to continue";
    cin.get();
    cout<<"Rules for the game: "<<endl;
    cout<<"1. Each player starts with health of 100 points."<<endl;
    cout<<"2. Each player also gets 3 Healthshots which increases the health points from 15-25(AI generated) ."<<endl;
    cout<<"3. The goal of each player is to decrease the health points of the other player."<<endl;
    cout<<"4. This can be done by either using the meelee or weapon."<<endl;
    cout<<"5. Each weapon or meelee will decrease the health points of the other player but will also lower your health points."<<endl;
    cout<<"May the odds be in your favour."<<endl;
    cout<<"Press enter to start the game!";
    cin.get();
}

//displays each character role and their attributes
void showPlayers(players players_list)
{

    cout << "Choose your Character: \n\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "Character Number: " << i + 1 << endl;
        cout << "Character Name: " << players_list.name[i] << ", Weapon Name: " << players_list.weapon_name[i] << ", Weapon Damage: " << players_list.weapon_damage[i] << endl;
        cout << "Meele Weapon: " << players_list.meele_name[i] << ", Meelee Damage: " << players_list.meele_damage[i] << endl;
        cout << endl;
    }
}


//Play: The main play function after the characters have been chosen. Function definition in play.cpp
void play(player *p1, player *p2);

int main()
{
    //Recording time
    

    //Display Game Rules
    showGameRules();

    //Display Player List
    players players_list;
    showPlayers(players_list);

    //Choice1 and Choice2 are input choices for player 1 and 2 respectively
    int choice1 = 0, choice2 = 0;


    string p1name, p2name;
    cout<<"Enter name of Player 1: ";
    cin>>p1name;
    cout<<"Enter name of Player 2: ";
    cin>>p2name;

    //Create player objects and initialise them according to the input choice using constructors
    cout << "Player "<<p1name<<" Choose player (1-5): ";
    cin >> choice1;
    choice1 -= 1;

    player *p1 = new player;
    player *p2 = new player;
    *p1 = player(p1name, players_list.meele_name[choice1], players_list.weapon_name[choice1], players_list.meele_damage[choice1], players_list.weapon_damage[choice1]);

    do {
        if (choice1 + 1 == choice2)
            cout << "This character has already been chosen. Please try again.\n";
        cout << "Player "<<p2name<<" Choose your character (1-5): ";
        cin >> choice2;
    } while ((choice1 + 1) == choice2);
    choice2 -= 1;

    *p2 = player(p2name, players_list.meele_name[choice2], players_list.weapon_name[choice2], players_list.meele_damage[choice2], players_list.weapon_damage[choice2]);

    cout<<endl<<endl;
    play(p1, p2);

    delete p1;
    delete p2;
}
