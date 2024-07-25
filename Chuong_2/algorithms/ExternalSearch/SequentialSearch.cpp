#include <iostream>
#include <fstream>
#include <string>

bool sequentialSearch(const std::string &filename, const std::string &target) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        if (line == target) {
            return true;
        }
    }
    return false;
}

int main() {
    std::string filename = "data.txt";
    std::string target = "hello";
    if (sequentialSearch(filename, target)) {
        std::cout << "Found\n";
    } else {
        std::cout << "Not found\n";
    }
    return 0;
}