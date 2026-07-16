class Solution {
public:
    void dfs(int r,int c, vector<vector<int>>& grid){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()){
            return;
        }
        if(grid[r][c] == 1 || grid[r][c] == 2) return;
        grid[r][c] = 2;
        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // traversing through first and last row
        for(int i = 0 ; i < cols ; i++){
            if(grid[0][i] == 0){
                dfs(0, i, grid);
            }
            if(grid[rows - 1][i] == 0){
                dfs(rows - 1, i, grid);
            }
        }
        // traversing through first and last column
        for(int i = 0 ; i < rows ; i++){
            if(grid[i][0] == 0){
                dfs(i, 0, grid);
            }
            if(grid[i][cols - 1] == 0){
                dfs(i, cols - 1, grid);
            }
        }
        int count = 0;
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(grid[i][j] == 0){
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
};