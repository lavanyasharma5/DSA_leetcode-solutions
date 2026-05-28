/*
problem: Search a 2D Matrix II
link: https://leetcode.com/problems/search-a-2d-matrix-ii/
difficulty: Medium

Description:
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
This matrix has the following properties:
- Integers in each row are sorted in ascending from left to right.
- Integers in each column are sorted in ascending from top to bottom.

Approach:
- We can start from the top right corner of the matrix
- If the current element is equal to the target, we return true
- If the current element is greater than the target, we can move left to find smaller elements
- If the current element is smaller than the target, we can move down to find larger elements
- We continue this process until we find the target or go out of bounds

Time Complexity: O(m + n) because in the worst case we will traverse at most m rows and n columns
Space Complexity: O(1) because we are using only constant extra space
*/

#include<vector>
using namespace std;

class Solution {
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n= matrix.size();
        int m= matrix[0].size();

        //start from thr top right corner
        //down -> numbers are increasing
        //left -> numbers are decreasing
        int row=0;
        int col= m-1;

        while(row < n && col >= 0){
            //target found at the position
            if(matrix[row][col] == target) return true;
            //current element is greater so go left
            else if(target < matrix[row][col]) col--;
            //current element is smaller so go down
            else row++;
        }
        return false;
    }
};