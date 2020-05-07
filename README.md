# Spartans 
### ENGG1340/COMP2113 @ HKU C++ Text Based Game Project
------------
### Team Members ###
- [Aarushi Goyal](https://github.com/aarushi26-sys "Aarushi Goyal") (BEng)
UID-3035709162
- [Mithil Aggarwal](http://github.com/dotus "Mithil Aggarwal")  (BEng) 
UID- 3035661724
------------
### Game Description ###
Spartans is a text based 2-player text-based combat and strategy game. Each player chooses one role out of a total of 5 at the starting of the game and is given a particular gun, a melee weapon and a number of health shots which are predefined with the factors. Each player role is balanced with different gun damages and melee damages. Players will use their weapons/health shots alternatively and the player who is able to eliminate the other player wins.

------------

### Rules ###
                
1. Each player will have *100* health points.
2. There are *5 character choices* within the game each with a different primary gun and a melee weapon.
3. All weapons (including the melee weapons) have *different damages*.
4. Melee weapons also cost the player using them 40% of the damage the weapon inflicts.
5. Each player will also get a total of 3 health shots which restore health *upto 25 points*, i.e: within the range of 15-25. 
6. Only *one* weapon/health shot can be used in a move. 
7. The character selection screen lists the *average* meelee and main weapon damage. The actual damage inflicted will be in the range of +- 5 of the listed value.
8. The first player to get the other player's health down to *zero* wins.
9. All the Game Records will be stored in games.txt along with the timestamp of each game.


------------

### List of features/functions
- Generation of random game sets or events 
  > As stated in Rule #7, the actual damage done will be in the range of the +-5 of the listed value. To accomplish this we've used the random function. Similarly, for the health shots, the health points repaired will be determined randomly in the range of 15-25. 
- Data structures for storing game status
  > We have used mainly two classes: **players** and **player**. The former is just a container class which contains details about all the 5 roles. We then created two items (p1, p2) of the **player** class which contain the details of the actual chosen role by the players and more details like the remaining health. Upon choosing the roles, the unique attributes (weapon name, average damage, etc) are copied to p1 and p2 using a constructor in the **player** class. To facilitate the entire game, we implemented multiple functions within the class to mainpulate and return the values of the variables like health, number of health shots, etc. 
- Dynamic memory management
  > This feature has been used to allocate the memory dynamically for the objects of the **player** class (p1, p2).
- File input/output (e.g., for loading/saving game status)
  > File I/O has been used to create a file named **games.txt**. This files contains all the past game records including the statistics of each round. Each game's record starts with a timestamp so that the user can find a particular record. This is useful for the cases in which a user might want to go through the past games that were played.
- Program codes in multiple files
  > Functions like play(), printPlayer() are defined in another file called play.cpp
  > The two classes, **players** and **player** are defined in separate header files.

------------

### Compilation and Execution Instructions
- A Makefile has already been made. To compile the entire code, simply type `make game`. To clean the files, i.e: remove the compiled files, simply type `make clean`.
- After the compilation is successful run `./game` in the terminal to execute the game.
- To choose weapon, use the letters 'w' (main weapon) / 'h' (health shot) / 'm' melee weapon. To proceed through different menus, press the 'Enter' key as instructed in the game.

- [Explanation Video Here](https://drive.google.com/file/d/1xU6E19GuDN4hBc2hjzlCsKvK4v21ZDHd/view?usp=sharing "Explanation Video Here")

