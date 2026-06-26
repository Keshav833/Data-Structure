#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool canPlace(vector<int>& stalls, int dist, int k) {

        int cows = 1;
        int last = stalls[0];

        for(int i = 1; i < stalls.size(); i++) {

            if(stalls[i] - last >= dist) {

                cows++;
                last = stalls[i];
            }
        }

        return cows >= k;
    }

    int aggressiveCows(vector<int>& stalls, int k) {

        sort(stalls.begin(), stalls.end());

        int l = 1;
        int r = stalls.back() - stalls.front();

        int ans = 0;

        while(l <= r) {

            int mid = l + (r - l) / 2;

            if(canPlace(stalls, mid, k)) {

                ans = mid;
                l = mid + 1;

            } else {

                r = mid - 1;
            }
        }

        return ans;
    }
};

int main() {

    vector<int> stalls = {1,2,4,8,9};

    Solution obj;

    cout << obj.aggressiveCows(stalls,3);

    return 0;
}