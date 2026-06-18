/*
problem: 1344. Angle Between Hands of a Clock
link: https://leetcode.com/problems/angle-between-hands-of-a-clock/
difficulty: medium

Description:
Given the hour and minutes shown on an analog clock,
find the smaller angle (in degrees) between the hour hand and the minute hand.
The minute hand moves 6 degrees per minute.
The hour hand moves 30 degrees per hour and also moves continuously as minutes pass.
Return the minimum angle formed between the two hands.

Approach:
1. Convert the given time into fractional hours:
      x = hour + minutes / 60.0
2. Compute the relative separation between the hands in clock-hour units:
    diff = (11 * x) % 12
3. Since the clock is circular, there are two possibleangles. Take the smaller separation:
    min(diff, 12 - diff)
4. Convert clock-hour units to degrees: angle = 
    separation * 30
5. Return the result.

Time: O(1)
Space: O(1)
*/

#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x = hour + minutes / 60.0;
        double diff = fmod(11.0 * x, 12.0);
        return min(diff, 12.0 - diff) * 30.0;
    }
};