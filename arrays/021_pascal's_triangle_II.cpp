/*
Problem: Pascal's Triangle II
Link: https://leetcode.com/problems/pascals-triangle-ii/
Difficulty: Easy

Idea:
We need only one row of Pascal's Triangle (0-indexed).

Use binomial coefficient formula:
nCr = nCr-1 * (n-r+1) / r

Instead of factorial, generate each element from previous one.

First element is always 1.
Each next element can be calculated using previous value.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
using namespace std;

class Solution{
    public:
    vector<int> getRow(int rowIndex){
        vector<int> row;
        row.push_back(1); //first element of every row is 1 
        long long ans=1; // we use long long to avoid overflow for large n

        for(int col=1; col <= rowIndex; col++){
            // we calculate the next element using the previous one
            ans= ans*(rowIndex-col+1); 
            ans= ans/col;
            row.push_back(ans);
        }
        return row;
    }
};