class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // 1. Compute Prefix Sums for O(1) range sum queries
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }
        
        auto getSum = [&](int l, int r) {
            return pref[r + 1] - pref[l];
        };

        // 2. DP table initialized to 0
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // 3. Bottom-Up DP over subsegment length
        for (int len = 2; len <= n; ++len) {      // len is interval length
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;              // end index of interval
                
                int maxScore = 0;
                for (int k = i; k < j; ++k) {
                    int leftSum = getSum(i, k);
                    int rightSum = getSum(k + 1, j);

                    if (leftSum < rightSum) {
                        maxScore = max(maxScore, leftSum + dp[i][k]);
                    } else if (leftSum > rightSum) {
                        maxScore = max(maxScore, rightSum + dp[k + 1][j]);
                    } else { // leftSum == rightSum
                        maxScore = max(maxScore, leftSum + max(dp[i][k], dp[k + 1][j]));
                    }
                }
                dp[i][j] = maxScore;
            }
        }

        return dp[0][n - 1];
    }
};