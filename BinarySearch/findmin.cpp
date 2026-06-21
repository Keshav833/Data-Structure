#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        int l = 0;
        int r = nums.size() - 1;

        int mini = INT_MAX;

        while (l <= r) {

            // If current range is already sorted
            if (nums[l] <= nums[r]) {
                mini = min(mini, nums[l]);
                break;
            }

            int mid = l + (r - l) / 2;

            // Left half is sorted
            if (nums[l] <= nums[mid]) {

                mini = min(mini, nums[l]);

                l = mid + 1;
            }
            // Right half contains minimum
            else {

                mini = min(mini, nums[mid]);

                r = mid - 1;
            }
        }

        return mini;
    }
};

int main() {

    Solution obj;

    vector<int> nums1 = {4,5,6,7,0,1,2};
    vector<int> nums2 = {3,4,5,1,2};
    vector<int> nums3 = {11,13,15,17};
    vector<int> nums4 = {2,1};

    cout << "Minimum: " << obj.findMin(nums1) << endl;
    cout << "Minimum: " << obj.findMin(nums2) << endl;
    cout << "Minimum: " << obj.findMin(nums3) << endl;
    cout << "Minimum: " << obj.findMin(nums4) << endl;

    return 0;
}