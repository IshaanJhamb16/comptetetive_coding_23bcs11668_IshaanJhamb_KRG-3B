#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

       
        if (obstacleGrid[0][0] == 1 || obstacleGrid[rows - 1][cols - 1] == 1) {
            return 0;
        }

      
        vector<long long> dp(cols, 0);

       
        dp[0] = 1;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    
                    dp[j] = 0;
                } else if (j > 0) {
                                        dp[j] += dp[j - 1];
                }
            }
        }

        return (int)dp[cols - 1];
    }
};