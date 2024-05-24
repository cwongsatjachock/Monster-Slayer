#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

class Item {
    private:
        int itemID;
        string itemName;
        int itemValue;

    public:
        Item();
        Item(int itemId, string itemName, int itemValue);
        ~Item();

        //Accessors
        int getItemID() const { return this->itemID; }
        string getItemName() const { return this->itemName; }
        int getItemValue() const { return this->itemValue; }

        //Mutators
        void setItemID(int itemID) { this->itemID = itemID; }
        void setItemName(string rarity, string kind) { this->itemName = rarity + " " + kind; }
        void setItemValue(int itemValue) { this->itemValue = itemValue; }

        //Function
        void initializeItem(int itemID);
};

#endif