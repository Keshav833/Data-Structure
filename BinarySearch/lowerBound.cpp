
        //      Binary Search
        //     ↓
        //      Find exact element

        //      Lower Bound
        //     ↓
        //      Find first >= target

        //      Upper Bound
        //     ↓
        //      Find first > target

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int lowerBound(vector<int>& arr, int target) {

        int l = 0;
        int r = arr.size() - 1;

        int ans = arr.size();

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (arr[mid] >= target) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};

int main() {

    vector<int> arr = {1, 2, 4, 4, 5, 7};

    Solution obj;

    cout << obj.lowerBound(arr, 4) << endl; // 2
    cout << obj.lowerBound(arr, 3) << endl; // 2
    cout << obj.lowerBound(arr, 6) << endl; // 5
    cout << obj.lowerBound(arr, 8) << endl; // 6

    return 0;
}