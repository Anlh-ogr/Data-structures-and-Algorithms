#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

bool hashingSearch(const std::string &filename, const std::string &target) {
    std::ifstream file(filename);
    std::unordered_map<std::string, bool> hashTable;
    std::string line;

    while (std::getline(file, line)) {
        hashTable[line] = true;
    }

    return hashTable.find(target) != hashTable.end();
}

int main() {
    std::string filename = "data.txt";
    std::string target = "search_value";

    if (hashingSearch(filename, target)) {
        std::cout << "Found!" << std::endl;
    } else {
        std::cout << "Not Found!" << std::endl;
    }
    return 0;
}
