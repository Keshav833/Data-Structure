#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> find(vector<int>& arr, int x) {

        int l = 0;
        int r = arr.size() - 1;

        vector<int> ans(2, -1);

        // First occurrence
        while(l <= r) {

            int mid = l + (r - l) / 2;

            if(arr[mid] == x) {
                ans[0] = mid;
                r = mid - 1;
            }
            else if(arr[mid] > x) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        l = 0;
        r = arr.size() - 1;

        // Last occurrence
        while(l <= r) {

            int mid = l + (r - l) / 2;

            if(arr[mid] == x) {
                ans[1] = mid;
                l = mid + 1;
            }
            else if(arr[mid] > x) {
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

    vector<int> arr = {1,2,2,2,3,4,5};

    Solution obj;

    vector<int> ans = obj.find(arr, 2);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}