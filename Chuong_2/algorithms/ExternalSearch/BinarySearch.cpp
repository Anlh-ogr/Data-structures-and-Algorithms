#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

bool binarySearch(const std::vector<std::string> &data, const std::string &target) {
    int left = 0;
    int right = data.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data[mid] == target) {
            return true;
        } else if (data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    std::string filename = "data.txt";
    std::ifstream file(filename);
    std::vector<std::string> data;
    std::string line;

    while (std::getline(file, line)) {
        data.push_back(line);
    }

    std::string target = "hello";
    if (binarySearch(data, target)) {
        std::cout << "Found\n";
    } else {
        std::cout << "Not found\n";
    }
    return 0;
}