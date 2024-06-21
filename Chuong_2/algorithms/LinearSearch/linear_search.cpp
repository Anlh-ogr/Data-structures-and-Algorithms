#include <iostream>
#include <vector>


void linearSearch(int *ptr, size_t size, int x) {
    for (size_t i = 0; i < size; ++i) {
        if (ptr[i] == x) {
            std::cout << "Element " << x << " is found at index " << i << std::endl;
            return;
        }
    }
    std::cout << "Element " << x << " is not found" << std::endl;
}

int main() {
    std::vector<int> array_M;
    int element;
    int value_x;
    
    std::cout << "Enter value x: ";
    std::cin >> value_x;

    while (true) {
        std::cout << "Enter element: ";
        std::cin >> element;
        if(element == -1) break;
        array_M.push_back(element);
    }

    linearSearch(array_M.data(), array_M.size(), value_x);
    return 0;
}