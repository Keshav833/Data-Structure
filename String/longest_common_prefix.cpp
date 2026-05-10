#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];

        for (int i = 0; i < prefix.size(); i++) {
            char ch = prefix[i];

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != ch) {
                    return prefix.substr(0, i);
                }
            }
        }
        return prefix;
    }
};

int main() {
    Solution sol;

    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Input: [\"flower\", \"flow\", \"flight\"]\n";
    cout << "Output: \"" << sol.longestCommonPrefix(strs1) << "\"\n\n";

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Input: [\"dog\", \"racecar\", \"car\"]\n";
    cout << "Output: \"" << sol.longestCommonPrefix(strs2) << "\"\n\n";

    vector<string> strs3 = {"apple", "ape", "april"};
    cout << "Input: [\"apple\", \"ape\", \"april\"]\n";
    cout << "Output: \"" << sol.longestCommonPrefix(strs3) << "\"\n\n";

    vector<string> strs4 = {""};
    cout << "Input: [\"\"]\n";
    cout << "Output: \"" << sol.longestCommonPrefix(strs4) << "\"\n\n";

    vector<string> strs5 = {"a"};
    cout << "Input: [\"a\"]\n";
    cout << "Output: \"" << sol.longestCommonPrefix(strs5) << "\"\n";

    return 0;
}

