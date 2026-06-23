class Solution {
public:
    int hoursSpent(vector<int>&piles, int speed){
        int hours = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            int q = piles[i]/speed;
            int r = piles[i]%speed;
            hours += q;
            if(r != 0){
                hours += 1;
            }
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for(auto i: piles){
            r = max(r,i);
        }
        int k = r;
        while(l <= r){
            int mid = r - (r - l) / 2;
            int hours = hoursSpent(piles,mid);
            if(hours <= h){
                k = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return k;
    }
};