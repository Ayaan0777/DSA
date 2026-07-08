class Solution {
public:
    int paths(vector<vector<int>>& obstacleGrid,
              vector<vector<int>>& dp,
              int i, int j) {
        if (i < 0 || j < 0)
            return 0;
        if (obstacleGrid[i][j] == 1)
            return 0;
        if (i == 0 && j == 0)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = paths(obstacleGrid, dp, i - 1, j);
        int left = paths(obstacleGrid, dp, i, j - 1);
        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(obstacleGrid, dp, m - 1, n - 1);
    }
};