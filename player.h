#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

class player {

  private:

    string name; //Character Name
    string meele_name; // Meele Weapon Name
    int meele_damage; //Average Meele Damage
    int weapon_damage; //Average Weapon Damage
    string weapon_name; // Weapon Name
    int health= 100; //Max Health
    int health_shots = 3; // Total number of health shots
    int health_shot_repair = 20; //Repair with each health shot

  public:

    // Default Constructor
    player() {
        name = " ";
        meele_name =" ";
        meele_damage = 0;
        weapon_damage = 0;
    }

    // Initalise the character with a character from the character list
    player(string nameM, string meelee_nameM, string weapon_nameM,int meele_damageM, int weapon_damageM){
        name = nameM;
        weapon_name = weapon_nameM;
        meele_name = meelee_nameM;
        meele_damage = meele_damageM;
        weapon_damage = weapon_damageM;
    }

    //Returns name of the Character
    string Name(){
      return name;
    }

    //Returns name of the Meele Weapon
    string meeleName(){
      return meele_name;
    }

    //Returns name of the Main Weapon
    string weaponName(){
      return weapon_name;
    }

    //Returns Average Damage of the Meele Weapon
    int meeleDamage(){
      return meele_damage;
    }

    //Returns Average damage of the Main Weapon
    int weaponDamage(){
      return weapon_damage;
    }

    //Returns the calculated random Meele Damage
    int meeleDamageRandom(){
      return ((rand()%11+(meele_damage-5)));
    }

    
    //Returns the calculated random Main Weapon Damage
    int weaponDamageRandom(){
      return ((rand()%11+(weapon_damage-5)));
    }

    
    //Returns the Number of health shots
    int healthShots(){
      return health_shots;
    }

    
    //Returns the calculated random Health Restore
    int healthRepair(){
      return ((rand()%11+(health_shot_repair-5)));
    }

  
    //Returns the Total health
    int getHealth(){
      return health;
    }

    
    //changes health according to the damage done
    void damageDone(int damage, ofstream &fout){
      cout<<"Damage Inflicted "<<damage<<endl;
      fout<<"Damage Inflicted "<<damage<<endl;
      health -= damage;
    }

    //Also changes health according to the damage done but outputs "damage taken" instead of "damage inflicted"
    //Used mainly for self damage when using Melee Weapon
     void damageTaken(int damage, ofstream &fout){
      cout<<"Damage Taken "<<int((0.4)*damage)<<endl;
      fout<<"Damage Taken "<<int((0.4)*damage)<<endl;
      health -= (0.4)*damage;
    }

    //Restores health
    void healthRestored(int healthN, ofstream &fout){
      if (health+healthN >100){
        health = 100;
      } else {
        health += healthN;
      }
      cout<<"Health Restored to "<<health<<endl;
      fout<<"Health Restored to "<<health<<endl;
      health_shots -= 1;
    }

    
};

#endif
