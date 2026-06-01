/*
problem: Minimum Cost of Buying Candies With Discount
link: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount
difficulty: Easy

Description:
A shop is selling candies at a discount. 
For every two candies sold, the shop gives a third candy for free. 
The customer can choose any candy to take for free as long as they buy two other candies.
Given an integer array cost where cost[i] is the price of the ith candy, return the minimum cost of buying all the candies.

Approach:
we want to minimize the cost, so we should take the most expensive candy for free.
and the cost of the free candy should be <= min(cost of the two candies we bought).
-sort the cost array in descending order.
-iterate through the sorted array and add the cost of every candy to the answer except for every 3rd candy 
  (i.e., when (i+1) % 3 == 0), which is free.

Time Complexity: O(n log n) due to sorting.
Space Complexity: O(1) 
*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost){
        sort(cost.begin(), cost.end(), greater<int>());

        int ans=0;
        for(int i=0; i< cost.size(); i++){
            if( (i+1) % 3 != 0){ //every 3rd candy is free
                ans += cost[i];
            }
        }
        return ans;
    }
};