#ifndef MONSTER_H
#define MONSTER_H

#include "item.h"

class Monster {
    private:
        string prefix;
        string type;
        int currentHealth;
        int maxHealth;
        int damageMin;
        int damageMax;
        int t1Chance;
        int t2Chance;
        int t3Chance;
        bool isAlive;

    
    public:
        Monster();
        Monster(string prefix, string type, int currentHealth, int maxHealth, int damageMin, int damageMax, int t1Chance, int t2Chance, int t3Chance, bool isAlive);
        virtual ~Monster();

        //Accessors
        string getPrefix() const { return this->prefix; }
        string getType() const { return this->type; }
        int getCurrentHealth() const { return this->currentHealth; }
        int getMaxHealth() const { return this->maxHealth; }
        int getDamageMin() const { return this->damageMin; }
        int getDamageMax() const { return this->damageMax; }
        int getTierOneChance() const { return this->t1Chance; }
        int getTierTwoChance() const { return this->t2Chance; }
        int getTierThreeChance() const { return this->t3Chance; }
        bool getAliveStatus() const { return this->isAlive; }

        //Mutators
        void setPrefix(string prefix) { this->prefix = prefix; }
        void setType(string type) { this->type = type; }
        void setCurrentHealth(int currentHealth) { this->currentHealth = currentHealth; }
        void setMaxHealth(int maxHealth) { this->maxHealth = maxHealth; }
        void setDamage(int damageMin, int damageMax) {
            this->damageMin = damageMin;
            this->damageMax = damageMax;
        }
        void setChances(int t1Chance, int t2Chance, int t3Chance) {
            this->t1Chance = t1Chance;
            this->t2Chance = t2Chance;
            this->t3Chance = t3Chance;
        }
        void setAliveStatus(bool status) { this->isAlive = status; }

        //functions
        void setCurrentMonster(Monster &m1, string &type);
        void setBossMonster(Monster &m1, string &type);
        void printMonsterStats();
};

#endif