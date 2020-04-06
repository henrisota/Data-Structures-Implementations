#include <cstdlib>
#include <iostream>
#include <string>

#include "Hash.h"

Item::Item(const std::string &name, const std::string &info) {
    this->name = name;
    this->info = info;
    this->next = NULL;
}

Item::Item() {
    this->name = "N/A";
    this->info = "N/A";
    this->next = NULL;
}

Hash::Hash() {
    // Initialize every entry in the HashTable with empty constructor Item()
    for (int i = 0; i < this->tableSize; ++i)
        HashTable[i] = new Item();
}

int Hash::hash(const std::string &key) {
    int hash = 0;
    int index;

    // Store the sum of the ASCII values of the characters of the key
    for (int i = 0; i < (int) key.length(); ++i)
        hash += (int) key[i];

    index = hash % this->tableSize;

    return index;
}

void Hash::AddItem(std::string name, std::string info) {
    int index = this->hash(name);
    // Check if there is no element stored in that index
    if (this->HashTable[index]->name == "N/A") {
        // Set the values of the item to be added
        this->HashTable[index]->name = name;
        this->HashTable[index]->info = info;
    } else {
        // Create cursor to traverse the list
        Item *ptr = this->HashTable[index];
        // Create new Item to be added to the end of the list
        Item *newItem = new Item();
        // Traverse the list of elements at that index
        while (ptr->next != NULL)
            ptr = ptr->next;
        // Place the link between the current end of the list and the new Item
        ptr->next = newItem;
    }
}
