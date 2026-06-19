#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool binarySearch(vector<int>& arr, int k) {

        int l = 0;
        int r = arr.size() - 1;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (arr[mid] > k) {
                r = mid - 1;
            }
            else if (arr[mid] < k) {
                l = mid + 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};

int main() {

    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};

    Solution obj;

    cout << obj.binarySearch(arr, 7) << endl;   // 1
    cout << obj.binarySearch(arr, 10) << endl;  // 0

    return 0;
}