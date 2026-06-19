#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int upperBound(vector<int>& arr, int target) {

        int l = 0;
        int r = arr.size() - 1;

        int ans = arr.size();

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (arr[mid] > target) {
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

    vector<int> arr = {1,2,4,4,5,7};

    Solution obj;

    cout << obj.upperBound(arr, 4) << endl;   // 4
    cout << obj.upperBound(arr, 3) << endl;   // 2
    cout << obj.upperBound(arr, 7) << endl;   // 6
    cout << obj.upperBound(arr, 10) << endl;  // 6

    return 0;
}