class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pp(nums.size() + 1,1);
        vector<int> sp(nums.size() + 1,1);
        for(int i = 0 ; i < nums.size() ; i++){
            pp[i+1] = pp[i] * nums[i];
        }
        for(int i = nums.size()-1 ; i>= 0 ;i--){
            sp[i] = sp[i+1] * nums[i];
        }
        vector<int>ans(nums.size());
        for(int i = 0 ; i < nums.size() ; i++){
            ans[i] = pp[i]*sp[i+1];
        }
        return ans;
    }
};