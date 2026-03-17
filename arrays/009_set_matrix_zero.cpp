/*
Problem: Set Matrix Zeroes
Link: https://leetcode.com/problems/set-matrix-zeroes/
Difficulty: Medium

Idea:
Use first row and first column as markers.

If matrix[i][j] == 0,
mark matrix[i][0] and matrix[0][j] as 0.

Use a separate variable to track first column.

Then update matrix using markers.

Time Complexity: O(n*m)
Space Complexity: O(1)
*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==0) return;
        int m= matrix[0].size();
        int col0=1;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }else{
                        col0=0;
                    }
                }
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j=0; j<m; j++){
                matrix[0][j]=0;
            }
        }
        if(col0==0){
            for(int i=0; i<n; i++){
                matrix[i][0]=0;
            }
        }
    }
};

