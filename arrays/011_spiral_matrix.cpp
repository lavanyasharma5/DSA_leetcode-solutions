/*
Problem: Spiral Matrix
Link: https://leetcode.com/problems/spiral-matrix/
Difficulty: Medium

Idea:
Use four boundaries:
top, bottom, left, right.

Traverse:
left → right
top → bottom
right → left
bottom → top

After each traversal, move boundary inward.

Time Complexity: O(m*n)
Space Complexity: O(1) extra
*/

#include<vector>
#include<iostream>
using namespace std;


class Solution {
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m= matrix.size(); // Number of rows
        if(m==0) return {};
        int n=matrix[0].size(); // Number of columns

        int left=0, right=n-1; // Initialize left and right boundaries
        int top=0, bottom=m-1; // Initialize top and bottom boundaries

        vector<int> ans;

        while(left<=right && top<=bottom){

            // Traverse from left to right
            for(int i=left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++; // Move top boundary down

            // Traverse from top to bottom
            for(int i=top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--; // Move right boundary left

            //conditional check to avoid duplicate traversal when boundaries overlap
            //case when there is only one row or one column left

            if(top<=bottom){

                // Traverse from right to left
                for(int i=right; i>=left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--; // Move bottom boundary up
            }

            if(left<=right){

                // Traverse from bottom to top
                for(int i=bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++; // Move left boundary right
            }
        }
        return ans;
    }
};