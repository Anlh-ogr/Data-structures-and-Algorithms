// linear search on list of strings with meaningful variable names
#include <iostream>
#include <vector>
#include <string>

int linearSearch(std::vector<std::string> stringList, std::string targetString) {
    for (int index = 0; index < stringList.size(); index++) {
        if (stringList[index] == targetString) {
            return index;
        }
    }
    return -1;
}

int main() {
    int listSize;
    std::cout << "Enter the size of the list: ";
    std::cin >> listSize;

    std::vector<std::string> stringList(listSize);
    std::cout << "Enter the elements of the list: ";
    for (int index = 0; index < listSize; index++) {
        std::cin >> stringList[index];
    }

    std::string targetString;
    std::cout << "Enter the target string: ";
    std::cin >> targetString;

    int searchResult = linearSearch(stringList, targetString);

    if (searchResult == -1) {
        std::cout << "The target string is not in the list." << std::endl;
    } else {
        std::cout << "The target string is at index " << searchResult << " in the list." << std::endl;
    }

    return 0;
}

