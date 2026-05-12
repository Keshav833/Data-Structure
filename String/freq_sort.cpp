#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        vector<pair<char, int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });

        string str;
        for (const auto& p : vec) {
            str += string(p.second, p.first);
        }

        return str;
    }
};

int main() {
    Solution sol;

    string input1 = "tree";
    cout << "Input: \"" << input1 << "\"\n";
    cout << "Output: \"" << sol.frequencySort(input1) << "\"\n\n";

    string input2 = "cccaaa";
    cout << "Input: \"" << input2 << "\"\n";
    cout << "Output: \"" << sol.frequencySort(input2) << "\"\n\n";

    string input3 = "Aabb";
    cout << "Input: \"" << input3 << "\"\n";
    cout << "Output: \"" << sol.frequencySort(input3) << "\"\n";

    return 0;
}
