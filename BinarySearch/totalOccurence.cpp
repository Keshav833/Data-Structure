#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countFreq(vector<int>& arr, int target) {

        int l = 0;
        int r = arr.size() - 1;

        int first = -1;
        int last = -1;

        // Find First Occurrence
        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (arr[mid] == target) {

                first = mid;
                r = mid - 1;

            } else if (arr[mid] > target) {

                r = mid - 1;

            } else {

                l = mid + 1;
            }
        }

        // Element not found
        if (first == -1)
            return 0;

        l = 0;
        r = arr.size() - 1;

        // Find Last Occurrence
        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (arr[mid] == target) {

                last = mid;
                l = mid + 1;

            } else if (arr[mid] > target) {

                r = mid - 1;

            } else {

                l = mid + 1;
            }
        }

        return last - first + 1;
    }
};

int main() {

    Solution obj;

    vector<int> arr1 = {1, 2, 2, 2, 3, 4, 5};
    vector<int> arr2 = {1, 1, 1, 1, 1};
    vector<int> arr3 = {1, 2, 3, 4, 5};

    cout << "Frequency of 2: "
         << obj.countFreq(arr1, 2) << endl;

    cout << "Frequency of 1: "
         << obj.countFreq(arr2, 1) << endl;

    cout << "Frequency of 10: "
         << obj.countFreq(arr3, 10) << endl;

    return 0;
}