#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> sub;

        int l = 0;
        int r = 0;
        int len = 0;

        int n = s.size();

        while (r < n) {

            while (sub.count(s[r])) {
                sub.erase(s[l]);
                l++;
            }

            sub.insert(s[r]);

            len = max(len, r - l + 1);

            r++;
        }

        return len;
    }
};

int main() {

    Solution obj;

    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    string s4 = "";

    cout << "Input: " << s1 << endl;
    cout << "Output: " << obj.lengthOfLongestSubstring(s1) << endl;

    cout << "\nInput: " << s2 << endl;
    cout << "Output: " << obj.lengthOfLongestSubstring(s2) << endl;

    cout << "\nInput: " << s3 << endl;
    cout << "Output: " << obj.lengthOfLongestSubstring(s3) << endl;

    cout << "\nInput: \"" << s4 << "\"" << endl;
    cout << "Output: " << obj.lengthOfLongestSubstring(s4) << endl;

    return 0;
}