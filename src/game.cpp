#include "../header/game.h"

Game::Game() {
    playerChoice = 0;
    gameStatus = 1;
    characterAvailable = 0;
    zoneCompleted = 0;
    quit = false;
}

Game::~Game() {
}

void Game::gameSequence() {
    cout << "Going into game sequence with:" << endl;
    cout << "gameStatus = " << getGameStatus() << endl;
    cout << "quit = " << quit << endl;
    while (getGameStatus()) {
        Player p1;
        // p1.initializePlayer("Machi");
        // monsterEncounter(p1, "Goblin");
        mainMenu(p1);
        // while (!(getCharacterAvailable())) {
        //     mainMenu(p1);
        // }
        // If-checks to load character into proper zone
        // If no load, then regular will execute in sequence
        if (p1.getCurrentLocation() == 0) {
            startGame(p1);
            intro(p1);
            p1.setCurrentLocation(1);
        }
        if (p1.getCurrentLocation() == 1) {
            Forest(p1);
            if (quit == false) {
                p1.setCurrentLocation(2);
            }
        }
        if (p1.getCurrentLocation() == 2) {
            Cave(p1);
            if (quit == false) {
                p1.setCurrentLocation(3);
            }
        }
        if (p1.getCurrentLocation() == 3) {
            Mountain(p1);
        }
        if (quit == false) { //If they reached here without quitting then they beat the game
            cout << "You beat the game. Yay" << endl;
            // cout << "Your final zone was: " << p1.getCurrentLocation() << endl << endl;
            cout << "⠄⠄⠄⠄⠄⠄⣀⣀⣀⣤⣶⣿⣿⣶⣶⣶⣤⣄⣠⣴⣶⣿⣿⣿⣿⣶⣦⣄⠄⠄  \n" << 
                    "⠄⠄⣠⣴⣾⣿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦  \n" << 
                    "⢠⠾⣋⣭⣄⡀⠄⠄⠈⠙⠻⣿⣿⡿⠛⠋⠉⠉⠉⠙⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿  \n" << 
                    "⡎⣾⡟⢻⣿⣷⠄⠄⠄⠄⠄⡼⣡⣾⣿⣿⣦⠄⠄⠄⠄⠄⠈⠛⢿⣿⣿⣿⣿⣿  \n" << 
                    "⡇⢿⣷⣾⣿⠟⠄⠄⠄⠄⢰⠁⣿⣇⣸⣿⣿⠄⠄⠄⠄⠄⠄⠄⣠⣼⣿⣿⣿⣿  \n" << 
                    "⢸⣦⣭⣭⣄⣤⣤⣤⣴⣶⣿⣧⡘⠻⠛⠛⠁⠄⠄⠄⠄⣀⣴⣿⣿⣿⣿⣿⣿⣿  \n" << 
                    "⠄⢉⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣦⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿  \n" << 
                    "⢰⡿⠛⠛⠛⠛⠻⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿  \n" << 
                    "⠸⡇⠄⠄⢀⣀⣀⠄⠄⠄⠄⠄⠉⠉⠛⠛⠻⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿  \n" << 
                    "⠄⠈⣆⠄⠄⢿⣿⣿⣿⣷⣶⣶⣤⣤⣀⣀⡀⠄⠄⠉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿  \n" << 
                    "⠄⠄⣿⡀⠄⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠂⠄⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿  \n" << 
                    "⠄⠄⣿⡇⠄⠄⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠄⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿  \n" << 
                    "⠄⠄⣿⡇⠄⠠⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠄⠄⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿  \n" << 
                    "⠄⠄⣿⠁⠄⠐⠛⠛⠛⠛⠉⠉⠉⠉⠄⠄⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿  \n" << 
                    "⠄⠄⠻⣦⣀⣀⣀⣀⣀⣀⣤⣤⣤⣤⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠄    " << endl << endl;
            gameStatus = 0;
        }
    }
}

