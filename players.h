#include<iostream>

using namespace std;
class players
{
  public:
  //to define the players

    int player_number[5];
    string name[5];
    string meele_name[5];
    int meele_damage[5];
    int weapon_damage[5];
    string weapon_name[5];
    int health_shots = 3;
    int health_shot_repair = 20;
  
    players()
      {
        player_number[0]=1;
        name[0]="Pentheus";
        meele_name[0]= "Knife";
        weapon_damage[0] =15;
        meele_damage[0] = 20;
        weapon_name[0]= "MP-15";
        
        player_number[1]=2;
        name[1]="Phylon";
        meele_name[1]="Hammer";
        weapon_damage[1] = 18;
        meele_damage[1] = 17;
        weapon_name[1]="Ak-47";

        player_number[2]=3;
        name[2]="Gorgo";
        meele_name[2]="Arrow";
        weapon_damage[2] =17;
        meele_damage[2] = 17;
        weapon_name[2]="P90";

        player_number[3]=4;
        name[3]="Xerxes";
        meele_name[3]="Axe";
        weapon_damage[3] =13;
        meele_damage[3] = 24;
        weapon_name[3]="Famas";

        player_number[4]=5;
        name[4]="Ellas";
        meele_name[4]="Galil_AR";
        weapon_damage[4] = 22;
        meele_damage[4] = 18;
        weapon_name[4]="Blades";
      }

};
