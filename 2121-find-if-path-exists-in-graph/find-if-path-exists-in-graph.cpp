class Solution {
public:
    bool dfs(int source, int destination, vector<vector<int>>& adj, vector<bool>&vis){
        if(source == destination) return true;
        vis[source] = true;
        for(auto neigh : adj[source]){
            if(!vis[neigh]){
                if(dfs(neigh,destination,adj,vis)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>vis(n);
        return dfs(source,destination,adj,vis);
    }
};