#include <iostream>
#include <fstream>
#include "player.h"

using namespace std;

//Print player stats and also output the same to the file
void printPlayer(player p, int i, ofstream &fout){
    cout << "Player Number: " << i << ", Health: " << p.getHealth() << endl;
    cout << "Player Name: " << p.Name() << ", Weapon Name: " << p.weaponName() << ", Weapon Damage: " << p.weaponDamage() << endl;
    cout << "Melee Weapon: " << p.meeleName() << ", Melee Damage: " << p.meeleDamage() << ", Health shots remaining: " << p.healthShots() << endl;
    cout << endl;

    fout << "Player Number: " << i << ", Health: " << p.getHealth() << endl;
    fout << "Player Name: " << p.Name() << ", Weapon Name: " << p.weaponName() << ", Weapon Damage: " << p.weaponDamage() << endl;
    fout << "Melee Weapon: " << p.meeleName() << ", Melee Damage: " << p.meeleDamage() << ", Health shots remaining: " << p.healthShots() << endl;
    fout << endl;
    
}

//Main play game function
void play(player *p1, player *p2)
{
    //Fetching current time
    time_t now = time(0);
    char* dt = ctime(&now);
    
    //Starting filestream. Create a new games.txt if it doesn't exist and if it does, append the new data at the end.
    ofstream fout;
    fout.open("games.txt", ios::out | ios::app);

    //Add file 
    fout<<"Game start time: "<<dt<<endl;

    cout << "Lets begin the game. Type w for using weapon, m for using melee weapon and h for using a health shot \n";

    int currentPlayer = 0;
    int nextPlayer = 1;

    //Declaring an array which will host both the players' statistics for easy retrieval during the loop below
    player playersAr[2];
    playersAr[0] = *p1;
    playersAr[1] = *p2;

    //Loop the game till one of the player wins
    while (playersAr[0].getHealth() > 0 && playersAr[1].getHealth() > 0)
    {
        cout << "\nPlayer stats are as follows: \n\n";
        printPlayer(playersAr[0], 1, fout);
        printPlayer(playersAr[1], 2, fout);

    start:
        cout << "\nYour turn player " << playersAr[currentPlayer].Name() << ". Type w (weapon) / h (health shot) / m (melee weapon): ";
        char choice;
        cin >> choice;

        //Switch depending on the move
        switch (choice)
        {
        case 'w':
            cout << "Weapon Used " << playersAr[currentPlayer].weaponName() << endl;
            fout << "Weapon Used " << playersAr[currentPlayer].weaponName() << endl;
            playersAr[nextPlayer].damageDone(playersAr[currentPlayer].weaponDamageRandom(), fout);
            break;
        case 'm':
            cout << "Melee Weapon Used " << playersAr[currentPlayer].meeleName() << endl;
            fout << "Melee Weapon Used " << playersAr[currentPlayer].meeleName() << endl;
            playersAr[nextPlayer].damageDone(playersAr[currentPlayer].meeleDamageRandom(), fout);
            playersAr[currentPlayer].damageTaken((playersAr[currentPlayer].meeleDamageRandom()), fout);
            break;
        case 'h':
            if (playersAr[currentPlayer].getHealth())
            {
                playersAr[currentPlayer].healthRestored(playersAr[currentPlayer].healthRepair(), fout);
            }
            else
            {
                cout << "No more health shots remaining. Try again" << endl;
                goto start;
            }
            break;
        default:
            cout << "Input error. Try again" << endl;
            goto start;
        }

        //Switch current player and next player after the move of the current player.
        if (currentPlayer == 0)
        {
            nextPlayer = 0;
            currentPlayer = 1;
        }
        else
        {
            currentPlayer = 0;
            nextPlayer = 1;
        }
    }

    //Declare winner and also output the same in the file.
    string winner = ((playersAr[0].getHealth() > playersAr[1].getHealth()) ? playersAr[0].Name() : playersAr[1].Name());
    cout << "Player " << winner << " won the game. " << endl;
    fout << "Player " << winner << " won the game. " << endl;
    fout << endl <<endl<<endl<<endl<<endl;
    fout.close();
}