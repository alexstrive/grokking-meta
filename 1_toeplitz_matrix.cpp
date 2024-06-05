#include <iostream>
#include <gtest/gtest.h>

using namespace std;

bool is_toeplitz_matrix(vector<vector<int>> &matrix) {
    // Iterate over each row of the matrix, except the last row.
    for (int i = 0; i < matrix.size() - 1; ++i) {
        // For each row, iterate over each column, except the last column
        for (int j = 0; j < matrix[0].size() - 1; ++j) {
            // Check if the current element is equal to the element diagonally down to its right.
            // If any such pair of elements is not equal, return false immediately.
            if (matrix[i][j] != matrix[i + 1][j + 1]) {
                return false;
            }
        }
    }

    // If the entire matrix is iterated without finding any mismatch, return true.
    return true;
}


TEST(Example, Case1) {
    vector<vector<int>> matrix{{1, 2, 3},
                               {4, 1, 2},
                               {5, 4, 1}};
    EXPECT_TRUE(is_toeplitz_matrix(matrix));
}

TEST(Example, Case2) {
    vector<vector<int>> matrix{{1, 2},
                               {3, 4}};
    EXPECT_FALSE(is_toeplitz_matrix(matrix));
}

TEST(Example, Case3) {
    vector<vector<int>> matrix{{7, 7, 7},
                               {7, 7, 7},
                               {7, 7, 7}};
    EXPECT_TRUE(is_toeplitz_matrix(matrix));
}

TEST(Run, Case1) {
    vector<vector<int>> matrix{{1, 2, 3, 4},
                               {5, 1, 2, 3},
                               {9, 5, 1, 2}};
    EXPECT_TRUE(is_toeplitz_matrix(matrix));
}