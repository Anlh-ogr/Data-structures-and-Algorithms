#include <iostream>

int firstGreaterEqual(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    // If no element is greater than or equal to target, return -1
    int result = -1;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(arr[mid] >= target) {
            result = mid;
            right = mid - 1;    // Continue searching on the left side
        }
        else
            left = mid + 1;    // Continue searching on the right side
    }
    return result;
}

int main() {
    int arr[] = {1, 3, 3, 5, 7, 8, 9, 9, 9, 15};
    int size = sizeof(arr) / sizeof(arr[0]);    // Calculate the size of the array

    int target = 6;
    int result = firstGreaterEqual(arr, size, target);

    // check if the target is found and print the result
    if(result != -1)
        std::cout << "The first element greater than or equal to " << target << " is found at index: " << result << std::endl;
    else
        std::cout << "There is no element greater than or equal to " << target << " in the array" << std::endl;

    return 0;
}