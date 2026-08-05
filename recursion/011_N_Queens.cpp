/*
    Problem: 51. N-Queens
    Link: https://leetcode.com/problems/n-queens/
    Difficulty: Hard

    Description:
    Place n queens on an n x n chessboard such that no two queens
    attack each other. A queen attacks horizontally, vertically,
    and diagonally. Return all valid board configurations.

    Approach:
    1. Use backtracking and place one queen per column.
    2. Before placing a queen, check if the row and both diagonals
       are free using three hash arrays:
         - leftRow[row]
         - lowerDiagonal[row + col]
         - upperDiagonal[n - 1 + col - row]
    3. If the position is safe:
         - Place the queen.
         - Mark the row and diagonals as occupied.
         - Recurse for the next column.
         - Backtrack by removing the queen and unmarking them.
    4. When all columns are filled, store the current board.

    Why it works:
    - Only one queen is placed in each column.
    - Hash arrays allow O(1) safety checks.
    - Backtracking explores every valid arrangement while undoing
      previous choices to try other possibilities.

    Time: O(N!)
          (Backtracking explores all valid queen placements.)

    Space: O(N)
           (Recursion stack + three hash arrays.
            Output space is not included.)
*/

#include<vector>
#include<string>
using namespace std;
class Solution {
public:

    void solve(int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n){
        //base case
        //all queens hv been placed in the cols
        if(col == n){
            ans.push_back(board);
            return;
        }

        //try every row
        for(int row=0; row<n; row++){
            
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[(n-1) + (col-row)] == 0){

                //safe so place the queen at that row and col
                board[row][col] = 'Q';

                //and write 1 in the respective hashsets
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[(n-1) + (col-row)] = 1;

                //recursively place the next queen in the next col
                solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

                //backtrack
                board[row][col] = '.';

                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[(n-1) + (col-row)] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board(n);

        string s(n, '.'); //one row Eg -> ". . . ." for n=4

        //fill board
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        
        //define the three hashsets
        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);

        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        //0 means start placing queens from the 0th column

        return ans;
    }
};