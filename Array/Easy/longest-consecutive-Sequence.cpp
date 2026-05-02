#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxSeq = 0;
        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int length = 1;
                int current = num;
                while (st.find(current + 1) != st.end()) {
                    length++;
                    current++;
                }
                maxSeq = max(length, maxSeq);
            }
        }
        return maxSeq;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Test 1: " << sol.longestConsecutive(nums1) << "\n";

    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Test 2: " << sol.longestConsecutive(nums2) << "\n";

    vector<int> nums3 = {}; 
    cout << "Test 3: " << sol.longestConsecutive(nums3) << "\n";

    vector<int> nums4 = {1, 2, 0, 1};
    cout << "Test 4: " << sol.longestConsecutive(nums4) << "\n";

    return 0;
}
