public class Solution {
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        // write your code here
    	int row = obstacleGrid.length;
    	int col = obstacleGrid[0].length;
    	int[][] dp = new int[row][col];
    	for (int i=0; i<col && obstacleGrid[0][i] != 1; dp[0][i++] = 1);
    	for (int i=0; i<row && obstacleGrid[i][0] != 1; dp[i++][0] = 1);
    	for (int i=1; i<row; ++i) {
    		for (int j=1; j<col; ++j) {
    			if (obstacleGrid[i][j] == 1) {
    				dp[i][j] = 0;
    			} else {
    				dp[i][j] = dp[i-1][j] + dp[i][j-1];
    			}
    		}
    	}
    	return dp[row-1][col-1];
    }
}