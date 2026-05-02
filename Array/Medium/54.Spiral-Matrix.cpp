#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> arr;
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                arr.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                arr.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    arr.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            bottom--;

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    arr.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return arr;
    }
};

int main() {
    Solution sol;
//test cases
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result1 = sol.spiralOrder(matrix1);
    cout << "Test 1: ";
    for (int val : result1) cout << val << " ";
    cout << "\n";

    vector<vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> result2 = sol.spiralOrder(matrix2);
    cout << "Test 2: ";
    for (int val : result2) cout << val << " ";
    cout << "\n";

    vector<vector<int>> matrix3 = {{1}};
    vector<int> result3 = sol.spiralOrder(matrix3);
    cout << "Test 3: ";
    for (int val : result3) cout << val << " ";
    cout << "\n";

    return 0;
}