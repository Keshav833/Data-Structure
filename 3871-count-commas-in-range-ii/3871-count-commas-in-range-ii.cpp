class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;
        long long left = 1000;
        long long right = 999999;
        long long commas = 1;

        while (left <= n ) {
            count += (min(n, right) - left + 1) * commas;


             if (left > n / 1000)
                break;
            left *= 1000;
            right = left * 1000 - 1;
            commas++;
        }

        return count;
    }
};