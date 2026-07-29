class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int>prev = intervals[0];
        vector<vector<int>>res;
        for(int i = 1 ; i < intervals.size(); i++){
            if(prev[1] >= intervals[i][0]){
                if(prev[1] >= intervals[i][1]){
                    swap(prev,intervals[i]);
                }else{
                    intervals[i][0] = prev[0];
                }
            }else{
                res.push_back(prev);
            }
            prev = intervals[i];
        }
        res.push_back(prev);
        return res;
    }
};