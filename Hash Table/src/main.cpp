#include <cstdlib>
#include <iostream>
#include <string>

#include "Hash.h"

int main(int argc, char **argv) {
    Hash hashTest;
    std::string name = "";

    int result = hashTest.hash("Henri");
    std::cout << "Result is: " << result << std::endl;
    
    // Retrieve number of elements at bucket in index result of Hash Table
    int elementsInBucket = hashTest.countBucket(result);
    std::cout << "Number of elements in bucket in index " << result
              << " of the Hash Table is: " << elementsInBucket
              << "." << std::endl;
    
    // Populate hash table iwth random information
    hashTest.AddItem("Henri", "Born: N/A");
    hashTest.AddItem("Test_1", "Born: Location_1");
    hashTest.AddItem("Test_02", "Born: Location_Test");
    hashTest.AddItem("TEST_99", "Born: Location_Testing");

    hashTest.printHashTable();

    hashTest.printItemsInBucket(4);

    while (name != "exit") {
        std::cout << "Search Hash Table with name: ";
        std::cin >> name;
        if (name != "exit")
            hashTest.searchInfo(name);
    }
    name = "";
    while (name != "exit") {
        std::cout << "Removing from Hash Table with name: ";
        std::cin >> name;
        if (name != "exit")
            hashTest.removeItem(name);
    }

    hashTest.printHashTable();
    
    return 0;
}
