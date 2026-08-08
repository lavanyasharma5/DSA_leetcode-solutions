/*
Problem: Sudoku Solver
link: https://leetcode.com/problems/sudoku-solver/
difficulty: Hard

Description:
Fill the empty cells of a 9x9 Sudoku board so that every row,
column, and 3x3 box contains the numbers 1-9 exactly once.

Approach:
1. Use backtracking to solve the Sudoku.
2. Find an empty cell and try numbers from 1 to 9.
3. Check if the number is valid in the current row, column,
   and 3x3 box.
4. If valid, place the number and recursively solve the board.
5. If the choice leads to a dead end, undo it and try another number.
6. When no empty cells remain, the Sudoku is solved.

Why it works:
- Every number is checked against all three Sudoku rules.
- Backtracking allows us to undo wrong choices and try alternatives.

Time: O(9^E)
      E = number of empty cells

Space: O(E)
       Recursion stack (excluding the board)
*/

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char num){

        for(int i=0; i< board.size(); i++){

            //check for row
            if(board[row][i] == num) return false;

            //check for column
            if(board[i][col] == num) return false;

            //check for 3*3 block
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        //check for each sell in the board 
        for(int row=0; row < board.size(); row++){
            for(int col = 0; col < board.size(); col++){

                //empty cell found
                if(board[row][col] == '.'){
                    //try to place numbers from 1-9
                    for(char num = '1'; num <= '9'; num++){
                        
                        //check if its safe to place the number in that cell 
                        if(isSafe(board, row, col, num)){

                            //place the number in that cell
                            board[row][col] = num;

                            if(solve(board)){
                                return true;
                            }
                            else{
                                //backtrack
                                board[row][col] = '.';
                            }
                        }
                    }
                    //no number worked
                    return false;
                }
            }
        }
        return true; 
        //means no empty cell is left so the board is filled with a valid sequence
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};