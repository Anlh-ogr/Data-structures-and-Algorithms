#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::streampos> createIndex(const std::string &filename) {
    std::ifstream file(filename);
    std::unordered_map<std::string, std::streampos> index;
    std::string line;
    std::streampos pos;
    while (file.tellg() != -1) {
        pos = file.tellg();
        std::getline(file, line);
        index[line] = pos;
    }
    return index;
}

bool indexedSearch(const std::unordered_map<std::string, std::streampos> &index, const std::string &target) {
    return index.find(target) != index.end();
}

int main() {
    std::string filename = "data.txt";
    auto index = createIndex(filename);

    std::string target = "hello";
    if (indexedSearch(index, target)) {
        std::cout << "Found\n";
    } else {
        std::cout << "Not found\n";
    }
    return 0;
}