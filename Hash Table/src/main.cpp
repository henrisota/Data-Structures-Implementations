#include <cstdlib>
#include <iostream>
#include <string>

#include "Hash.h"

int main(int argc, char **argv) {
    Hash hashTest;
    int result = hashTest.hash("Henri");
    std::cout << "Result is: " << result << std::endl;
    return 0;
}
