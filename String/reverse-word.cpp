#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i = static_cast<int>(s.size()) - 1;

        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') {
                i--;
            }
            if (i < 0) {
                break;
            }

            int j = i;
            while (i >= 0 && s[i] != ' ') {
                i--;
            }

            ans += s.substr(i + 1, j - i);
            ans += ' ';
        }

        if (!ans.empty()) {
            ans.pop_back();
        }
        return ans;
    }
};

int main() {
    Solution sol;

    string input1 = "the sky is blue";
    cout << "Input: \"" << input1 << "\"\n";
    cout << "Output: \"" << sol.reverseWords(input1) << "\"\n\n";

    string input2 = "  hello world  ";
    cout << "Input: \"" << input2 << "\"\n";
    cout << "Output: \"" << sol.reverseWords(input2) << "\"\n\n";

    string input3 = "a good   example";
    cout << "Input: \"" << input3 << "\"\n";
    cout << "Output: \"" << sol.reverseWords(input3) << "\"\n";

    return 0;
}
