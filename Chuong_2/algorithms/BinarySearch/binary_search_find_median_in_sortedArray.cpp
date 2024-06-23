#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    if(nums1.size() > nums2.size())
        // Ensure that nums1 is the smaller or equal nums2
        return findMedianSortedArrays(nums2, nums1);

    int x = nums1.size();
    int y = nums2.size();
    int left = 0, right = x;

    while(left <= right) {
        int partitionX = left + (right - left) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int max_X = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int min_X = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int max_Y = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int min_Y = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if(max_X <= min_Y && max_Y <= min_X) {
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
    throw std::invalid_argument("Input arrays are not sorted");
}

int main() {
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};

    double median = findMedianSortedArrays(nums1, nums2);

    std::cout << "Median of the two sorted arrays is: " << median << std::endl;

    return 0;
}