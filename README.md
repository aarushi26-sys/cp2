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
Spartans is a text based 2-player text-based combat and strategy game. Each player chooses roles at the starting of the game and is given a particular gun, a melee weapon and a number of health shots which are predifined with the factors. Each player role is balanced with different gun damages and melee damages. Players will use their weapons/health shots alternatively and the player who is able to eliminate the other player wins.

------------

### Rules ###

-  Each player will have *100* health points.
-  There are *5 character choices* within the game each with a different primary gun and a melee weapon.
-  All weapons (including the melee weapons) have *different damages*.
-  Melee weapons also cost the player using them 40% of the damage the weapon inflicts.
-  Each player will also get a total of 3 health shots which restore health *upto 25 points*, i.e: within the range of 15-25. 
-  Only *one* weapon/health shot can be used in a move. 
-  The character selection screen lists the *average* meelee and main weapon damage. The actual damage inflicted will be in the range of +- 5 of the listed value.
-  The first player to get the other player's health down to *zero* wins.
-  All the Game Records will be stored in games.txt along with the timestamp of each game.


------------

### List of features/functions
- Generation of random game sets or events 
  > Random function for determining the damages caused by each weapon and also the calculation of the actual restored health.
- Data structures for storing game status
  > Data structures like classes to store the info about the characters and each player.
- Dynamic memory management
  > This feature will be used to allocate the memory of the real time input of the players and the information of the character chosen by the player.
- File input/output (e.g., for loading/saving game status)
  > File I/O will be used to save the game records.
- Program codes in multiple files
  > Functions like play() are stored in another file called file.cpp
  > Character class and also the player class are stored in separate files.

------------

### Compilation and Execution Instructions
- A Makefile has already been made. To compile the entire code, simply type `make game`. To clean the files, i.e: remove the compiled files, simply type `make clean`.
- After the compilation is successful run `./game` in the terminal to execute the game.
- To choose weapon, use the letters 'w' (main weapon) / 'h' (health shot) / 'm' melee weapon. To proceed through different menus, press the 'Enter' key as instructed in the game.
