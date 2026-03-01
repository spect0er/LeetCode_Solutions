class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i: nums){
            pq.push(i);
        }
        while(!pq.empty() && pq.top() <= 0){
            pq.pop();
        }
        if(pq.empty() || pq.top() > 1) return 1;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            while(!pq.empty() && pq.top() == top){
                pq.pop();
            }
            if(pq.empty()) return top + 1;
            if(pq.top() != top+1){
                return top + 1;
            }
        }
        return 1;
    }
};