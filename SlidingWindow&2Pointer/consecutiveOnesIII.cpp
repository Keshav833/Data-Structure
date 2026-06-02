#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();

        int l = 0;
        int r = 0;

        unordered_map<int,int> num;

        int len = 0;

        while (r < n) {

            num[nums[r]]++;

            while (num[0] > k) {
                num[nums[l]]--;
                l++;
            }

            len = max(len, r - l + 1);

            r++;
        }

        return len;
    }
};
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();

        int l = 0;
        int r = 0;

        // unordered_map<int,int> num;
        int zero =0

        int len = 0;

        while (r < n) {

            num[nums[r]]++;
            if(nums[r]==0){
                zero++;
            }

            while (zero > k) {
                num
                l++;
            }

            len = max(len, r - l + 1);

            r++;
        }

        return len;
    }
};

int main() {

    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    Solution obj;

    cout << "Maximum Length = "
         << obj.longestOnes(nums, k)
         << endl;

    return 0;
}