class Solution {
public:
    double angleClock(int hour, int minutes) {
        int minDegree = 6;
        int hourDegree = 30;
        double hourAngle = hour*30 + minutes*(hourDegree*1.0/60);
        double minuteAngle = minutes * minDegree;
        double diff = abs(hourAngle - minuteAngle);
        return min(diff,360-diff);
    }
};