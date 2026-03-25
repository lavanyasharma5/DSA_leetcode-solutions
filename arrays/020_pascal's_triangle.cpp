/*
Problem: Pascal's Triangle
Link: https://leetcode.com/problems/pascals-triangle/
Difficulty: Easy

Idea:
Each row of Pascal triangle contains binomial coefficients.
Instead of computing factorial, we use formula:

nCr = nCr-1 * (n-r) / r

Build each row using previous value.
First element is always 1.
Next subsequent element = previous element × (row − col) / col 
Last element becomes 1 because in final step formula becomes
ans = ans × 1 / (n-1), which always gives 1.

Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

#include <vector>
using namespace std;

class Solution{
    public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        // we generate each row of the pascal triangle and add it to the answer
        for(int row=1; row<= numRows; row++){
            //generate ecah row using the pascal function
            ans.push_back(pascal(row)); 
        }
        return ans;
    }
    vector<int> pascal(int n){      
        vector<int> row;
        row.push_back(1); // first element of every row is 1

        long long ans=1; // we use long long to avoid overflow for large n, as the values can get very large
        for(int col=1; col<n; col++){
            // we start from the second element (col=1)(0 based indexing)
            //and calculate each element using the previous one

            ans= ans*(n-col);
            ans= ans/col;
            row.push_back(ans);
        }
        return row;
    }
};