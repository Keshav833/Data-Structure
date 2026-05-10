#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int i = n - 1;

        while (i >= 0) {
            if ((num[i] - '0') % 2 != 0) {
                break;
            }
            i--;
        }

        if (i < 0) {
            return "";
        }

        return num.substr(0, i + 1);
    }
};

int main() {
    Solution sol;

    string num1 = "52";
    cout << "Input: \"" << num1 << "\"\n";
    cout << "Output: \"" << sol.largestOddNumber(num1) << "\"\n\n";

    string num2 = "4206";
    cout << "Input: \"" << num2 << "\"\n";
    cout << "Output: \"" << sol.largestOddNumber(num2) << "\"\n\n";

    string num3 = "35427";
    cout << "Input: \"" << num3 << "\"\n";
    cout << "Output: \"" << sol.largestOddNumber(num3) << "\"\n\n";

    string num4 = "246";
    cout << "Input: \"" << num4 << "\"\n";
    cout << "Output: \"" << sol.largestOddNumber(num4) << "\"\n\n";

    string num5 = "1";
    cout << "Input: \"" << num5 << "\"\n";
    cout << "Output: \"" << sol.largestOddNumber(num5) << "\"\n";

    return 0;
}