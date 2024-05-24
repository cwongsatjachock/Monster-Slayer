#include "../header/item.h"

Item::Item() {
    itemID = 0;
    itemName = "";
    // itemType = 0;
    itemValue = 0;
}

Item::Item(int itemID, string itemName, int itemValue) {
    this->itemID = itemID;
    this->itemName = itemName;
    this->itemValue = itemValue;
}

Item::~Item() {}

void Item::initializeItem(int itemID) {
    ifstream ifs("items.txt");

    if (ifs.fail()) {
        cout << "Could not open item library" << endl;
        exit(1);
    }

    int currID, currValue;
    string currRarity, currKind;

    while (!ifs.eof()) {
        ifs >> currID;
        ifs >> currRarity;
        ifs >> currKind;
        ifs >> currValue;


        if (currID == itemID) {
            setItemID(currID);
            setItemName(currRarity, currKind);
            // currentWeapon.setItemType(currWeaponType);
            setItemValue(currValue);

            ifs.close();

            return;
        }
    }

    ifs.close();
}