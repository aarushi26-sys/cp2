#include<iostream>
#include<stdlib.h>
#include "players.h"
#include "player.h"

using namespace std;

void showGameRules() {

}

void showPlayers(players players_list) {

    cout<<"Choose your Player: \n\n";

    for (int i = 0; i < 5; i++){
        cout<<"Player Number: "<<i+1<<endl;
        cout<<"Player Name: "<<players_list.name[i]<<", Weapon Name: "<<players_list.weapon_name[i]<<", Weapon Damage: "<<players_list.weapon_damage[i]<<endl;
        cout<<"Meele Weapon: "<<players_list.meele_name[i]<<", Meelee Damage: "<<players_list.meele_damage[i]<<endl;
        cout<<endl;
    }
}


int main(){
    //Clearing Screen 
 
    //Display Game Rules
    showGameRules();


    //Display Player List 
    players players_list;
    showPlayers(players_list);
    cout<<"Press any key to continue ";
    cin.get();
  

}