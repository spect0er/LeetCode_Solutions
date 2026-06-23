class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1;
        int r = n;
        int completeRows = l;
        while(l <= r){
            long long mid = r - (r - l) / 2;
            long long numOfCoins = (mid*(mid+1))/2;
            if(numOfCoins <= n){
                completeRows = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return completeRows;
    }
};