// linear seach on user input array with meaningful variable names

#include <iostream>

int linearSearch(int array[], int array_size, int targetValue) {
    for (int index = 0; index < array_size; index++) {
        if (array[index] == targetValue) {
            return index;
        }
    }
    return -1;
}

int main() {
    int array_size;
    std::cout << "Enter the size of the array: ";
    std::cin >> array_size;

    int array[array_size];
    std::cout << "Enter the elements of the array: ";
    for (int index = 0; index < array_size; index++) {
        std::cin >> array[index];
    }

    int targetValue;
    std::cout << "Enter the target value: ";
    std::cin >> targetValue;

    int result = linearSearch(array, array_size, targetValue);
    if (result == -1) {
        std::cout << "The target value is not in the array." << std::endl;
    } else {
        std::cout << "The target value is at index " << result << "." << std::endl;
    }

    return 0;
}