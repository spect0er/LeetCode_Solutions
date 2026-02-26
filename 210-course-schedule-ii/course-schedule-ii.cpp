class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(int i = 0 ; i < pre.size() ; i++){
            int u = pre[i][0];
            int v = pre[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        vector<int>res;
        queue<int>q;
        for(int i = 0 ; i < indegree.size() ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            res.push_back(front);
            for(auto &neigh: adj[front]){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }

        }
        if(res.size() != numCourses) return {}; 
        return res;
    }
};