#include<iostream>
#include<cstdlib>

using namespace std;

class player {

  private:

    string name;
    string meele_name;
    int meele_damage;
    int weapon_damage;
    string weapon_name;
    int health_shots = 3;
    int health_shot_repair = 20;

  public:

    player(string nameM, string meelee_nameM, int meele_damageM, int weapon_damageM){
        name = nameM;
        meele_name = meelee_nameM;
        meele_damage = meele_damageM;
        weapon_damage = weapon_damageM;
    }

    string Name(){
      return name;
    }
    string meeleName(){
      return meele_name;
    }
    string weaponName(){
      return weapon_name;
    }
    int meeleDamage(){
      return ((rand()%meele_damage+5)+(meele_damage-5));
    }
    int weaponDamage(){
      return ((rand()%weapon_damage+5)+(weapon_damage-5));
    }
    int healthShots(){
      return health_shots;
    }
    int healthRepair(){
      return ((rand()%health_shot_repair+5)+(health_shot_repair-5));
    }

    
};