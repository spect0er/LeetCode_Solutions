class Solution {
public:
    void dfs(int curr, int destination, vector<vector<int>>&graph, vector<bool>&vis, vector<vector<int>>& result,vector<int>path){
        vis[curr] = true;
        path.push_back(curr);
        if(curr == destination){
            result.push_back(path);
        }
        for(auto neigh: graph[curr]){
            if(vis[neigh] == false){
                dfs(neigh,destination,graph,vis,result,path);
            }
        }
        // one traversal will make all the paths visited so we have to mark the node as false when we backtrack so that it can choose different paths later!!
        vis[curr] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        int V = graph.size();
        vector<bool>vis(V);
        vector<int>path;
        dfs(0,V-1,graph,vis,result,path);
        return result;
    }
};