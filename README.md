[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8880561&assignment_repo_type=AssignmentRepo)

# Monster Slayer
 
Malachi Ambra (https://github.com/GrizzlyMachi) <br />
Michelle Choi (https://github.com/mchoi084) <br />
Dennis Santoso (https://github.com/dennissantoso) <br />
Chaiwat Wongsatjachock (https://github.com/supergoodham) <br />

Importance: As college students, we like to have a outlet to relax after a long day of class and work. The usual outlets ranges from gaming to execrising. So as a group, we decided to create a game since it provides us with a challenge and it is something that can always have more features. It is a nice project to show others when they ask about our work and it is always more engaging when you create something you like.<br />

Tools: We are planning on using C++ and VS Studio Codes to implement the game. <br />

Features: some features that will be implemented in C++ are the storyline, variety of weapons and armors, boss fights and ways to get stronger, etc. Since our game is a fantasy medieval-themed game, our storyline gives background, and the game's goal is to kill the final boss after going through some mini-bosses to increase the player's stats. We have a variety of weapons and armors that you can get from defeating monsters. The boss fight is the final boss of the game and is a dragon after defeating the dragon, you will win the game and finish the story. Ways to get stronger are to defeat monsters and gain weapons to help increase stats against monsters. <br />

Inputs: The inputs are the user inputs but we will have options for them to choose from. <br />
- Status commands like checking status, etc
- An option to choose whether they want to grind, heal, or navigate to the next boss <br />
- Battle State commands (attack and run) <br />

Outputs: Depends are what the input the player choses. <br />
- Environmental descriptions <br />
- Battle information (attacking, running away, etc) <br />
- Story / dialogue <br />

Instructions to run the game:
1. Clone the repository by accessing the HTTPS url in the top right green button that says <>code. <br />
2. Once you have clone the repository, you will open a new terminal. <br />
3. Inputs to run game: <br />
``cmake . `` <br />
``make`` <br />
``./run`` <br />
4. Enjoy the game! <br />

Install Cmake on computer to run <br />
*This game only runs on the cs100 server (SSH) <br />

## UML Diagram

<img src="https://i.imgur.com/G1TWR79.png"><br>

Link to Wireframe: https://www.figma.com/file/NYmO4THujHkwBGHEJss6yN/CS100-Final-Project?node-id=0%3A1 <br />

<img src="https://i.imgur.com/WCvK2y5.jpg"><br>

Link to Demo the Wireframe: https://www.figma.com/proto/NYmO4THujHkwBGHEJss6yN/CS100-Final-Project?node-id=413%3A25&scaling=min-zoom&page-id=0%3A1&starting-point-node-id=413%3A25&show-proto-sidebar=1 <br />


Description...
- Starting with the game class, it will hold the sequence of events, particularly the story, as well as serve as the container for the rest of the classes and functions needed to get the game running. It will define the save and load functions, which will then be accessible via the adventure menu. The Game class has access to both the Monster and Item classes through using includes.
- The game class holds each of the main 3 zones, forest, cave, and mountain. As well as the print functions for story exposition associated with said zones. This will also have the player function inside since the zones are where the player actually plays the game. It makes sure that after each boss fight, the next zone function is called, placing the player into the next region with the proper story dialogue.
- At the beginning of the game, the Game class will set up a player creation and a tutorial to introduce the player to the game. 
- The player class contains the player's name, health, damage, current weapon, current armor, location, lives, and health.
- The player class has access to the adventure menu in the Game class, which is what is displayed for each region after progressing through the storyline. This menu is where the player has actual choices, such as: grinding mobs for loot, navigating (or progressing) to the mini-boss of the region, healing (only available 3 times per zone), stats (prints out character stats), and saving the game (they can also quit).
- The grind option in the adventure menu leads to a separate battle menu in the Game class. This will be a relatively simple action menu, that allows the player to either attack or run (running is useful in case you don't want to die). The attack function here is done in the Game class. 
- The last class the player has access to (as well as the Monster class), is the Item class. This class will hold the items to be found in the game, weapons or armor. Weapons will be given a unique ID, as well as armor, which will all be defined in the Item class. Monster class has access to the Items as well since they have a chance of dropping them via RNG.
- The Monster class contains both the boss and regular monster, their health, damage, and drop chance. There is a system where there is a variation of the random enemy type that is done by reading a text file and applying a modifier to the base monster.  

## Valgrind Memory Leaks

<img src="https://i.imgur.com/U0N1RBs.png"><br>
-----------------------------------------------
<img src="https://i.imgur.com/36jyPuF.png"><br>

## Game Walkthrough

<img src="https://i.imgur.com/VZY5HdN.png"><br>
-----------------------------------------------
<img src="https://i.imgur.com/JNC93LG.png"><br>
-----------------------------------------------
<img src="https://i.imgur.com/ILbo2CX.png"><br>
-----------------------------------------------
<img src="https://i.imgur.com/Lu8ARC1.png"><br>
-----------------------------------------------
<img src="https://i.imgur.com/YQVskrN.png"><br>
-----------------------------------------------
<img src="https://i.imgur.com/2lkCYW0.png"><br>
-----------------------------------------------
<img src="https://i.imgur.com/KJT16wI.png"><br>
-----------------------------------------------
<img src="https://i.imgur.com/Sz54Vre.png"><br>
-----------------------------------------------
<img src="https://i.imgur.com/2rcUiBM.png"><br>
-----------------------------------------------
<img src="https://i.imgur.com/OMtNb88.png"><br>
-----------------------------------------------
<img src="https://i.imgur.com/jRBZrX1.png"><br>
-----------------------------------------------
<img src="https://i.imgur.com/llRQSuu.png"><br>
-----------------------------------------------
<img src="https://i.imgur.com/z1goctU.png"><br>
