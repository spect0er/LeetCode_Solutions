class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>s;
        while(n != 1){
            int nn = 0;
            while(n != 0){
                int rem = n % 10;
                nn += rem*rem;
                n /= 10;
            }
            if(s.find(nn) != s.end()){
                return false;
            }
            s.insert(nn);
            n = nn;
        }
        return true;
    }
};