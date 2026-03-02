class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        if(k > nums.size()){
            k = nums.size();
        }
        
        if(k == nums.size()){
            for(int i = 0 ; i < k ; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > 1)return true;
        }
        return false;
        }
        for(int i = 0 ; i <= k ; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > 1)return true;
        }
        for(int i = k + 1 ; i < nums.size() ; i++){
            mp[nums[i-k-1]]--;
            mp[nums[i]]++;
            if(mp[nums[i]] > 1) return true;
        }
        return false;
    }
};