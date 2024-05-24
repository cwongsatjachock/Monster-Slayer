#include "../header/monster.h"

Monster::Monster() { 
    prefix = "";
    type = "";
    currentHealth = 0;
    maxHealth = 0;
    damageMin = 0;
    damageMax = 0;
    t1Chance = 0;
    t2Chance = 0;
    t3Chance = 0;
    isAlive = true;
}

Monster::Monster(string prefix, string type, int currentHealth, int maxHealth, int damageMin, int damageMax, int t1Chance, int t2Chance, int t3Chance, bool isAlive) {
    this->prefix = prefix;
    this->type = type;
    this->currentHealth = currentHealth;
    this->maxHealth = maxHealth;
    this->damageMin = damageMin;
    this->damageMax = damageMax;
    this->t1Chance = t1Chance;
    this->t2Chance = t2Chance;
    this->t3Chance = t3Chance;
    this->isAlive = isAlive;
}

Monster::~Monster() {
}

void Monster::setCurrentMonster(Monster &m1, string &type) {
    ifstream ifs("monsterscaling.txt");

    if (ifs.fail()) {
        cout << "Could not open monster library" << endl;
        exit(1);
    }

    bool prefix1, prefix2, prefix3, prefix4;
    string prefix;
    int damageIncrease, healthIncrease, t1DChance, t2DChance, t3DChance;

    prefix1 = (rand() % 100) < 100;
    prefix2 = (rand() % 100) < 75;
    prefix3 = (rand() % 100) < 50;
    prefix4 = (rand() % 100) < 25;

    // cout << "Prefix1: " << prefix1 << endl;
    // cout << "Prefix2: " << prefix2 << endl;
    // cout << "Prefix3: " << prefix3 << endl;
    // cout << "Prefix4: " << prefix4 << endl;

    if (prefix4 == 1) {
        for (int j = 0; j < 4; j++) {
            ifs >> prefix;
            ifs >> damageIncrease;
            ifs >> healthIncrease;
            ifs >> t1DChance;
            ifs >> t2DChance;
            ifs >> t3DChance;
        }
    }
    else if (prefix3 == 1) {
        for (int j = 0; j < 3; j++) {
            ifs >> prefix;
            ifs >> damageIncrease;
            ifs >> healthIncrease;
            ifs >> t1DChance;
            ifs >> t2DChance;
            ifs >> t3DChance;
        }
    }
    else if (prefix2 == 1) {
        for (int j = 0; j < 2; j++) {
            ifs >> prefix;
            ifs >> damageIncrease;
            ifs >> healthIncrease;
            ifs >> t1DChance;
            ifs >> t2DChance;
            ifs >> t3DChance;
        }
    }
    else {
        ifs >> prefix;
        ifs >> damageIncrease;
        ifs >> healthIncrease;
        ifs >> t1DChance;
        ifs >> t2DChance;
        ifs >> t3DChance;
    }

    prefix1 = 0;
    prefix2 = 0;
    prefix3 = 0;
    prefix4 = 0;

    if (type == "Slime") {
        m1.setPrefix(prefix);
        m1.setType(type);
        m1.setCurrentHealth(15 + healthIncrease);
        m1.setMaxHealth(15 + healthIncrease);
        m1.setDamage(1 + damageIncrease, 2 + damageIncrease);
        m1.setChances(t1DChance, t2DChance, t3DChance);
    }
    else if (type == "Goblin") {
        m1.setPrefix(prefix);
        m1.setType(type);
        m1.setCurrentHealth(20 + healthIncrease);
        m1.setMaxHealth(20 + healthIncrease);
        m1.setDamage(2 + damageIncrease, 4 + damageIncrease);
        m1.setChances(t1DChance, t2DChance, t3DChance);
    }
    else if (type == "Ogre") {
        m1.setPrefix(prefix);
        m1.setType(type);
        m1.setCurrentHealth(25 + healthIncrease);
        m1.setMaxHealth(25 + healthIncrease);
        m1.setDamage(3 + damageIncrease, 5 + damageIncrease);
        m1.setChances(t1DChance, t2DChance, t3DChance);
    }
    else if (type == "Sentinel") {
        m1.setPrefix(prefix);
        m1.setType(type);
        m1.setCurrentHealth(35 + healthIncrease);
        m1.setMaxHealth(35 + healthIncrease);
        m1.setDamage(4 + damageIncrease, 6 + damageIncrease);
        m1.setChances(t1DChance, t2DChance, t3DChance);
    }

    ifs.close();
}

void Monster::setBossMonster(Monster &m1, string &type) {
    ifstream ifs("bossStats.txt");

    if (ifs.fail()) {
        cout << "Could not open boss library" << endl;
        exit(1);
    }

    string prefix, bossType;
    int maxHealth, damageMin, damageMax, t1DC, t2DC, t3DC;

    while (!ifs.eof()) {
        ifs >> prefix >> bossType >> maxHealth >> damageMin >> damageMax >> t1DC >> t2DC >> t2DC;

        if (bossType == type) {
            m1.setPrefix(prefix);
            m1.setType(type);
            m1.setCurrentHealth(maxHealth);
            m1.setMaxHealth(maxHealth);
            m1.setDamage(damageMin, damageMax);
            m1.setChances(t1DC, t2DC, t3DC);

            return;
        }
    }


}

void Monster::printMonsterStats() {
    cout << "Monster Stats:" << endl;
    cout << getPrefix() + " " + type << endl;
    cout << "--------------------" << endl;
    cout << "Health: " << getMaxHealth() << "|" << getCurrentHealth() << endl;
    cout << "Damage: " << getDamageMin() << "-" << getDamageMax() << endl;
    cout << "Drop Chances (T1, T2, T3): " << getTierOneChance() << ", " 
        << getTierTwoChance() << ", " << getTierThreeChance() << endl << endl;
}