void Game::mainMenu(Player &p1) {
    bool finished = 0;

    // Do-While Statement just to catch any invalid NUMBERS, let's us loop the menu
    do {
        system("clear");
        cout << "   __    __   ____     __      _ _____ ________ ___________      _____ _____      ______      _____________    " << endl;
        cout << "   \\ \\  / /  / __ \\   /  \\    / ) ____(___  ___) ___(   __ \\    / ____(_   _)    (    ) \\    / ( ___(   __ \\   " << endl;
        cout << "   () \\/ () / /  \\ \\ / /\\ \\  / ( (___     ) ) ( (__  ) (__) )  ( (___   | |      / /\\ \\  \\  / ( (__  ) (__) )  " << endl;
        cout << "   / _  _ \\( ()  () )) ) ) ) ) )\\___ \\   ( (   ) __)(    __/    \\___ \\  | |     ( (__) )\\ \\/ / ) __)(    __/   " << endl;
        cout << "  / / \\/ \\ ( ()  () | ( ( ( ( (     ) )   ) ) ( (    ) \\ \\  _       ) ) | |   __ )    (  \\  / ( (    ) \\ \\  _  " << endl;
        cout << " /_/      \\_\\ \\__/ // /  \\ \\/ / ___/ /   ( (   \\ \\__( ( \\ \\_))  ___/ /__| |___) )  /\\  \\  )(   \\ \\__( ( \\ \\_)) " <<endl;
        cout << "(/          \\)____/(_/    \\__/ /____/    /__\\   \\____)_) \\__/  /____/ \\________/__(  )__\\/__\\   \\____)_) \\__/  " << endl;
        cout << "---------------------------------------------------------------------------------------------------------------" << endl << endl;

        cout << "1. New Game" << endl;
        cout << "2. Load" << endl;
        cout << "3. Quit" << endl;
        cout << endl << "Choice: ";
        cin >> playerChoice;

        // While loop catches any invalid LETTERS and loops until a number is inputted
        while (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            system("clear");

            cout << "   __    __   ____     __      _ _____ ________ ___________      _____ _____      ______      _____________    " << endl;
            cout << "   \\ \\  / /  / __ \\   /  \\    / ) ____(___  ___) ___(   __ \\    / ____(_   _)    (    ) \\    / ( ___(   __ \\   " << endl;
            cout << "   () \\/ () / /  \\ \\ / /\\ \\  / ( (___     ) ) ( (__  ) (__) )  ( (___   | |      / /\\ \\  \\  / ( (__  ) (__) )  " << endl;
            cout << "   / _  _ \\( ()  () )) ) ) ) ) )\\___ \\   ( (   ) __)(    __/    \\___ \\  | |     ( (__) )\\ \\/ / ) __)(    __/   " << endl;
            cout << "  / / \\/ \\ ( ()  () | ( ( ( ( (     ) )   ) ) ( (    ) \\ \\  _       ) ) | |   __ )    (  \\  / ( (    ) \\ \\  _  " << endl;
            cout << " /_/      \\_\\ \\__/ // /  \\ \\/ / ___/ /   ( (   \\ \\__( ( \\ \\_))  ___/ /__| |___) )  /\\  \\  )(   \\ \\__( ( \\ \\_)) " <<endl;
            cout << "(/          \\)____/(_/    \\__/ /____/    /__\\   \\____)_) \\__/  /____/ \\________/__(  )__\\/__\\   \\____)_) \\__/  " << endl;
            cout << "---------------------------------------------------------------------------------------------------------------" << endl << endl;

            cout << "1. New Game" << endl;
            cout << "2. Load" << endl;
            cout << "3. Quit" << endl;
            cout << endl << "Choice: ";
            cin >> playerChoice;
        }

        switch(playerChoice) {
            case 1: // New Game
                system("clear");
                cout << "Starting a New Game..." << endl;
                continueScreen();
                characterAvailable = 1;
                finished = 1;
                break;

            case 2: // Loading Game
                system("clear");
                loadCharacter(p1);
                cout << "Loaded Character" << endl;
                continueScreen();
                characterAvailable = 1;
                finished = 1;
                break;

            case 3: // Exit
                exit(0);
                finished = 1;
                break;

            default:
                break;
        }
    } while(!finished);
}

void Game::startGame(Player &p1) {
    cin.clear();
    string name;
    cout << "Welcome to Monster Slayer! What is your name?" << endl;
    cin >> name;
    cout << endl << "Nice to meet you, " << name << endl;
    p1.initializePlayer(name);
    continueScreen();
}

void Game::intro(Player &p1) {
    cout << "You are the chosen one. You are the only one who can kill the ancient dragon, Dragamor. It has been terrorizing the kingdom." << endl; 
    cout << "We need your help. You can find Dragamor at the top of Dazu Mountain. It is a long journey. Brace yourself." << endl;
    cout << "You will need to go through the Enchanted Forest, then go through the Frozen Caves before being able to reach Dazu Mountain." << endl; 
    cout << "Always be careful. You never know what monsters you might encounter." << endl;
    continueScreen();
    tutorial(p1);
}

void Game::tutorial(Player &p1) {
    cout << "Welcome to the tutorial." << endl;
    continueScreen();
    cout << "Here are your current stats:" << endl;
    p1.printStats();
    continueScreen();
    cout << "You are given 3 lives and 3 heals that brings you back to max health. " << endl;
    cout << "When you reach a new region you will gain a live if you have less than 3. If you lose all 3 lives, it is GAME OVER." << endl;
    continueScreen();
    cout << "You have been gifted a crumby wooden sword and leather chestplate by the gods to use against any incoming foes." << endl;
    continueScreen();
    cout << "For every region, a whopping 3 of them, you'll have the option to grind monsters." << endl;
    cout << "Each region has their own monsters, goblins in the forest, ogres in the cave, and sentinels dwelling within the mountain." << endl;
    continueScreen();
    cout << "Upon each instance of grinding a monster, you'll notice a sort of prefix preceding the monster type." << endl;
    continueScreen();
    cout << "Depending on the type of prefix, the monster may be harder (have more health and do more damage)..." << endl;
    cout << "You'll have to figure out which prefixes make the monster more difficult through trial and error." << endl;
    continueScreen();
    cout << "But fret not! The harder a monster is, the higher chance you have a getting better loot!" << endl;
    cout << "On the topic of loot, there are 3 tiers per region, ranging from 1-3. Tier 3 being the best item for that region!" << endl;
    continueScreen();
    cout << "It's important to keep an eye out for what tier was dropped while grinding! Each tier has a weapon or armor to be had for that region." << endl;
    cout << "So keep an eye out for whether or not you've already obtained the best items for that region!" << endl;
    continueScreen();
    cout << "Lastly, the objective is to become strong enough through obtaining items via grinding which modify your damage and health!" << endl;
    cout << "Once you've done enough grinding and feel that you are ready to progress, you will face a mini-boss before you can enter the next region!" << endl;
    cout << "Do this until you reach the final boss, and you will have won the game!" << endl;
    continueScreen();
    cout << "Speak of the devil! Here's an incoming malnourished slime attempting to ruffle your feathers!" << endl;
    continueScreen();
    
    monsterEncounter(p1, "Slime");

    cout << "Congrats! You managed to not get killed by the slime!" << endl;
    cout << "You now officially know how to kill monsters!" << endl;
    cout << "Now... Onto the main game!" << endl;
    p1.setCurrentHealth(26);
    continueScreen();
}

