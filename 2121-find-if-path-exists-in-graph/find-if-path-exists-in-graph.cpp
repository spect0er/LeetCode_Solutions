class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        vector<bool>vis(n,false);
        q.push(source);
        vis[source] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(front == destination) return true;
            for(int neigh: adj[front]){
                if(!vis[neigh]){
                    q.push(neigh);
                    vis[neigh] = true;
                }
            }
        }
        return false;
    }
};