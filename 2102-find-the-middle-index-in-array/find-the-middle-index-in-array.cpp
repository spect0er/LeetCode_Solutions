class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size() ; i++){
            sum += nums[i];
        }
        int ss = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            ss += nums[i];
            if(ss == sum) return i; 
            sum -= nums[i];
        }
        return -1;
    }
};