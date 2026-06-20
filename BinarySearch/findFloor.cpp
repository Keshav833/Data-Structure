// Find Floor
// Floor  -> last element <= x
// Ceil   -> first element >= x

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findFloor(vector<int>& arr, int x) {

        int l = 0;
        int r = arr.size() - 1;

        int ans = -1;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (arr[mid] > x) {

                r = mid - 1;

            } else {

                ans = mid;      // possible floor
                l = mid + 1;    // search for a larger valid floor
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> arr1 = {1, 2, 4, 6, 10};

    cout << "Floor of 5  : "
         << obj.findFloor(arr1, 5) << endl;

    cout << "Floor of 6  : "
         << obj.findFloor(arr1, 6) << endl;

    cout << "Floor of 0  : "
         << obj.findFloor(arr1, 0) << endl;

    cout << "Floor of 15 : "
         << obj.findFloor(arr1, 15) << endl;

    return 0;
}