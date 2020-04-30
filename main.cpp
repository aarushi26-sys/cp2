#include <iostream>
#include <stdlib.h>
#include "players.h"
#include "player.h"

using namespace std;

void showGameRules()
{

}

//displays each character role and their attributes
void showPlayers(players players_list)
{

    cout << "Choose your Player: \n\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "Player Number: " << i + 1 << endl;
        cout << "Player Name: " << players_list.name[i] << ", Weapon Name: " << players_list.weapon_name[i] << ", Weapon Damage: " << players_list.weapon_damage[i] << endl;
        cout << "Meele Weapon: " << players_list.meele_name[i] << ", Meelee Damage: " << players_list.meele_damage[i] << endl;
        cout << endl;
    }
}


//Play: The main play function after the characters have been chosen. Function definition in play.cpp
void play(player p1, player p2);

int main()
{
    //Clearing Screen

    //Display Game Rules
    showGameRules();

    //Display Player List
    players players_list;
    showPlayers(players_list);

    //Choice1 and Choice2 are input choices for player 1 and 2 respectively
    int choice1 = 0, choice2 = 0;

    //Create player objects and initialise them according to the input choice using constructors
    cout << "Player 1 Choose player (1-5): ";
    cin >> choice1;
    choice1 -= 1;
    player p1(players_list.name[choice1], players_list.meele_name[choice1], players_list.weapon_name[choice1], players_list.meele_damage[choice1], players_list.weapon_damage[choice1]);

    do {
        if (choice1 + 1 == choice2)
            cout << "This character has already been chosen. Please try again.\n";
        cout << "Player 2 Choose player (1-5): ";
        cin >> choice2;
    } while ((choice1 + 1) == choice2);
    choice2 -= 1;

    player p2(players_list.name[choice2], players_list.meele_name[choice2], players_list.weapon_name[choice2], players_list.meele_damage[choice2], players_list.weapon_damage[choice2]);

    cout<<endl<<endl;
    play(p1, p2);
}