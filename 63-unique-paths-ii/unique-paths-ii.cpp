class Solution {
public:
    int helper(int r,int c, vector<vector<int>>& obstacleGrid){
        if(r >= obstacleGrid.size() || c >= obstacleGrid[0].size()) return 0;
        if(obstacleGrid[r][c] == 1) return 0;
        if(r == obstacleGrid.size() - 1 && c == obstacleGrid[0].size() - 1){
            obstacleGrid[r][c] = -1;
            return -1;
        }
        if(obstacleGrid[r][c] != 0) return obstacleGrid[r][c];
        int down = helper(r+1,c,obstacleGrid);
        int right = helper(r,c+1,obstacleGrid);
        return obstacleGrid[r][c] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return -1 * helper(0,0,obstacleGrid);
    }
};