void Game::Forest(Player &p1) {
    cout << " /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ \n"
            " /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ \n"
            " /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\   " << endl;
    cout << "You have reached the Enchanted Forest. As you walk towards the forest your surrounding slowly changes. "<< endl;
    cout << "All the trees slowly turn from the luscious green into a bright blue trees. You look around in awe but still concious of your surroudings." << endl;
    cout << "You suddenly remember that the Dark Elf lives in the Enchanted Forest and he will definitely try to stop you from getting to Dragamor." << endl;
    cout << "You marched on and continued through the forest until you reached a clearing..."<< endl;
    cout << "This looks to be a perfect place to set up camp." << endl;

    continueScreen();
    Zone1(p1);

    if (quit == true) {
        cout << "Quitting to main menu..." << endl;
        continueScreen();
        return;
    }

    cout << "Upon reaching the entrance, Seymour the Dark Elf stops your advancement." << endl;
    cout << "Dark Elf: How dare you intrude my forest and hurt my subjects." << endl << 
        "This is why your kingdom deserves to be taunted by the great Dragamor. You will never defeat him. *Laughs*" << endl << 
        "It is not like you can defeat me." << endl;

    continueScreen();
    monsterEncounter(p1, "Seymour");

    cout << "You curb stomped Seymour. Big props." << endl;

    if (p1.getLives() < 3) {
        p1.setLives(p1.getLives() + 1);
    }
    if(p1.getHeals() < 3) {
        p1.setHeals(3);
    }
    continueScreen();
}

void Game::Cave(Player &p1) {
    zoneCompleted = 0;
    cout << "                     /   \\              /'\\       _                                \n" <<
            " \\_..           /'.,/     \\_         .,'   \\     / \\_                            \n" <<
            "     \\         /            \\      _/       \\_  /    \\    _                      \n" <<
            "      \\__,.   /              \\   /           \\/.,   _|  _/ \\                     \n" <<
            "          \\_/                \\  /',.,''\\      \\_ \\_/  \\/    \\                 \n" <<
            "                            _  \\/   /    ',../',.\\    _/      \\                   \n" <<
            "              /           _/m\\  \\  /    |         \\  /.,/'\\   _\\                \n" <<
            "           _/           /MMmm\\  \\_     |          \\/      \\_/  \\                \n" <<
            "          /      \\     |MMMMmm|   \\__   \\          \\_       \\   \\_             \n" <<
            "                  \\   /MMMMMMm|      \\   \\           \\       \\    \\            \n" <<
            "                   \\  |MMMMMMmm\\      \\___            \\_      \\_   \\           \n" <<
            "                    \\|MMMMMMMMmm|____.'  /\\_            \\       \\   \\_          \n" <<
            "                    /'.,___________...,,'   \\            \\   \\        \\          \n" <<
            "                   /       \\          |      \\    |__     \\   \\_       \\        \n" <<
            "                 _/        |           \\      \\_     \\     \\    \\       \\_     \n" <<
            "                /                               \\     \\     \\_   \\        \\     \n" <<
            "                                                 \\     \\      \\   \\__      \\    \n" <<
            "                                                  \\     \\_     \\     \\      \\   \n" <<
            "                                                   |      \\     \\     \\      \\   \n" <<
            "                                                     \\           |            \\      " << endl;
    cout << "After many fights and continous walking...." << endl;
    cout << "You have reached the Frozen Caves. The chilly cave made your hairs stand up as you grabbed a torch to light the way. "<< endl;
    cout << "You can hear the fire crackle as it flickers and drops of water hitting the ground echo through the cave. You stay alert for any movement." << endl;
    cout << "You suddenly remember that the Giant Orge lives in the Frozen Caves and he will definitely try to stop you from getting to Dragamor" << endl;
    cout << "You marched on and continued through the caves until reaching a domed region."<< endl;
    cout << "Perfect place for camp." << endl;

    continueScreen();
    Zone2(p1);

    if (quit == true) {
        cout << "Quitting to main menu..." << endl;
        continueScreen();
        return;
    }

    cout << "Before you can exit the cave, a big ogre grabs you by the thigh." << endl;

    continueScreen();
    monsterEncounter(p1, "Obbo");

    cout << "Obbo got major deathed. Congrats." << endl;

    if (p1.getLives() < 3) {
        p1.setLives(p1.getLives() + 1);
    }
    if(p1.getHeals() < 3) {
        p1.setHeals(3);
    }
    continueScreen();
}

void Game::Mountain(Player &p1) {
    zoneCompleted = 0;
    cout << "   .                  .-.    .  _   *     _   . \n" <<
            "          *          /   \\     ((       _/ \\       *    . \n" <<
            "        _    .   .--'\\/\\_ \\     `      /   \\  *    ___ \n" <<
            "    *  / \\_    _/ ^      \\/\'__        /\\/\\  /\\  __/   \\ * \n" <<
            "      /    \\  /    .'   _/  /  \\  *' /    \\/  \\/ .`'\\_/\\   . \n" <<
            " .   /\\/\\  /\\/ :' __  ^/  ^/    `--./.'  ^  `-.\\ _    _:\\ _ \n" <<
            "     /    \\/  \\  _/  \\-' __/.' ^ _   \\_   .'\\   _/ \\ .  __/ \\ \n" <<
            "   /\\  .-   `. \\/     \\ / -.   _/ \\ -. `_/   \\ /    `._/  ^  \\ \n" <<
            "  /  `-.__ ^   / .-'.--'    . /    `--./ .-'  `-.  `-. `.  -  `. \n" <<
            " /        `.  / /      `-.   /  .-'   / .   .'   \\    \\  \\  .-  \\" << endl;
    cout << "After many fights and continous walking...." << endl;
    cout << "You have finally reached Dazu Mountain. As you climb the steep mountain to reach the top, you take a look of the view. "<< endl;
    cout << "You think to yourself \"I am almost there.\" and continuing climbing. As you climb to the top, you think all the struggles you went through." << endl;
    cout << "You reach the top and you prepare yourself to defeat Dragamor. You take a deep breathe in and walked into the cave where Dragamor lives." << endl;
    cout << "You marched on and continued through the mountain until you reach a plateau." << endl;
    cout << "Perfect place to setup camp..." << endl;

    continueScreen();
    Zone3(p1);

    if (quit == true) {
        cout << "Quitting to main menu..." << endl;
        continueScreen();
        return;
    }

    cout << "Dragamor has awoken upon hearing you reach the top of the mountain." << endl;
    cout << "There's no time to think as Dragamor suddenly roars, and proceeds to speed blitz you..." << endl;

    continueScreen();
    monsterEncounter(p1, "Dragamor");

    cout << "You've save the kingdom. Hip hip hooray!" << endl;

    if (p1.getLives() < 3) {
        p1.setLives(p1.getLives() + 1);
    }
    if(p1.getHeals() < 3) {
        p1.setHeals(3);
    }
    continueScreen();
}

