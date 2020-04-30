#include <iostream>
#include <fstream>
#include "player.h"

using namespace std;

void printPlayer(player p, int i, ofstream &fout){
    cout << "Player Number: " << i << ", Health: " << p.getHealth() << endl;
    cout << "Player Name: " << p.Name() << ", Weapon Name: " << p.weaponName() << ", Weapon Damage: " << p.weaponDamage() << endl;
    cout << "Meele Weapon: " << p.meeleName() << ", Meelee Damage: " << p.meeleDamage() << ", Health shots remaining: " << p.healthShots() << endl;
    cout << endl;

    fout << "Player Number: " << i << ", Health: " << p.getHealth() << endl;
    fout << "Player Name: " << p.Name() << ", Weapon Name: " << p.weaponName() << ", Weapon Damage: " << p.weaponDamage() << endl;
    fout << "Meele Weapon: " << p.meeleName() << ", Meelee Damage: " << p.meeleDamage() << ", Health shots remaining: " << p.healthShots() << endl;
    fout << endl;
    
}

void play(player *p1, player *p2)
{
    time_t now = time(0);
    char* dt = ctime(&now);
    ofstream fout;
    fout.open("games.txt", ios::out | ios::app);

    fout<<"Game start time: "<<dt<<endl;

    cout << "Lets begin the game. Type w for using weapon, m for using meele weapon and h for using a health shot \n";

    int currentPlayer = 0;
    int nextPlayer = 1;

    player playersAr[2];
    playersAr[0] = *p1;
    playersAr[1] = *p2;
    while (playersAr[0].getHealth() > 0 && playersAr[1].getHealth() > 0)
    {
        cout << "\nPlayer stats are as follows: \n\n";
        printPlayer(playersAr[0], 1, fout);
        printPlayer(playersAr[1], 2, fout);

    start:
        cout << "\nYour turn player " << playersAr[currentPlayer].Name() << ". Type w (weapon) / h (health shot) / m (meele weapon): ";
        char choice;
        cin >> choice;

        switch (choice)
        {
        case 'w':
            cout << "Weapon Used " << playersAr[currentPlayer].weaponName() << endl;
            fout << "Weapon Used " << playersAr[currentPlayer].weaponName() << endl;
            playersAr[nextPlayer].damageDone(playersAr[currentPlayer].weaponDamageRandom(), fout);
            break;
        case 'm':
            cout << "Meele Weapon Used " << playersAr[currentPlayer].meeleName() << endl;
            fout << "Meele Weapon Used " << playersAr[currentPlayer].meeleName() << endl;
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

    string winner = ((playersAr[0].getHealth() > playersAr[1].getHealth()) ? playersAr[0].Name() : playersAr[1].Name());
    cout << "Player " << winner << " won the game. " << endl;
    fout << "Player " << winner << " won the game. " << endl;
    fout << endl <<endl<<endl<<endl<<endl;
    fout.close();
}