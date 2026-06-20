#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int search(vector<int>& arr, int key) {

        int l = 0;
        int r = arr.size() - 1;

        while(l <= r) {

            int mid = l + (r - l) / 2;

            if(arr[mid] == key)
                return mid;

            if(arr[mid] >= arr[l]) {

                if(arr[l] <= key &&
                   key <= arr[mid]) {

                    r = mid - 1;

                } else {

                    l = mid + 1;
                }

            } else {

                if(arr[mid] < key &&
                   key <= arr[r]) {

                    l = mid + 1;

                } else {

                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {

    vector<int> arr = {4,5,6,7,0,1,2};

    Solution obj;

    cout << obj.search(arr, 0) << endl; // 4
    cout << obj.search(arr, 6) << endl; // 2
    cout << obj.search(arr, 3) << endl; // -1

    return 0;
}