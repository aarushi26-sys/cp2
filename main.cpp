#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "players.h"
#include "player.h"

using namespace std;

//Show the initial game rules screen
void showGameRules()
{
    cout<<"Welcome to the game of SPARTANS "<<endl;
    cout<<"Created by Mithil and Aarushi!"<<endl;
    cout<<"Press enter to continue";
    cin.get();
    cout<<"Rules for the game: "<<endl;
    cout<<"1. Each player will have 100 health points."<<endl;
    cout<<"2. There are 5 character choices within the game each with a different primary gun and a melee weapon. "<<endl;
    cout<<"3. All weapons (including the melee weapons) have different damages. "<<endl;
    cout<<"4. Melee weapons also cost the player using them 40% of the damage the weapon inflicts."<<endl;
    cout<<"5. Each player will also get a total of 3 health shots which restore health upto 25 points, i.e: within the range of 15-25. "<<endl;
    cout<<"6. Only one weapon/health shot can be used in a move. "<<endl;
    cout<<"7. The character selection screen lists the average melee and main weapon damage. The actual damage inflicted will be in the range of +- 5 of the listed value."<<endl;
    cout<<"8. The first player to get the other player's health down to zero wins. "<<endl;
    cout<<"9. All the Game Records will be stored in games.txt along with the timestamp of each game."<<endl;
    cout<<endl<<"Press Enter to continue. ";

    cin.get();
    cout<<endl<<endl;
}

//displays each character role and their attributes
void showPlayers(players players_list)
{

    cout << "Choose your Character: \n\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "Character Number: " << i + 1 << endl;
        cout << "Character Name: " << players_list.name[i] << ", Weapon Name: " << players_list.weapon_name[i] << ", Weapon Damage: " << players_list.weapon_damage[i] << endl;
        cout << "Melee Weapon: " << players_list.meele_name[i] << ", Melee Damage: " << players_list.meele_damage[i] << endl;
        cout << endl;
    }
}


//Play: The main play function after the characters have been chosen. Function definition in play.cpp
void play(player *p1, player *p2);

int main()
{

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

    //Dynamically allocating memory to p1 and p2 (each player's individual character)
    player *p1 = new player;
    player *p2 = new player;
    *p1 = player(p1name, players_list.meele_name[choice1], players_list.weapon_name[choice1], players_list.meele_damage[choice1], players_list.weapon_damage[choice1]);

    //Try again in case the character has already been chosen by Player 1.
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
