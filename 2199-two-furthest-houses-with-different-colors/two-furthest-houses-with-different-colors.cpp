class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxDis = INT_MIN;
        int i = 0;
        for(int j = 1; j < colors.size(); j++){
            if(colors[j] != colors[i]){
                maxDis = max(maxDis, abs(j - i));
            }
        }
        i = colors.size() - 1;
        for(int j = i ; j >= 0 ; j--){
            if(colors[j] != colors[i]){
                maxDis = max(maxDis, abs(j - i));
            }
        }
        return maxDis;
    }
};