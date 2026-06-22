class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>answer(n+1,0);
        for(int i = 0 ; i < bookings.size() ; i++){
            answer[bookings[i][0]-1] += bookings[i][2];
            answer[bookings[i][1]] -= bookings[i][2];
        }
        for(int i = 1 ; i < n ; i++){
            answer[i] += answer[i-1];
        }
        answer.pop_back();
        return answer;
    }
};