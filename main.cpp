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

void printPlayer(player p1, int i){
        cout<<"Player Number: "<<i<<", Health: "<<p1.getHealth()<<endl;
        cout << "Player Name: " << p1.Name() << ", Weapon Name: " << p1.weaponName() << ", Weapon Damage: " << p1.weaponDamage() << endl;
        cout << "Meele Weapon: " << p1.meeleName() << ", Meelee Damage: " <<p1.meeleDamage() <<", Health shots remaining: "<<p1.healthShots()<<endl;
        cout << endl;
}

//Play: The main play function after the characters have been chosen

void play(player p1, player p2){
    cout<<"Lets begin the game. Type w for using weapon, m for using meele weapon and h for using a health shot \n";

    int currentPlayer = 0;
    int nextPlayer = 1;

    player playersAr[2];
    playersAr[0] = p1;
    playersAr[1] = p2;
    while(playersAr[0].getHealth()>0 && playersAr[1].getHealth()>0){
        cout<<"\nPlayer stats as follows: \n\n";
        printPlayer(playersAr[0], 1);
        printPlayer(playersAr[1] ,2);

        start:
        cout<<"\nYour turn player "<<currentPlayer+1<<". Type w (weapon) / h (health shot) / m (meele weapon): ";
        char choice;
        cin>>choice;

        switch (choice){
            case 'w':
                cout<<"Weapon Used "<<playersAr[currentPlayer].weaponName()<<endl;
                playersAr[nextPlayer].damageDone(playersAr[currentPlayer].weaponDamageRandom());
                break;
            case 'm':
                cout<<"Meele Weapon Used "<<playersAr[currentPlayer].meeleName()<<endl;
                playersAr[nextPlayer].damageDone(playersAr[currentPlayer].meeleDamageRandom());
                playersAr[currentPlayer].damageTaken((playersAr[currentPlayer].meeleDamageRandom()));
                break;
            case 'h':
                if(playersAr[currentPlayer].getHealth()) {
                    playersAr[currentPlayer].healthRestored(playersAr[currentPlayer].healthRepair());
                }
                else {
                    cout<<"No more health shots remaining. Try again"<<endl;
                    goto start;
                }
                break;
            default:
                cout<<"Input error. Try again"<<endl;
                goto start;
        }

        if (currentPlayer == 0){
            nextPlayer = 0;
            currentPlayer = 1;
        } else {
            currentPlayer = 0;
            nextPlayer = 1;
        }
        
    }

    int winner=((playersAr[0].getHealth()>playersAr[1].getHealth())?1:2);
    cout<<"Player "<<winner<<" won the game. "<<endl;

}

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