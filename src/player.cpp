#include "../header/player.h"

Player::Player() {
    Item weaponNull(0, "", 0);
    Item ArmorNull(0, "", 0);

    name = "";
    currHealth = 0;
    maxHealth = 0;
    damageMin = 0;
    damageMax = 0;
    currentWeapon = weaponNull;
    currentArmor = ArmorNull;
    currentLocation = 0;
    lives = 0;
    heals = 0;
    isAlive = true;
}

Player::~Player() {

}

string Player::turnToString() const {
    return name + " " 
        + to_string(currHealth) + " "
        + to_string(maxHealth) + " "
        + to_string(damageMin) + " "
        + to_string(damageMax) + " "
        + to_string(currentWeapon.getItemID()) + " "
        + to_string(currentArmor.getItemID()) + " "
        + to_string(currentLocation) + " "
        + to_string(lives) + " "
        + to_string(heals);
}

void Player::initializePlayer(string name) {
    // Item weapon1(10, "Wooden Sword", 0, 2);
    // Item armor1(20, "Leather Chestplate", 1, 1);

    setName(name);
    setCurrentHealth(25);
    setMaxHealth(25);
    setDamage(3, 5);
    setCurrentWeapon(10);
    // cout << "Current Weapon Stats upon initial initialization: " << endl;
    // cout << "Weapon ID: " << currentWeapon.getItemID() << endl;
    // cout << "Weapon Name: " << currentWeapon.getItemName() << endl;
    // cout << "Weapon Damage Addition: " << currentWeapon.getItemValue() << endl << endl;

    setCurrentArmor(20);
    // cout << "Current Armor Stats upon initial initialization: " << endl;
    // cout << "Armor ID: " << currentArmor.getItemID() << endl;
    // cout << "Armor Name: " << currentArmor.getItemName() << endl;
    // cout << "Armor Health Addition: " << currentArmor.getItemValue() << endl << endl;
    setCurrentLocation(0);
    setLives(3);
    setHeals(3);
    setCurrentHealth(26);
}

void Player::printStats() const {
    cout << name << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "Health: " << currHealth << "|" << maxHealth << endl;
    cout << "Damage: " << damageMin << "-" << damageMax << endl;
    cout << "Current Weapon: " << currentWeapon.getItemName() << " (+" << currentWeapon.getItemValue() << " to base damage)" << endl;
    cout << "Current Armor: " << currentArmor.getItemName() << " (+" << currentArmor.getItemValue() << " to base health)" << endl;
    if (currentLocation == 1) {
        cout << "Current Location: Forest" << endl;
    }
    else if (currentLocation == 2) {
        cout << "Current Location: Cave" << endl;
    }
    else if (currentLocation == 0) {
        cout << "Current Location: Tutorial" << endl;
    }
    else {
        cout << "Current Location: Mountain" << endl;
    }
    cout << "Lives: " << lives << endl;
    cout << "Heals: " << heals << endl;
}

void Player::setCurrentWeapon(int weaponID) {
    ifstream ifs("items.txt");

    if (ifs.fail()) {
        cout << "Could not open item library" << endl;
        exit(1);
    }

    int currWeaponID, currWeaponValue;
    string currWeaponRarity, currWeaponKind;

    while (!ifs.eof()) {
        ifs >> currWeaponID;
        ifs >> currWeaponRarity;
        ifs >> currWeaponKind;
        ifs >> currWeaponValue;


        if (currWeaponID == weaponID) {
            currentWeapon.setItemID(currWeaponID);
            currentWeapon.setItemName(currWeaponRarity, currWeaponKind);
            // currentWeapon.setItemType(currWeaponType);
            currentWeapon.setItemValue(currWeaponValue);

            ifs.close();

             updateDamage(currentWeapon.getItemValue());

            return;
        }
    }
    
    ifs.close();
}

void Player::setCurrentArmor(int armorID) {
    ifstream ifs("items.txt");

    if (ifs.fail()) {
        cout << "Could not open item library" << endl;
        exit(1);
    }

    int currArmorID, currArmorValue;
    string currArmorRarity, currArmorKind;

    while (!ifs.eof()) {
        ifs >> currArmorID;
        ifs >> currArmorRarity;
        ifs >> currArmorKind;
        ifs >> currArmorValue;

        // cout << "ArmorID: " << currArmorID << endl;
        // cout << "Armor Rarity: " << currArmorRarity << endl;
        // cout << "Armor Kind: " << currArmorKind << endl;
        // cout << "Armor Val: " << currArmorValue << endl;

        if (currArmorID == armorID) {
            currentArmor.setItemID(currArmorID);
            currentArmor.setItemName(currArmorRarity, currArmorKind);
            currentArmor.setItemValue(currArmorValue);

            ifs.close();

            // cout << "Set Current Armor: " << currentArmor.getItemName() << endl;

            updateHealth(currentArmor.getItemValue());

            return;
        }
    }

    ifs.close();
}