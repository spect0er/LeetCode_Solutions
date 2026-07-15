class Solution {
public:
    void dfs(int n, vector<bool>& vis, vector<vector<int>>&isConnected){
        vis[n] = true;
        for(int i = 0 ; i < isConnected.size() ; i++){
            if(isConnected[n][i] == 1 and !vis[i]){
                dfs(i,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool>vis(V,false);
        int count = 0;
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                dfs(i,vis,isConnected);
                count++;
            }
        }
        return count;
    }
};