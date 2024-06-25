#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    // nums1 > nums2 ? swap(nums1, nums2) : nums1;
    if(nums1.size() > nums2.size())
        // Ensure that nums1 is the smaller or equal nums2
        return findMedianSortedArrays(nums2, nums1);

    int x = nums1.size();
    int y = nums2.size();
    int left = 0, right = x;

    while(left <= right) {
        int partitionX = left + (right - left) / 2; // tính chỉ số phân vùng của nums1
        int partitionY = (x + y + 1) / 2 - partitionX; // tính chỉ số phân vùng của nums2

        int max_X = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];  // lấy phần tử lớn nhất của nums1
        int min_X = (partitionX == x) ? INT_MAX : nums1[partitionX];      // lấy phần tử nhỏ nhất của nums1

        int max_Y = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];  // lấy phần tử lớn nhất của nums2
        int min_Y = (partitionY == y) ? INT_MAX : nums2[partitionY];      // lấy phần tử nhỏ nhất của nums2

        if(max_X <= min_Y && max_Y <= min_X) {
            // nếu tổng số phần tử là chẵn? return giá trị trung bình của 2 phần tử ở giữa : return giá trị phần tử ở giữa
            if((x + y) % 2 == 0)
                return(double)(std::max(max_X, max_Y) + std::min(min_X, min_Y)) / 2;
            else
                return(double)std::max(max_X, max_Y);
        }
        else if(max_X > min_Y) {
            // Go on the left side
            right = partitionX - 1;
        }
        else
        {   
            // Go on the right side
            left = partitionX + 1;
        }
    }
    // If the input arrays are not sorted
    throw std::invalid_argument("Input arrays are not sorted");
}

int main() {
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};

    double median = findMedianSortedArrays(nums1, nums2);

    std::cout << "Median of the two sorted arrays is: " << median << std::endl;

    return 0;
}