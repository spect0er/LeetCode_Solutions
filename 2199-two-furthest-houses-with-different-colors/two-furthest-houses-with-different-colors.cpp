class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxDis = INT_MIN;
        for(int i = 0; i < colors.size();i++){
            for(int j = i + 1; j < colors.size() ; j++){
                if(colors[i] != colors[j]){
                    int diff = abs(j - i);
                    maxDis = max(diff,maxDis);
                }
            }
        }
        return maxDis;
    }
};