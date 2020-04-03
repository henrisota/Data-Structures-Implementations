#include <cstdlib>
#include <iostream>
#include <string>

#ifndef HASH_TABLE_HASH_H
#define HASH_TABLE_HASH_H

class Hash {
    private:
        int tableSize;
    public:
        Hash();
        int hash(const std::string &key);
};

#endif
