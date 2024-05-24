#include "../header/game.h"

int main() {
    Game game1;
    srand(time(0));
    
    game1.gameSequence();
    // for (int i = 0; i < 50; i++) {
    //     cout << (rand() % 2) << endl;
    // }
    

    // bool t1Drop, t2Drop, t3Drop;

    // for (int i = 0; i < 50; i++) {
    //     t1Drop = (rand() % 100) < 20;
    //     t2Drop = (rand() % 100) < 5;
    //     t3Drop = (rand() % 100) < 1;

    //     if (t3Drop == 1) {
    //         cout << "T3 Dropped..." << endl;
    //     }
    //     else if (t2Drop == 1) {
    //         cout << "T2 Dropped..." << endl;
    //     }
    //     else if (t1Drop == 1) {
    //         cout << "T1 Dropped..." << endl;
    //     }
    //     else {
    //         cout << "You received nothing..." << endl;
    //     }
    // }
    
    
    return 0;
}