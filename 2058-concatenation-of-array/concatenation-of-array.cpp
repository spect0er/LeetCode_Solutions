class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n*2);
        for(int i = 0 ; i < 2*n ; i++){
            int ind = i % n;
            ans[i] = nums[ind];
        }
        return ans;
    }
};