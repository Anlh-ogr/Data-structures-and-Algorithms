#include <iostream>

int findMinInRotatedArray(int arr[], int size) {
    int left = 0, right = size - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] > arr[right]) {
            // min_element is in the right side
            left = mid + 1;
        }
        else {
            // min_element is in the left side or is mid
            right = mid;
        }
    }
    return arr[left];
}

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min_element = findMinInRotatedArray(arr, size);

    std::cout << "Min element in the rotated array is: " << min_element << std::endl;

    return 0;
}