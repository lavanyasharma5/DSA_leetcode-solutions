/*
Problem: 1260. Shift 2D Grid
Link: https://leetcode.com/problems/shift-2d-grid/
Difficulty: Easy

Description:
Given an m × n grid and an integer k, shift every element of the grid
to the right by k positions. The last element wraps around to the first
position. Return the grid after performing all shifts.

Approach:
1. Treat the 2D grid as a virtual 1D array.
2. Compute the 1D index of each element using:
      index = row * n + col
3. Calculate its new position after k shifts:
      newIndex = (index + k) % (m * n)
4. Convert the new 1D index back to 2D coordinates:
      newRow = newIndex / n
      newCol = newIndex % n
5. Place the element in its new position in the answer grid.

Why it works:
- Viewing the grid as a single linear array simplifies the shifting process.
- Modulo handles wrap-around automatically when the index exceeds the total
  number of elements.
- Every element is moved exactly once to its correct final position without
  performing k individual shifts.

Time: O(m × n)
Space: O(m × n)
*/

#include<vector>
using namespace std;

class Solution{
    public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k){
        int m = grid.size();
        int n = grid[0].size();

        // Create a new 2D vector to store the shifted grid
        vector<vector<int>> ans(m, vector<int>(n)); 

        int total = m * n;

        // Since shifting by total elements results in the same grid, we can reduce k
        k %= total;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int index = i * n + j; // Convert 2D index to 1D index

                int newIndex = (index + k) % total; // Calculate the new index after shifting

                int newRow = newIndex / n; // Convert the new 1D index back to 2D index
                int newCol = newIndex % n; // Calculate the new column index

                ans[newRow][newCol] = grid[i][j]; // Place the element in the new position
            }
        }
        return ans;
    }
};