void Game::Zone1(Player &p1) {
    // Do-While Statement just to catch any invalid NUMBERS, let's us loop the menu
    do {
        quit = false;
        system("clear");
        cout << "--Forest Region--" << endl << endl;
        cout << "What would you like to do?" << endl;

        cout << "1. Progress" << endl;
        cout << "2. Grind" << endl;
        cout << "3. Stats" << endl;
        cout << "4. Save" << endl;
        cout << "5. Quit" << endl;
        cout << "6. Heal" << endl << endl;
        cout << endl << "Choice: ";
        cin >> playerChoice;

        // While loop catches any invalid LETTERS and loops until a number is inputted
        while (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            system("clear");

            cout << "--Forest Region--" << endl << endl;
            cout << "What would you like to do?" << endl;

            cout << "1. Progress" << endl;
            cout << "2. Grind" << endl;
            cout << "3. Stats" << endl;
            cout << "4. Save" << endl;
            cout << "5. Quit" << endl;
            cout << "6. Heal" << endl << endl;
            cout << endl << "Choice: ";
            cin >> playerChoice;
        }

        switch (playerChoice) {
            case 1: //Progress to Boss
                system("clear");
                cout << "Progressing to Cave Entrance" << endl;
                continueScreen();
                zoneCompleted = 1;
                break;

            case 2: // Grind Monsters for drops
                system("clear");
                cout << "You head into the forest..." << endl;
                monsterEncounter(p1, "Goblin");
                break;

            case 3: // Print Char Stats
                system("clear");
                p1.printStats();
                continueScreen();
                break;

            case 4: // Save Game
                system("clear");
                //Name health damageMin damageMax weaponID armorID currentLocation lives
                saveCharacter(p1);
                cout << "Game Saved" << endl;
                continueScreen();
                break;

            case 5: // Quit Game
                quit = true;
                // exit(0);
                break;

            case 6: // Heal
                if (p1.getHeals() == 0) {
                    cout << endl << "No heals lul" << endl;
                    continueScreen();
                }
                else if (p1.getCurrentHealth() == p1.getMaxHealth()) {
                    cout << endl << "You are already at max health..." << endl;
                    continueScreen();
                }
                else {
                    p1.Heal();
                    cout << endl << "Healed to max..." << endl;
                    continueScreen();
                }
                break;

            default:
                break;
        }
    } while(zoneCompleted == 0 && quit == false);
}

void Game::Zone2(Player &p1) {
    // Do-While Statement just to catch any invalid NUMBERS, let's us loop the menu
    do {
        quit = false;
        system("clear");
        cout << "--Cave Region--" << endl << endl;
        cout << "What would you like to do?" << endl;

        cout << "1. Progress" << endl;
        cout << "2. Grind" << endl;
        cout << "3. Stats" << endl;
        cout << "4. Save" << endl;
        cout << "5. Quit" << endl;
        cout << "6. Heal" << endl;
        cout << endl << "Choice: ";
        cin >> playerChoice;

        // While loop catches any invalid LETTERS and loops until a number is inputted
        while (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            system("clear");

            cout << "--Cave Region--" << endl << endl;
            cout << "What would you like to do?" << endl;

            cout << "1. Progress" << endl;
            cout << "2. Grind" << endl;
            cout << "3. Stats" << endl;
            cout << "4. Save" << endl;
            cout << "5. Quit" << endl;
            cout << "6. Heal" << endl << endl;
            cout << endl << "Choice: ";
            cin >> playerChoice;
        }

        switch (playerChoice) {
            case 1: //Progress to Boss
                system("clear");
                cout << "Progressing towards cave exit..." << endl;
                continueScreen();
                zoneCompleted = 1;
                break;

            case 2: // Grind Monsters for drops
                system("clear");
                cout << "Chose grinding..." << endl;
                continueScreen();
                monsterEncounter(p1, "Ogre");
                break;

            case 3: // Print Char Stats
                system("clear");
                p1.printStats();
                continueScreen();
                break;

            case 4: // Save Game
                system("clear");
                //Name health damageMin damageMax weaponID armorID currentLocation lives
                saveCharacter(p1);
                cout << "Game saved..." << endl;
                continueScreen();
                break;

            case 5: // Quit Game
                quit = true;
                // exit(0);
                break;

            case 6: // Heal
                if (p1.getHeals() == 0) {
                    cout << endl << "No heals lul" << endl;
                    continueScreen();
                }
                else if (p1.getCurrentHealth() == p1.getMaxHealth()) {
                    cout << endl << "You are already at max health..." << endl;
                    continueScreen();
                }
                else {
                    p1.Heal();
                    cout << endl << "Healed to max..." << endl;
                    continueScreen();
                }
                break;

            default:
                break;
        }
    } while(zoneCompleted == 0 && quit == false);
}

