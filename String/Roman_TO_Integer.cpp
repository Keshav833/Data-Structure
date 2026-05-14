#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (i + 1 < s.size() && s[i] == 'I' && s[i + 1] == 'V') {
                i++;
                sum += 4;
                continue;
            }
            else if (i + 1 < s.size() && s[i] == 'I' && s[i + 1] == 'X') {
                i++;
                sum += 9;
                continue;
            }
            else if (i + 1 < s.size() && s[i] == 'X' && s[i + 1] == 'L') {
                i++;
                sum += 40;
                continue;
            }
            else if (i + 1 < s.size() && s[i] == 'X' && s[i + 1] == 'C') {
                i++;
                sum += 90;
                continue;
            }
            else if (i + 1 < s.size() && s[i] == 'C' && s[i + 1] == 'D') {
                i++;
                sum += 400;
                continue;
            }
            else if (i + 1 < s.size() && s[i] == 'C' && s[i + 1] == 'M') {
                i++;
                sum += 900;
                continue;
            }

            switch (ch) {
                case 'I':
                    sum += 1;
                    break;
                case 'V':
                    sum += 5;
                    break;
                case 'X':
                    sum += 10;
                    break;
                case 'L':
                    sum += 50;
                    break;
                case 'C':
                    sum += 100;
                    break;
                case 'D':
                    sum += 500;
                    break;
                case 'M':
                    sum += 1000;
                    break;
                default:
                    break;
            }
        }
        return sum;
    }
};