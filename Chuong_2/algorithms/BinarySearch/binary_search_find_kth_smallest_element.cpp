#include <iostream>
#include <vector>

int countLessEqual(std::vector<std::vector<int>>& matrix, int mid, int n) {
    int count = 0;      // count of elements less than or equal to mid
    
    // start from the bottom-left corner
    int row = n - 1;
    int col = 0;

    while(row>= 0 && col < n) {
        if(matrix[row][col] <= mid) {
            count += (row + 1);
            col++;
        }
        else
            row--;
    }
    return count;
}

int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n-1][n-1];

    while(left < right) {
        int mid = left + (right - left) / 2;
        int count = countLessEqual(matrix, mid, n);

        if(count < k)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main() {
    std::vector<std::vector<int>> matrix = {{1, 5, 9},
                                            {10, 11, 13},
                                            {12, 13, 15}};
    int k = 8;
    int result = kthSmallest(matrix, k);

    std::cout << "The minor element " << k << " in matrix is: " << result << std::endl;

    return 0;
}

