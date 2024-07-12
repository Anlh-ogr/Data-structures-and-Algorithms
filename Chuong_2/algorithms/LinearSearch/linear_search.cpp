#include <iostream>

// Function to perform linear search
int linearSearch(int array[], int array_size, int targetValue) {
    for (int index = 0; index < array_size; index++) {
        if (array[index] == targetValue) {
            return index;
        }
    }
    return -1;  // return -1 if not found
}

int main() {
    int array[] = {5, 3, 7, 1, 9, 4, 6};
    int array_size = sizeof(array) / sizeof(array[0]);
    int targetValue = 4;

    int searchResult = linearSearch(array, array_size, targetValue);
    if (searchResult != -1) {
        std::cout << "Target value found at index: " << searchResult << std::endl;
    } else {
        std::cout << "Target value not found in the array" << std::endl;
    }

    return 0;
}
