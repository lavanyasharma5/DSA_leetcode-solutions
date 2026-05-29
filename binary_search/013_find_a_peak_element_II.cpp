/*
problem: Find a Peak Element II
link: https://leetcode.com/problems/find-a-peak-element-ii/
difficulty: Medium

Description:
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom. 
Given a 0-indexed 2D integer array mat where mat[i][j] represents the element at position (i, j)
return the position of any peak element in mat.

Approach:
- Use binary search on the columns of the matrix.
- Pick the middle column and find the maximum element in that column.
- Compare this element with its left and right neighbors.
- If it is greater than both, it is a peak, so return its position.
- If the left neighbor is greater, a peak must exist in the left half, so search left.
- Otherwise, a peak must exist in the right half, so search right.
- Repeat until a peak element is found.

Time Complexity: O(n log m) 
Space Complexity: O(1) 
*/

#include <vector>
using namespace std;

class Solution {
public:

    int maxRowInd(vector<vector<int>>& mat, int n, int m, int col){
        int maxi= -1;
        int ind= -1;
        for(int i=0; i<n; i++){
            if(mat[i][col] > maxi){
                maxi = mat[i][col];
                ind= i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();

        int low=0;
        int high= m-1; //binary search on columns 

        while(low <= high){
            int mid= (low + high)/2; //pick middle column 

            //find the row containing the max element in the column mid
            int row = maxRowInd(mat, n, m, mid);

            //get left  and right neighbour
            //if no left or right neighbour exists take -1
            int left= (mid-1 >= 0) ? mat[row][mid - 1] : -1;
            int right= (mid+1 < m) ? mat[row][mid + 1] : -1;

            //check for peak element
            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row, mid};
            }
            //the left element is bigger so move left and eliminate the right half 
            else if(mat[row][mid] < left){
                high = mid-1;
            }
            //the right element is bigger so move right and eliminate the left half
            else{
                low = mid+1;
            }
        }
        return {-1, -1};
    }
};