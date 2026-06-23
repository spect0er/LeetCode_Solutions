class Solution {
public:
    int arrangeCoins(int n) {
        int row = 1;
        int completeRows = 0;
        while(n > 0){
            n -= row;
            row++;
            if(n >= 0) completeRows++;
        }
        return completeRows;
    }
};