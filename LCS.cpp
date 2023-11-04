/* https://leetcode.com/problems/longest-common-subsequence/description/
 *
 * A very common DP problem.
 * Status: Passes all tests. */

#include<string>
#include<vector>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        const int n = text1.size();
        const int m = text2.size();
        
        // DP[i][j] is value of best match of text1[0..i] (exluding i) and text2[0..j] (excluding j) 
        std::vector<std::vector<int>> DP (n + 1, std::vector(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i-1] == text2[j-1]) {
                    DP[i][j] = DP[i-1][j-1] + 1;
                }
                else {
                    DP[i][j] = std::max(DP[i-1][j], DP[i][j-1]);
                }
            }
        }

        return DP[n][m];
    }
};