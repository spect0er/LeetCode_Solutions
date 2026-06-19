class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highestAlt = 0;
        int currAlt = 0;
        for(int i = 0 ; i < gain.size() ; i++){
            currAlt += gain[i];
            highestAlt = max(currAlt,highestAlt);
        }
        return highestAlt;
    }
};