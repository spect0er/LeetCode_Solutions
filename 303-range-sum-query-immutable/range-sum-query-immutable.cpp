class NumArray {
public:
    vector<int>prefix_sum;
    NumArray(vector<int>& nums) {
        prefix_sum.resize(nums.size(),nums[0]);
        for(int i = 1; i < nums.size(); i++){
            prefix_sum[i] = nums[i] + prefix_sum[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return left == 0 ? prefix_sum[right] : prefix_sum[right] - prefix_sum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */