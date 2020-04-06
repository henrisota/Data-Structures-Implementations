#include <cstdlib>
#include <iostream>
#include <string>

#ifndef HASH_TABLE_HASH_H
#define HASH_TABLE_HASH_H

struct Item {
    std::string name;
    std::string info;
    Item *next;
    Item(const std::string &name, const std::string &info);
    Item();
};

class Hash {
    private:
        static const int tableSize = 20;
        Item* HashTable[tableSize];
    public:
        Hash();
        int hash(const std::string &key);
        void AddItem(std::string name, std::string info);

};

#endif
