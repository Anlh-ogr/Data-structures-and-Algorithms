#include <iostream>
#include <vector>
#include <memory>

void linearSearch(int *ptr, size_t size, int x) {
    for(size_t i = 0; i < size; ++i) {
        if(ptr[i] == x) {
            std::cout << "Element " << x << " is found at index " << i << std::endl;
            return;
        }
    }
    std::cout << "Element " << x << " is not found" << std::endl;
}

void add_element(std::vector<std::unique_ptr<int>> &array_M, int element) {
    array_M.push_back(std::make_unique<int>(element));
}

int main() {
    std::vector<std::unique_ptr<int>> array_M;
    int element;
    int x_value;

    std::cout << "Enter value x: ";
    std::cin >> x_value;

    std::cout << "Enter elements (-1 to stop):" << std::endl;
    while(true) {
        std::cout << "Enter element: ";
        std::cin >> element;
        if(element == -1) break;
        add_element(array_M, element);        
    }

    // Create a raw pointer array to pass to the linearSearch function
    std::vector<int> raw_ptr_array;
    for(const auto &ptr : array_M) {
        raw_ptr_array.push_back(*ptr);
    }

    // Perform linear search
    linearSearch(raw_ptr_array.data(), raw_ptr_array.size(), x_value);
    
    return 0;
}