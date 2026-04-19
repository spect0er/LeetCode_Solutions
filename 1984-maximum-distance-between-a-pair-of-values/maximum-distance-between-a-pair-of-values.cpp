class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDis = INT_MIN;
        int i = 0, j = 0;
        while(i < nums1.size() and j < nums2.size()){
            int diff;
            if(i > j){
                j++;
            }else if(nums1[i] <= nums2[j]){
                diff = j - i;
                maxDis = max(maxDis,diff);
                j++;
            }else{
                i++; 
            }
        }
        return maxDis == INT_MIN ? 0 : maxDis;
    }
};