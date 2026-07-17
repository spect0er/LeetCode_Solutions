class Solution {
public:
    bool dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()){
            return false;
        }
        if(vis[r][c] == true || grid[r][c] == 1)return false;
        vis[r][c] = true;
        if(r == grid.size() - 1) return true;
        return dfs(r + 1, c, grid, vis) ||
        dfs(r - 1, c, grid, vis) ||
        dfs(r, c + 1, grid, vis) ||
        dfs(r, c - 1, grid, vis);
    }
    bool isPossible(int day, vector<vector<int>>& cells, vector<vector<int>> grid){
        for(int i = 0 ; i < day ; i++){
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }
        vector<vector<bool>>vis(grid.size(), vector<bool>(grid[0].size(),false));
        for(int i = 0 ; i < grid[0].size() ; i++){
            if(grid[0][i] == 0){
                if(dfs(0, i, grid, vis)){
                    return true;
                }
            }
        }
        return false;

    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>>grid(row,vector<int>(col,0));
        int start = 1, end = cells.size();
        int lastDay = -1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(isPossible(mid,cells,grid)){
                lastDay = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return lastDay;
    }
};