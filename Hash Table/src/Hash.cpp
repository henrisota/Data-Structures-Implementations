#include <cstdlib>
#include <iostream>
#include <string>

#include "Hash.h"

Hash::Hash() {
    this->tableSize = 20;
}

int Hash::hash(const std::string &key) {
    int hash = 0;
    int index;

    for (int i = 0; i < key.length(); i++)
        hash += (int) key[i];

    index = hash % this->tableSize;

    return hash;
}
