#include <iostream>

int findPeakElement(int arr[], int size) {
    int left = 0, right = size - 1;

    while(left < right) {
        int mid = left + (right - left) / 2;

        // mid < phần tử tiếp theo? peak element ở bên phải : peak element ở bên trái hoặc chính mid
        if(arr[mid] < arr[mid + 1])
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main() {
    int arr[] = {1, 3, 20, 4, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    int peakIndex = findPeakElement(arr, size);

    std::cout << "The peak element in the array is at index: " << peakIndex << std::endl;

    return 0;
}