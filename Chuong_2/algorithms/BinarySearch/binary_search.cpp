#include <iostream>

int binarySearch(int arr[], int size, int target) {
    int left = 0;               // index of the leftmost element
    int right = size - 1;       // index of the rightmost element
    
    while (left <= right) {
        // ct: mid = (left + right) / 2; -> overflow
        // fix: mid = left + (right - left) / 2; -> no overflow
        int mid = left + (right - left) / 2;         // find the middle element

        // check if the middle element is the target
        if(arr[mid] == target)
            return mid;
        
        // check if the target is in the right half
        if(arr[mid] < target)
            left = mid + 1;                 // target is in the right half

        // check if the target is in the left half
        else
            right = mid - 1;                // target is in the left half
    }

    // target is not in the array
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50};
    
    // Calculate the size of the array
    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 10;
    int result = binarySearch(arr, size, target);

    if (result != -1)
        std::cout << "Element " << target << " is found at index: " << result << std::endl;
    else    
        std::cout << "Element " << target << " is not found in the array" << std::endl;

    return 0;
}


                                    // Explain the code at line 10:
/**
 * CASE 1: mid = (left + right) / 2;
 in case left and right are very large numbers, the sum of left and right may exceed the
 maximum value that an integer can store. As a result, the value of mid will be incorrect.
    
For example_1
    if left = 1000000 and right = 2000000.
 -> (left + right) / 2 = (1000000 + 2000000) / 2 = 1500000.
 at this example_1, the overflow does not occur because the value of left and right is not too large.

For example_2
    max = 2147483646 (max is the maximum value that an integer can store)
    if left = max - 1 and right = max - 1.
 -> (left + right) / 2 = (2147483646 + 2147483646) / 2 = 4294967292.
    the value "4294967292" is greater than the maximum value that an integer can store.
 at this example_2, the overflow occurs because the value of left and right is too large.


 * CASE 2: mid = left + (right - left) / 2;
For how to fix the overflow, we can use the following formula:
    mid = left + (right - left) / 2;

For example_2
    max = 2147483646 (max is the maximum value that an integer can store)
    if left = max - 1 and right = max - 1.
 -> mid = 2147483646 + (2147483646 - 2147483646) / 2 = 2147483646 + 0 / 2 = 2147483646.
    the value "2147483646" is correct and does not exceed the maximum value that an integer can store.
 at this example_2, the overflow does not occur
 */