void Game::Zone3(Player &p1) {
    // Do-While Statement just to catch any invalid NUMBERS, let's us loop the menu
    do {
        quit = false;
        system("clear");
        cout << "--Mountain Region--" << endl << endl;
        cout << "What would you like to do?" << endl;

        cout << "1. Progress" << endl;
        cout << "2. Grind" << endl;
        cout << "3. Stats" << endl;
        cout << "4. Save" << endl;
        cout << "5. Quit" << endl;
        cout << "6. Heal" << endl;
        cout << endl << "Choice: ";
        cin >> playerChoice;

        // While loop catches any invalid LETTERS and loops until a number is inputted
        while (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            system("clear");

            cout << "--Mountain Region--" << endl << endl;
            cout << "What would you like to do?" << endl;

            cout << "1. Progress" << endl;
            cout << "2. Grind" << endl;
            cout << "3. Stats" << endl;
            cout << "4. Save" << endl;
            cout << "5. Quit" << endl;
            cout << "6. Heal" << endl << endl;
            cout << endl << "Choice: ";
            cin >> playerChoice;
        }

        switch (playerChoice) {
            case 1: //Progress to Boss
                system("clear");
                cout << "Progressing to top of mountain" << endl;
                continueScreen();
                zoneCompleted = 1;
                break;

            case 2: // Grind Monsters for drops
                system("clear");
                cout << "Chose grinding..." << endl;
                continueScreen();
                monsterEncounter(p1, "Sentinel");
                break;

            case 3: // Print Char Stats
                system("clear");
                p1.printStats();
                continueScreen();
                break;

            case 4: // Save Game
                system("clear");
                //Name health damageMin damageMax weaponID armorID currentLocation lives
                saveCharacter(p1);
                cout << "Game saved..." << endl;
                continueScreen();
                break;

            case 5: // Quit Game
                quit = true;
                // exit(0);
                break;

            case 6: // Heal
                if (p1.getHeals() == 0) {
                    cout << endl << "No heals lul" << endl;
                    continueScreen();
                }
                else if (p1.getCurrentHealth() == p1.getMaxHealth()) {
                    cout << endl << "You are already at max health..." << endl;
                    continueScreen();
                }
                else {
                    p1.Heal();
                    cout << endl << "Healed to max..." << endl;
                    continueScreen();
                }
                break;

            default:
                break;
        }
    } while(zoneCompleted == 0 && quit == false);

}

void Game::continueScreen() {
    cout << "--------------------------------------------------------------" << endl;
    cout << "Press [Enter] to continue..." << endl;
    system("read");
    system("clear");
}

void Game::saveCharacter(Player &p1) {
    ofstream oFile("savegame.txt");

    if (oFile.is_open()) {
        oFile << p1.turnToString();
    }

    oFile.close();
}

void Game::loadCharacter(Player &p1) {
    ifstream ifs("savegame.txt");

    string name;
    int currHealth, maxHealth, damageMin, damageMax, weaponID, armorID, currentLocation, lives, heals;

    if (ifs.fail()) {
        cout << "No save file detected..." << endl;
        exit(1);
    }

    while (!ifs.eof()) {
        ifs >> name >> currHealth >> maxHealth >> damageMin >> damageMax >> weaponID >> armorID
            >> currentLocation >> lives >> heals;
    }

    p1.setName(name);
    p1.setCurrentHealth(currHealth);
    p1.setCurrentWeapon(weaponID);
    p1.setCurrentArmor(armorID);
    p1.setMaxHealth(maxHealth);
    p1.setDamage(damageMin, damageMax);
    p1.setCurrentLocation(currentLocation);
    p1.setLives(lives);
    p1.setHeals(heals);

    cout << "Character Found!" << endl << endl;

    cout << "Character Name: " << p1.getName() << endl;
    cout << "Health: " << p1.getCurrentHealth() << "|" << p1.getMaxHealth() << endl;
    cout << "Damage: " << p1.getDamageMin() << "-" << p1.getDamageMax() << endl;
    cout << "Weapon: " << p1.getCurrentWeapon().getItemName() << endl;
    cout << "Armor: " << p1.getCurrentArmor().getItemName() << endl;
    if (p1.getCurrentLocation() == 1) {
        cout << "Current Location is: Forest" << endl;
    }
    else if (p1.getCurrentLocation() == 2) {
        cout << "Current Location is: Cave" << endl;
    }
    else {
        cout << "Current Location is: Mountain" << endl;
    }
    cout << "Lives: " << p1.getLives() << endl;
    cout << "Heals: " << p1.getHeals() << endl;

    ifs.close();

    continueScreen();
}

