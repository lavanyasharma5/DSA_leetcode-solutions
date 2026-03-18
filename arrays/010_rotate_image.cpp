/*
Problem: Rotate Image
Link: https://leetcode.com/problems/rotate-image/
Difficulty: Medium

Idea:
Rotate matrix 90° clockwise.

Step 1: Transpose the matrix
Step 2: Reverse each row

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==0) return;

        for(int i=0; i<n; i++){ // Iterate through each row
            for(int j=i+1; i<n; j++){ // Start from j=i+1 to avoid swapping elements twice
                swap(matrix[i][j], matrix[j][i]); // Transpose the matrix
            }
        }

        //reverse each row
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end()); // Reverse each row to get the
        }       
    }
};
