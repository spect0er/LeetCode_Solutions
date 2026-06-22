class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>answer(n,0);
        for(int i = 0 ; i < bookings.size() ; i++){
            int first = bookings[i][0];
            int last = bookings[i][1];
            int seats = bookings[i][2];
            for(int j = first - 1; j < last ; j++){
                answer[j] += seats;
            }
        }
        return answer;
    }
};