#include<iostream>
#include "player.h"

using namespace std;

void printPlayer(player p1, int i){
        cout<<"Player Number: "<<i<<", Health: "<<p1.getHealth()<<endl;
        cout << "Player Name: " << p1.Name() << ", Weapon Name: " << p1.weaponName() << ", Weapon Damage: " << p1.weaponDamage() << endl;
        cout << "Meele Weapon: " << p1.meeleName() << ", Meelee Damage: " <<p1.meeleDamage() <<", Health shots remaining: "<<p1.healthShots()<<endl;
        cout << endl;
}

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