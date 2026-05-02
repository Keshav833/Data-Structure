#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[j][i], matrix[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sol.rotate(matrix1);
    cout << "Test 1: ";
    for (auto& row : matrix1) {
        for (int val : row) {
            cout << val << " ";
        }
    }
    cout << "\n";

    vector<vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    sol.rotate(matrix2);
    cout << "Test 2: ";
    for (auto& row : matrix2) {
        for (int val : row) {
            cout << val << " ";
        }
    }
    cout << "\n";

    vector<vector<int>> matrix3 = {{1}};
    sol.rotate(matrix3);
    cout << "Test 3: " << matrix3[0][0] << "\n";

    return 0;
}