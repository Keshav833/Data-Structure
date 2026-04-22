#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n= nums.size();
        for(int i =0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                count++;
            }
        }
        return count<=1;
    }
};


int main() {
    Solution sol;
    
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Test 1: " << (sol.check(nums1) ? "True" : "False") << endl;

    vector<int> nums2 = {2, 1, 3, 4};
    cout << "Test 2: " << (sol.check(nums2) ? "True" : "False") << endl;
    

    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "Test 3: " << (sol.check(nums3) ? "True" : "False") << endl;
    

    vector<int> nums4 = {1};
    cout << "Test 4: " << (sol.check(nums4) ? "True" : "False") << endl;
    
    return 0;
}


