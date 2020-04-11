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
        Item *newItem = new Item(name, info);
        // Traverse the list of elements at that index
        while (ptr->next != NULL)
            ptr = ptr->next;
        // Place the link between the current end of the list and the new Item
        ptr->next = newItem;
    }
}

int Hash::countBucket(int index) {
    int count = 0;
    if (this->HashTable[index]->name == "N/A")
        return count;
    else {
        count++;
        Item *cursor = this->HashTable[index];
        while (cursor->next != NULL) {
            count++;
            cursor = cursor->next;
        }
        return count;
    }
}

void Hash::printHashTable() {
    int number;
    for (int i = 0; i < this->tableSize; i++) {
        number = this->countBucket(i);
        std::cout << "********************" << std::endl
                  << "Index: " << i << std::endl
                  << "Name: " << this->HashTable[i]->name << std::endl
                  << "Info: " << this->HashTable[i]->info << std::endl
                  << "Number of items in bucket: " << number << std::endl
                  << "********************" << std::endl;
    }
}

void Hash::printItemsInBucket(int index) {
    Item *cursor = HashTable[index];
    if (cursor->name == "N/A")
        std::cout << "Bucket at index " << index << " has no elements inside!" 
                  << std::endl;
    else {
        std::cout << "Bucket at index " << index
                  << " contains the following elements:" << std::endl;
        while (cursor != NULL) {
            std::cout << "********************" << std::endl
                      << "Name: " << cursor->name << std::endl
                      << "Info: " << cursor->info << std::endl
                      << "********************" << std::endl;
            cursor = cursor->next;
        }
    }
}

void Hash::searchInfo(std::string name) {
    int index = this->hash(name);
    bool found = false;
    std::string info;

    Item *cursor = this->HashTable[index];
    while (cursor != NULL) {
        if (cursor->name == name) {
            found = true;
            info = cursor->info;
            break;
        }
        cursor = cursor->next;
    }
    if (found == true)
        std::cout << "Found entry with name " << name
                  << " and associated information " << std::endl
                  << info << std::endl;
    else {
        std::cout << "Could not find an entry with name " << name
                  << " in the Hash Table!" << std::endl;
    }
}

void Hash::removeItem(std::string name) {
    int index = this->hash(name);
    Item *deleteCursor;
    Item *next;
    Item *previous;

    if (this->HashTable[index]->name == "N/A" &&
        this->HashTable[index]->info == "N/A")
        std::cout << "Entry with name " << name
                  << " could not be found in the Hash Table!" << std::endl;
    else {
        if (this->HashTable[index]->name == name &&
            this->HashTable[index]->next == NULL) {
            this->HashTable[index]->name = "N/A";
            this->HashTable[index]->info = "N/A";
            std::cout << "Entry with name " << name
                      << " was successfully removed from the Hash Table!"
                      << std::endl;
        } else if (this->HashTable[index]->name == name) {
            deleteCursor = this->HashTable[index];
            this->HashTable[index] = HashTable[index]->next;
            delete deleteCursor;
            std::cout << "Entry with name " << name
                      << " was successfully removed from the Hash Table!"
                      << std::endl;
        } else {
            next = this->HashTable[index]->next;
            previous = this->HashTable[index];

            while (next != NULL && next->name != name) {
                previous = next;
                next = next->next;
            }

            if (next == NULL)
                std::cout << "Entry with name " << name
                          << " could not be found in the Hash Table!" << std::endl;
            else {
                deleteCursor = next;
                next = next->next;
                previous->next = next;
                delete deleteCursor;
                std::cout << "Entry with name " << name
                          << " was successfully removed from the Hash Table!"
                          << std::endl;
            }
        }
    }
}
