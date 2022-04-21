```
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0&& j == 0) continue;
                int a = 0, b = 0;
                if(i > 0) a = dp[i-1][j];
                if(j > 0) b = dp[i][j-1];
                dp[i][j] = grid[i][j] + max(a, b);
            }
        }
        return dp[m-1][n-1];
    }
};
```