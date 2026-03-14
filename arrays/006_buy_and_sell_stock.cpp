/*
Problem: Best Time to Buy and Sell Stock
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Difficulty: Easy

Idea:
Traverse the array once.
Keep track of minimum price so far.
At each step calculate profit.

profit = price - minimum

Update max profit.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini= prices[0]; // Initialize mini to the first price
        int profit=0; // Initialize profit to 0

        for(int i=0; i<n; i++){
            int cost = prices[i]-mini; // Profit if we sell at current price
            profit= max(profit, cost); // Update profit if current cost is greater
            mini= min(mini, prices[i]); // Update mini if current price is lower
        }
        return profit;
    }
};