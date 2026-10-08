class Solution {
public:
    int countDigits(int n){
        int dig = 0;
        while(n != 0){
            n = n/10;
            dig++;
        }
        return dig;
    }
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (auto i: nums){
            int numOfDig = countDigits(i);
            if(numOfDig % 2 == 0){
                ans++;
            }

        }
        return ans;
    }
};