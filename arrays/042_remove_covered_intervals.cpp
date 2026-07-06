/*
Problem: 1288. Remove Covered Intervals
Link: https://leetcode.com/problems/remove-covered-intervals/
Difficulty: Medium

Description:
Given a list of intervals, remove all intervals that are completely
covered by another interval.
An interval [a, b] is covered by [c, d] if:
    c <= a and b <= d.
Return the number of intervals remaining after removing all covered intervals.

Approach:
1. Sort intervals by:
   - Start point in ascending order.
   - If starts are equal, end point in descending order.
2. Maintain the maximum end point (maxEnd) seen so far.
3. Traverse the sorted intervals:
   - If the current interval ends after maxEnd, it is not covered.
     Increment the answer and update maxEnd.
   - Otherwise, the interval is covered by a previous interval.
4. Return the count of uncovered intervals.

Example:
Input:
intervals = [[1,4],[3,6],[2,8]]

Sorted:
[1,4]
[2,8]
[3,6]

Traversal:
[1,4] -> Keep (maxEnd = 4)
[2,8] -> Keep (maxEnd = 8)
[3,6] -> Covered (6 <= 8)

Answer = 2

Time: O(n log n) (sorting and traversal)
Space: O(1)
*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        /* Sorting by start ascending guarantees all previous intervals start no later than the current one.
        Sorting by end descending for equal starts ensures the largest interval appears before smaller intervals with the same start */
         
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });

        int count = 0;
        //the farthest ending point seen so far
        int maxEnd = 0;

        for (auto &interval : intervals) {
            // If the current interval's end is greater than the farthest end seen so far, it is not covered
            if (interval[1] > maxEnd) {
                count++;
                maxEnd = interval[1];
            }
        }
        return count;
    }
};