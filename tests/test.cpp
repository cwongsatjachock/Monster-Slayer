#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "string"

#include "../header/game.h"
#include "../header/item.h"
#include "../header/monster.h"
#include "../header/player.h"

#include "../src/game.cpp"
#include "../src/item.cpp"
#include "../src/monster.cpp"
#include "../src/player.cpp"

using::testing::InSequence;
using::testing::AtLeast;

TEST(ItemTest, testInitialization) {
    Item stuff;
    stuff.initializeItem(10);
    EXPECT_EQ(stuff.getItemID(), 10);
}

TEST(MonsterTest, testSetMonster) {
    Monster testMon;
    std::string testType = "Slime";
    EXPECT_NO_THROW(testMon.setCurrentMonster(testMon, testType));
}

TEST(MonsterTest, testBossMonster) {
    Monster testBoss;
    std::string testType = "Seymour";
    EXPECT_NO_THROW(testBoss.setBossMonster(testBoss, testType));
}

TEST(MonsterTest, testMonsterStat) {
    Monster testMon;
    EXPECT_NO_THROW(testMon.printMonsterStats());
}

TEST(PlayerTest, testInitializeAndString) {
    Player p1;
    p1.initializePlayer("Joe");
    EXPECT_NO_THROW(p1.turnToString());
}

TEST(PlayerTest, testPrintPlayer) {
    Player p1;
    EXPECT_NO_THROW(p1.printStats());
}

TEST(PlayerTest, testSetWeapon) {
    Player p1;
    EXPECT_NO_THROW(p1.setCurrentWeapon(10));
    EXPECT_EQ(p1.getCurrentWeapon().getItemID(), 10);
    EXPECT_EQ(p1.getCurrentWeapon().getItemName(), "Wooden Sword");
    EXPECT_EQ(p1.getCurrentWeapon().getItemValue(), 2);
}

TEST(PlayerTest, testSetArmor) {
    Player p1;
    EXPECT_NO_THROW(p1.setCurrentArmor(20));
    EXPECT_EQ(p1.getCurrentArmor().getItemID(), 20);
    EXPECT_EQ(p1.getCurrentArmor().getItemName(), "Leather Chestplate");
    EXPECT_EQ(p1.getCurrentArmor().getItemValue(), 1);
    EXPECT_EQ(p1.getMaxHealth(), 1);
}

TEST(PlayerTest, testUpdateDmg) {
    Player p1;
    EXPECT_NO_THROW(p1.updateDamage(5));
    EXPECT_EQ(p1.getDamageMin(), 5);
    EXPECT_EQ(p1.getDamageMax(), 5);
}

TEST(PlayerTest, testUpdateHP) {
    Player p1;
    EXPECT_NO_THROW(p1.updateHealth(5));
    EXPECT_EQ(p1.getMaxHealth(), 5);
}

TEST(PlayerTest, testHeal) {
    Player p1;
    EXPECT_NO_THROW(p1.Heal());
    EXPECT_EQ(p1.getHeals(), -1);
}

TEST(PlayerTest, testRevive) {
    Player p1;
    p1.setMaxHealth(2);
    EXPECT_NO_THROW(p1.Revive());
    EXPECT_EQ(p1.getLives(), -1);
    EXPECT_EQ(p1.getCurrentHealth(), 2);
}

TEST(GameTest, testBattleStats) {
    Game g1;
    Player p1;
    Monster m1;
    EXPECT_NO_THROW(g1.printBattleStats(p1, m1));
}

TEST(GameTest, testSaveCharacter) {
    Game g1;
    Player p1;
    EXPECT_NO_THROW(g1.saveCharacter(p1));
}

TEST(GameTest, testLoadCharacter) {
    Game g1;
    Player p1;
    EXPECT_NO_THROW(g1.loadCharacter(p1));
}



class MockGame : public Game {
    public:
        MOCK_METHOD(void, gameSequence, (), ());
        MOCK_METHOD(void, mainMenu, (Player &p1), ());
        MOCK_METHOD(void, startGame, (Player &p1), ());
        MOCK_METHOD(void, intro, (Player &p1), ());
        MOCK_METHOD(void, tutorial, (Player &p1), ());
        MOCK_METHOD(void, Forest, (Player &p1), ());
        MOCK_METHOD(void, Cave, (Player &p1), ());
        MOCK_METHOD(void, Mountain, (Player &p1), ());
        MOCK_METHOD(void, Zone1, (Player &p1), ());
        MOCK_METHOD(void, Zone2, (Player &p1), ());
        MOCK_METHOD(void, Zone3, (Player &p1), ());
        MOCK_METHOD(void, continueScreen, (), ());
        MOCK_METHOD(void, monsterEncounter, (Player &p1, std::string type), ());
};

TEST(GameTest, testSequence) {
    MockGame g1;
    EXPECT_CALL(g1, gameSequence()).Times(AtLeast(1));
    g1.gameSequence();
}

TEST(GameTest, testContinue) {
    MockGame g1;
    EXPECT_CALL(g1, continueScreen()).Times(AtLeast(1));
    g1.continueScreen();
}
