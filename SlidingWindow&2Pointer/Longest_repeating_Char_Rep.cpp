#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

        int l = 0;
        int maxFreq = 0;
        int ans = 0;

        unordered_map<char,int> freq;

        for(int r = 0; r < s.size(); r++) {

            freq[s[r]]++;

            maxFreq = max(maxFreq, freq[s[r]]);

            while((r - l + 1) - maxFreq > k) {

                freq[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    cout << obj.characterReplacement("ABAB", 2) << endl;
    cout << obj.characterReplacement("AABABBA", 1) << endl;

    return 0;
}