/*
problem: 1732. Find the Highest Altitude
link: https://leetcode.com/problems/find-the-highest-altitude/
difficulty: easy

Description:
A biker starts at altitude 0.
You are given an array gain where gain[i] represents the net change
in altitude between point i and point i + 1.
Find the highest altitude reached during the trip.

Approach:
1. Initialize current altitude curr = 0.
2. Initialize highest altitude ans = 0 (starting altitude).
3. Traverse the gain array.
4. Add each gain value to curr to get the new altitude.
5. Update ans with the maximum of ans and curr.
6. After processing all points, return ans.

Example:
gain = [-5,1,5,0,-7]
Altitudes:
0 -> -5 -> -4 -> 1 -> 1 -> -6
Highest altitude = 1

Time: O(n)
Space: O(1)
*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        //biker starts at point 0 with altitude 0
        int sum = 0;
        int highest = 0;

        for(int g: gain){
            sum += g; //ad the net change in gain to find teh current altitude
            highest= max(highest, sum); //find the highest ppoint
        }
        return highest;
    }
};