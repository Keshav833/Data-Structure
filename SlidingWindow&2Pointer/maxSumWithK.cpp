#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int l = k - 1;
        int r = 0;

        int sum = 0;

        // Take first k cards from left
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }

        int maxScore = sum;

        // Replace left cards with right cards one by one
        while (r < k) {

            sum -= cardPoints[l];
            sum += cardPoints[n - r - 1];

            maxScore = max(maxScore, sum);

            l--;
            r++;
        }

        return maxScore;
    }
};

int main() {

    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    Solution obj;

    int ans = obj.maxScore(cardPoints, k);

    cout << "Maximum Score = " << ans << endl;

    return 0;
}