void Game::monsterEncounter(Player &p1, string type) {
    Monster m1;
    int userChoice, attackValue;
    bool run = false;

    if (type == "Seymour" || type == "Obbo" || type == "Dragamor") {
        m1.setBossMonster(m1, type);

        cout << m1.getPrefix() << " " << m1.getType() << " challenges you." << endl;
        continueScreen();
    }
    else {
        m1.setCurrentMonster(m1, type);

        cout << "A " << m1.getPrefix() << " " << m1.getType() << " approaches!" << endl;
        continueScreen();
    }

    if (type == "Seymour" || type == "Obbo" || type == "Dragamor") {
        do { //Looped battle screen
            printBattleStats(p1, m1);

            cout << "1. Attack" << endl;
            cout << endl << "Choice: ";
            cin >> userChoice;

            // While loop catches any invalid LETTERS and loops until a number is inputted
            while (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
                system("clear");

                printBattleStats(p1, m1);

                cout << "1. Attack" << endl;
                cout << endl << "Choice: ";
                cin >> userChoice;
            }

            switch(userChoice) {
                case 1: // Attack
                    // system("clear");
                    // Randomly picks how much damage to do between damageMin and damageMax)
                    attackValue = rand() % (p1.getDamageMax() - p1.getDamageMin() + 1) + p1.getDamageMin();
                    m1.setCurrentHealth(m1.getCurrentHealth() - attackValue);

                    cout << endl << "You hit the " << m1.getPrefix() << " " << m1.getType() << " for " << attackValue << " damage!" << endl;

                    if (m1.getCurrentHealth() <= 0) {
                        m1.setCurrentHealth(0); 
                        cout << "You've killed the " + m1.getPrefix() + " " + m1.getType() + "!" << endl;
                        m1.setAliveStatus(false);
                        continueScreen();
                    }
                    else {
                        attackValue = rand() % (m1.getDamageMax() - m1.getDamageMin() + 1) + m1.getDamageMin();
                        p1.setCurrentHealth(p1.getCurrentHealth() - attackValue);

                        cout << "You were hit by the " << m1.getPrefix() << " " << m1.getType() << " for " << attackValue << " damage!" << endl;
                        continueScreen();

                        if (p1.getCurrentHealth() <= 0) {
                            if (p1.getLives() > 0) {
                                p1.Revive();
                                cout << "You have used a life to stay in the fight!" << endl;
                                continueScreen();
                                m1.setAliveStatus(true);
                                p1.setAliveStatus(true);

                            }
                            else {
                                p1.setCurrentHealth(0);
                                cout << "You died!" << endl;
                                p1.setAliveStatus(false);
                                continueScreen();
                            }
                        }
                        else {
                            m1.setAliveStatus(true);
                            p1.setAliveStatus(true);
                        }
                    }
                    break;

                default:
                    m1.setAliveStatus(true);
                    p1.setAliveStatus(true);
                    break;
            }
        } while(p1.getAliveStatus() == 1 && m1.getAliveStatus() == 1);
    }
    else {
        do { //Looped battle screen
            printBattleStats(p1, m1);

            cout << "1. Attack" << endl;
            cout << "2. Run" << endl;
            cout << endl << "Choice: ";
            cin >> userChoice;

            // While loop catches any invalid LETTERS and loops until a number is inputted
            while (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
                system("clear");

                printBattleStats(p1, m1);

                cout << "1. Attack" << endl;
                cout << "2. Run" << endl;
                cout << endl << "Choice: ";
                cin >> userChoice;
            }

            switch(userChoice) {
                case 1: // Attack
                    // system("clear");
                    // Randomly picks how much damage to do between damageMin and damageMax)
                    attackValue = rand() % (p1.getDamageMax() - p1.getDamageMin() + 1) + p1.getDamageMin();
                    m1.setCurrentHealth(m1.getCurrentHealth() - attackValue);

                    cout << endl << "You hit the " << m1.getPrefix() << " " << m1.getType() << " for " << attackValue << " damage!" << endl;

                    if (m1.getCurrentHealth() <= 0) {
                        m1.setCurrentHealth(0); 
                        cout << "You've killed the " + m1.getPrefix() + " " + m1.getType() + "!" << endl;
                        m1.setAliveStatus(false);
                        continueScreen();
                    }
                    else {
                        attackValue = rand() % (m1.getDamageMax() - m1.getDamageMin() + 1) + m1.getDamageMin();
                        p1.setCurrentHealth(p1.getCurrentHealth() - attackValue);

                        cout << "You were hit by the " << m1.getPrefix() << " " << m1.getType() << " for " << attackValue << " damage!" << endl;
                        continueScreen();

                        if (p1.getCurrentHealth() <= 0) {
                            p1.setCurrentHealth(0);
                            cout << "You died!" << endl;
                            p1.setAliveStatus(false);
                            continueScreen();
                        }
                        else {
                            m1.setAliveStatus(true);
                            p1.setAliveStatus(true);
                        }
                    }


                    break;

                case 2: // Run
                    system("clear");
                    cout << "You ran away..." << endl;
                    continueScreen();
                    run = true;
                    break;

                default:
                    break;
            }
        } while(!run && p1.getAliveStatus() == 1 && m1.getAliveStatus() == 1);
    }

    if (p1.getAliveStatus() == false) { // You Died
        if (p1.getLives() > 0) {
            cout << "You've been revived using a life" << endl;
            p1.Revive();
            cout << "Lives remaining: " << p1.getLives() << endl;
        }
        else {
            cout << "No lives, GAME OVER" << endl;
            quit = true;
            return;
        }
        continueScreen();
    }
    else if (m1.getAliveStatus() == false) { // Monster Died
        bool t1Drop, t2Drop, t3Drop;
        int t1WeaponID, t1ArmorID, t2WeaponID, t2ArmorID, t3WeaponID, t3ArmorID;
        int itemType; // 0 for weapon, 1 for armor
        Item droppedWeapon, droppedArmor;

        t1Drop = (rand() % 100) < m1.getTierOneChance();
        t2Drop = (rand() % 100) < m1.getTierTwoChance();
        t3Drop = (rand() % 100) < m1.getTierThreeChance();

        if (m1.getType() == "Goblin") {
            t3WeaponID = 12;
            t3ArmorID = 22;
            t2WeaponID = 11;
            t2ArmorID = 21;
            t1WeaponID = 10;
            t1ArmorID = 20;

            if (t3Drop == 1) { // Best Drop
                cout << "T3 Dropped..." << endl;
                itemType = (rand() % 2);
                // cout << "Type was: " << itemType << endl;
                if (itemType == 0) {
                    droppedWeapon.initializeItem(12);
                    cout << "A " << droppedWeapon.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedWeapon.getItemID() > p1.getCurrentWeapon().getItemID()) {
                        cout << "The " << droppedWeapon.getItemName() << " is better than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        p1.setCurrentWeapon(12);
                        cout << p1.getCurrentWeapon().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedWeapon.getItemName() << " is worse than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
                else {
                    droppedArmor.initializeItem(22);
                    cout << "A " << droppedArmor.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedArmor.getItemID() > p1.getCurrentArmor().getItemID()) {
                        cout << "The " << droppedArmor.getItemName() << " is better than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        p1.setCurrentArmor(22);
                        cout << p1.getCurrentArmor().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedArmor.getItemName() << " is worse than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
            }
            else if (t2Drop == 1) {
                cout << "T2 Dropped..." << endl;
                itemType = (rand() % 2);
                // cout << "Type was: " << itemType << endl;
                if (itemType == 0) {
                    droppedWeapon.initializeItem(11);
                    cout << "A " << droppedWeapon.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedWeapon.getItemID() > p1.getCurrentWeapon().getItemID()) {
                        cout << "The " << droppedWeapon.getItemName() << " is better than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        p1.setCurrentWeapon(11);
                        cout << p1.getCurrentWeapon().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedWeapon.getItemName() << " is worse than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
                else {
                    droppedArmor.initializeItem(21);
                    cout << "A " << droppedArmor.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedArmor.getItemID() > p1.getCurrentArmor().getItemID()) {
                        cout << "The " << droppedArmor.getItemName() << " is better than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        p1.setCurrentArmor(21);
                        cout << p1.getCurrentArmor().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedArmor.getItemName() << " is worse than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
            }
            else if (t1Drop == 1) { // Worst Drop
                cout << "T1 Dropped..." << endl;
                itemType = (rand() % 2);
                // cout << "Type was: " << itemType << endl;
                if (itemType == 0) {
                    droppedWeapon.initializeItem(10);
                    cout << "A " << droppedWeapon.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedWeapon.getItemID() > p1.getCurrentWeapon().getItemID()) {
                        cout << "The " << droppedWeapon.getItemName() << " is better than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        p1.setCurrentWeapon(10);
                        cout << p1.getCurrentWeapon().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedWeapon.getItemName() << " is worse than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
                else {
                    droppedArmor.initializeItem(20);
                    cout << "A " << droppedArmor.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedArmor.getItemID() > p1.getCurrentArmor().getItemID()) {
                        cout << "The " << droppedArmor.getItemName() << " is better than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        p1.setCurrentArmor(20);
                        cout << p1.getCurrentArmor().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedArmor.getItemName() << " is worse than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
            }
            else {
                cout << "You received nothing..." << endl;
                continueScreen();
            }
        }
        else if (m1.getType() == "Ogre") {
            t3WeaponID = 15;
            t3ArmorID = 25;
            t2WeaponID = 14;
            t2ArmorID = 24;
            t1WeaponID = 13;
            t1ArmorID = 23;

            if (t3Drop == 1) {
                cout << "T3 Dropped..." << endl;
                itemType = (rand() % 2);
                if (itemType == 0) {
                    droppedWeapon.initializeItem(15);
                    cout << "A " << droppedWeapon.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedWeapon.getItemID() > p1.getCurrentWeapon().getItemID()) {
                        cout << "The " << droppedWeapon.getItemName() << " is better than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        p1.setCurrentWeapon(15);
                        cout << p1.getCurrentWeapon().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedWeapon.getItemName() << " is worse than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
                else {
                    droppedArmor.initializeItem(25);
                    cout << "A " << droppedArmor.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedArmor.getItemID() > p1.getCurrentArmor().getItemID()) {
                        cout << "The " << droppedArmor.getItemName() << " is better than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        p1.setCurrentArmor(25);
                        cout << p1.getCurrentArmor().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedArmor.getItemName() << " is worse than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
            }
            else if (t2Drop == 1) {
                cout << "T2 Dropped..." << endl;
                itemType = (rand() % 2);
                if (itemType == 0) {
                    droppedWeapon.initializeItem(14);
                    cout << "A " << droppedWeapon.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedWeapon.getItemID() > p1.getCurrentWeapon().getItemID()) {
                        cout << "The " << droppedWeapon.getItemName() << " is better than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        p1.setCurrentWeapon(14);
                        cout << p1.getCurrentWeapon().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedWeapon.getItemName() << " is worse than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
                else {
                    droppedArmor.initializeItem(24);
                    cout << "A " << droppedArmor.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedArmor.getItemID() > p1.getCurrentArmor().getItemID()) {
                        cout << "The " << droppedArmor.getItemName() << " is better than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        p1.setCurrentArmor(24);
                        cout << p1.getCurrentArmor().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedArmor.getItemName() << " is worse than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
            }
            else if (t1Drop == 1) {
                cout << "T1 Dropped..." << endl;
                itemType = (rand() % 2);
                if (itemType == 0) {
                    droppedWeapon.initializeItem(13);
                    cout << "A " << droppedWeapon.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedWeapon.getItemID() > p1.getCurrentWeapon().getItemID()) {
                        cout << "The " << droppedWeapon.getItemName() << " is better than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        p1.setCurrentWeapon(13);
                        cout << p1.getCurrentWeapon().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedWeapon.getItemName() << " is worse than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
                else {
                    droppedArmor.initializeItem(23);
                    cout << "A " << droppedArmor.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedArmor.getItemID() > p1.getCurrentArmor().getItemID()) {
                        cout << "The " << droppedArmor.getItemName() << " is better than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        p1.setCurrentArmor(23);
                        cout << p1.getCurrentArmor().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedArmor.getItemName() << " is worse than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
            }
            else {
                cout << "You received nothing..." << endl;
                continueScreen();
            }
        }
        else if (m1.getType() == "Sentinel") {
            t3WeaponID = 18;
            t3ArmorID = 28;
            t2WeaponID = 17;
            t2ArmorID = 27;
            t1WeaponID = 16;
            t1ArmorID = 26;

            if (t3Drop == 1) {
                cout << "T3 Dropped..." << endl;
                itemType = (rand() % 2);
                if (itemType == 0) {
                    droppedWeapon.initializeItem(18);
                    cout << "A " << droppedWeapon.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedWeapon.getItemID() > p1.getCurrentWeapon().getItemID()) {
                        cout << "The " << droppedWeapon.getItemName() << " is better than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        p1.setCurrentWeapon(18);
                        cout << p1.getCurrentWeapon().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedWeapon.getItemName() << " is worse than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
                else {
                    droppedArmor.initializeItem(28);
                    cout << "A " << droppedArmor.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedArmor.getItemID() > p1.getCurrentArmor().getItemID()) {
                        cout << "The " << droppedArmor.getItemName() << " is better than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        p1.setCurrentArmor(28);
                        cout << p1.getCurrentArmor().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedArmor.getItemName() << " is worse than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
            }
            else if (t2Drop == 1) {
                cout << "T2 Dropped..." << endl;
                itemType = (rand() % 2);
                if (itemType == 0) {
                    droppedWeapon.initializeItem(17);
                    cout << "A " << droppedWeapon.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedWeapon.getItemID() > p1.getCurrentWeapon().getItemID()) {
                        cout << "The " << droppedWeapon.getItemName() << " is better than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        p1.setCurrentWeapon(17);
                        cout << p1.getCurrentWeapon().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedWeapon.getItemName() << " is worse than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
                else {
                    droppedArmor.initializeItem(27);
                    cout << "A " << droppedArmor.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedArmor.getItemID() > p1.getCurrentArmor().getItemID()) {
                        cout << "The " << droppedArmor.getItemName() << " is better than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        p1.setCurrentArmor(27);
                        cout << p1.getCurrentArmor().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedArmor.getItemName() << " is worse than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
            }
            else if (t1Drop == 1) {
                cout << "T1 Dropped..." << endl;
                itemType = (rand() % 2);
                if (itemType == 0) {
                    droppedWeapon.initializeItem(16);
                    cout << "A " << droppedWeapon.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedWeapon.getItemID() > p1.getCurrentWeapon().getItemID()) {
                        cout << "The " << droppedWeapon.getItemName() << " is better than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        p1.setCurrentWeapon(16);
                        cout << p1.getCurrentWeapon().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedWeapon.getItemName() << " is worse than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
                else {
                    droppedArmor.initializeItem(26);
                    cout << "A " << droppedArmor.getItemName() << " was dropped..." << endl;
                    continueScreen();
                    if (droppedArmor.getItemID() > p1.getCurrentArmor().getItemID()) {
                        cout << "The " << droppedArmor.getItemName() << " is better than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        p1.setCurrentArmor(26);
                        cout << p1.getCurrentArmor().getItemName() << " was equipped!" << endl;
                        continueScreen();
                    }
                    else {
                        cout << "The " << droppedArmor.getItemName() << " is worse than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                        cout << "You discard it." << endl;
                        continueScreen();
                    }
                }
            }
            else {
                cout << "You received nothing..." << endl;
                continueScreen();
            }
        }
        else if (m1.getType() == "Seymour") {
            cout << "T3 Dropped..." << endl;
            itemType = (rand() % 2);
            if (itemType == 0) {
                droppedWeapon.initializeItem(12);
                cout << "A " << droppedWeapon.getItemName() << " was dropped..." << endl;
                continueScreen();
                if (droppedWeapon.getItemID() > p1.getCurrentWeapon().getItemID()) {
                    cout << "The " << droppedWeapon.getItemName() << " is better than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                    p1.setCurrentWeapon(12);
                    cout << p1.getCurrentWeapon().getItemName() << " was equipped!" << endl;
                    continueScreen();
                }
                else {
                    cout << "The " << droppedWeapon.getItemName() << " is worse than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                    cout << "You discard it." << endl;
                    continueScreen();
                }
            }
            else {
                droppedArmor.initializeItem(22);
                cout << "A " << droppedArmor.getItemName() << " was dropped..." << endl;
                continueScreen();
                if (droppedArmor.getItemID() > p1.getCurrentArmor().getItemID()) {
                    cout << "The " << droppedArmor.getItemName() << " is better than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                    p1.setCurrentArmor(22);
                    cout << p1.getCurrentArmor().getItemName() << " was equipped!" << endl;
                    continueScreen();
                }
                else {
                    cout << "The " << droppedArmor.getItemName() << " is worse than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                    cout << "You discard it." << endl;
                    continueScreen();
                }
            }
        }
        else if (m1.getType() == "Obbo") {
            cout << "T3 Dropped..." << endl;
            itemType = (rand() % 2);
            if (itemType == 0) {
                droppedWeapon.initializeItem(15);
                cout << "A " << droppedWeapon.getItemName() << " was dropped..." << endl;
                continueScreen();
                if (droppedWeapon.getItemID() > p1.getCurrentWeapon().getItemID()) {
                    cout << "The " << droppedWeapon.getItemName() << " is better than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                    p1.setCurrentWeapon(15);
                    cout << p1.getCurrentWeapon().getItemName() << " was equipped!" << endl;
                    continueScreen();
                }
                else {
                    cout << "The " << droppedWeapon.getItemName() << " is worse than your " << p1.getCurrentWeapon().getItemName() << "!" << endl;
                    cout << "You discard it." << endl;
                    continueScreen();
                }
            }
            else {
                droppedArmor.initializeItem(25);
                cout << "A " << droppedArmor.getItemName() << " was dropped..." << endl;
                continueScreen();
                if (droppedArmor.getItemID() > p1.getCurrentArmor().getItemID()) {
                    cout << "The " << droppedArmor.getItemName() << " is better than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                    p1.setCurrentArmor(25);
                    cout << p1.getCurrentArmor().getItemName() << " was equipped!" << endl;
                    continueScreen();
                }
                else {
                    cout << "The " << droppedArmor.getItemName() << " is worse than your " << p1.getCurrentArmor().getItemName() << "!" << endl;
                    cout << "You discard it." << endl;
                    continueScreen();
                }
            }
        }
    }
}

void Game::printBattleStats(Player &p1, Monster &m1) {
    system("clear");
    cout << m1.getPrefix() + " " + m1.getType() << endl;
    cout << "====================" << endl;
    cout << "Health: " << m1.getCurrentHealth() << "|" << m1.getMaxHealth() << endl;
    cout << "--------------------" << endl << endl;

    cout << p1.getName() << endl;
    cout << "====================" << endl;
    cout << "Health: " << p1.getCurrentHealth() << "|" << p1.getMaxHealth() << endl;
    cout << "--------------------" << endl << endl;
}
