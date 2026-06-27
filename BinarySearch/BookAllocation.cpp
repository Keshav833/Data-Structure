#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool canAloc(vector<int>& arr, int k, int mid) {

        int students = 1;
        int pages = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            if (pages + arr[i] > mid) {

                students++;
                pages = arr[i];

            } else {

                pages += arr[i];
            }
        }

        return students <= k;
    }

    int findPages(vector<int>& arr, int k) {

        if (arr.size() < k)
            return -1;

        int l = *max_element(arr.begin(), arr.end());

        int r = 0;

        for (int x : arr)
            r += x;

        int ans = -1;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (canAloc(arr, k, mid)) {

                ans = mid;
                r = mid - 1;

            } else {

                l = mid + 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> books1 = {12, 34, 67, 90};
    int students1 = 2;

    cout << "Minimum Pages = "
         << obj.findPages(books1, students1)
         << endl;

    vector<int> books2 = {15, 17, 20};
    int students2 = 2;

    cout << "Minimum Pages = "
         << obj.findPages(books2, students2)
         << endl;

    vector<int> books3 = {10, 20, 30, 40};
    int students3 = 5;

    cout << "Minimum Pages = "
         << obj.findPages(books3, students3)
         << endl;

    return 0;
}