/*
problem: Search a 2D Matrix
link: https://leetcode.com/problems/search-a-2d-matrix/
difficulty: Medium

Description:
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
This matrix has the following properties:
- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

Approach:
- We can treat the 2D matrix as a 1D sorted array and apply binary search
- We will calculate the mid index in the flattened array and convert it back to 2D indices to compare with the target
- If the mid value is equal to the target, we return true
- If the mid value is less than the target, we search in the right half
- If the mid value is greater than the target, we search in the left half

Time Complexity: O(log(m*n)) which is O(log(m) + log(n))
Space Complexity: O(1)
*/

#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int low=0;
        int high=n*m-1;

        while(low <= high){
            int mid = (low + high) >> 1; //mid index in the flattened array

            //convert 1D index into 2D index
            int row = mid / m; //row index
            int col = mid % m; //column index
            int mid_value = matrix[row][col]; //value at mid index

            if(mid_value == target) return true; //target found
            else if(mid_value < target) low = mid + 1; //search in the right half
            else high = mid - 1; //search in the left half
        }
        return false;
    }
};