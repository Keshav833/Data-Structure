
#include <iostream>
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    // Approach 1: Using Set (Not Optimal)(Brute Force)
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        set <int> st;
        for(int i =0;i<n;i++){
            st.insert(nums[i]);
        }
        int index =0;
        for(auto it:st){
            nums[index]=it;
            index++;
        }
        return index;
    }
};
int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 1, 2};
    int newLength1 = sol.removeDuplicates(nums1);
    cout << "Test 1: New Length = " << newLength1 << ", Array = [";
    for (int i = 0; i < newLength1; i++) {
        cout << nums1[i] << (i < newLength1 - 1 ? ", " : "");
    }
    cout << "]" << endl;

    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int newLength2 = sol.removeDuplicates(nums2);
    cout << "Test 2: New Length = " << newLength2 << ", Array = [";
    for (int i = 0; i < newLength2; i++) {
        cout << nums2[i] << (i < newLength2 - 1 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}