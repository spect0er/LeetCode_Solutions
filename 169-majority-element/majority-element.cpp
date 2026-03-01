class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore Voting Algorithm
        int count = 0; 
        int res = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(count == 0){
                res = nums[i];
            }
            count += (res == nums[i]) ? 1 : -1;
        }
        return res;
    }
};