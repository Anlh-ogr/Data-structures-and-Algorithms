#include <iostream>
#include <vector>

// Function to count the number of elements less than or equal to mid in the matrix
int countLessEqual(std::vector<std::vector<int>>& matrix, int mid, int n) {
    int count = 0;      // count of elements less than or equal to mid
    
    // start from the bottom-left corner
    int row = n - 1; // last row
    int col = 0;     // first col   

    // duyệt matrix từ góc dưới bên trái
    while(row>= 0 && col < n) {
        // phần tử hiện tại <= mid ? tăng biến đếm và chuyển sang cột tiếp theo : di chuyển lên hàng trên
        if(matrix[row][col] <= mid) {
            count += (row + 1);
            col++;
        }
        else
            row--;
    }
    return count;
}

// Function to find the kth smallest element in the matrix 
int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
    int n = matrix.size();
    
    // đặt giá trị biên trái & phải cho max & small elements trong matrix
    int left = matrix[0][0], right = matrix[n-1][n-1];

    while(left < right) {
        int mid = left + (right - left) / 2;
        int count = countLessEqual(matrix, mid, n); // count of elements less than or equal to mid

        // nếu số phần tử < k? dịch sang trái : dịch sang phải
        if(count < k)
            left = mid + 1;
        else
            right = mid;
    }
    return left;    // trả về phần tử nhỏ thứ k
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

