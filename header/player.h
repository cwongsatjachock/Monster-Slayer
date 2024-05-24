#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"

class Player {
    private:
        string name;
        int currHealth;
        int maxHealth;
        int damageMin;
        int damageMax;
        Item currentWeapon;
        Item currentArmor;
        int currentLocation;
        int lives;
        int heals;
        bool isAlive;

    public:
        Player();
        virtual ~Player();

        //Accessors
        string getName() const { return this->name; }
        int getCurrentHealth() const { return this->currHealth; }
        int getMaxHealth() const { return this->maxHealth; }
        int getDamageMin() const { return this->damageMin; }
        int getDamageMax() const { return this->damageMax; }
        Item getCurrentWeapon() const { return this->currentWeapon; }
        Item getCurrentArmor() const { return this->currentArmor; }
        int getCurrentLocation() const { return this->currentLocation; }
        int getLives() const { return this->lives; }
        int getHeals() const { return this->heals; }
        int getAliveStatus() const { return this->isAlive; }

        //Mutators
        void setName(string name) { this->name = name; }
        void setCurrentHealth(int currHealth) { this->currHealth = currHealth; }
        void setMaxHealth(int maxHealth) { this->maxHealth = maxHealth; }
        void setDamage(int damageMin, int damageMax) {
            this->damageMin = damageMin;
            this->damageMax = damageMax;
        }
        void setCurrentWeapon(int weaponID);
        void setCurrentArmor(int armorID);
        void setCurrentLocation(int currentLocation) { this->currentLocation = currentLocation; }
        void setLives(int lives) { this->lives = lives; }
        void setHeals(int heals) { this->heals = heals; }
        void setAliveStatus(bool status) { this->isAlive = status; }

        //Functions
        void updateDamage(int weaponValue) {
            damageMin += weaponValue;
            damageMax += weaponValue;
        }
        void updateHealth(int armorValue) {
            maxHealth += armorValue;
        }
        void Heal() {
            currHealth = maxHealth;
            heals--;
        }
        void Revive() {
            currHealth = maxHealth;
            lives--;
        }
        string turnToString() const;
        void initializePlayer(string name);
        void printStats() const;
};

#endif