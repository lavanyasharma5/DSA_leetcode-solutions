/*
    Problem: 79. Word Search
    Link: https://leetcode.com/problems/word-search/
    Difficulty: Medium

    Description:
    Given a 2D board of characters and a word, determine whether
    the word can be formed by moving through adjacent cells
    (up, down, left, or right). Each cell can be used only once.

    Approach:
    1. Traverse every cell of the board.
    2. If a cell matches the first character of the word,
       start DFS from that cell.
    3. At each step:
       - Check if the current character matches.
       - Mark the current cell as visited.
       - Explore all four directions.
       - Backtrack by restoring the original character.
    4. If all characters of the word are matched,
       return true.
    5. If no starting cell can form the word,
       return false.

    Why it works:
    - DFS explores every possible path for the word.
    - Marking cells as visited prevents reusing
      the same cell in one path.
    - Backtracking restores the board so other
      paths can reuse the cell.
    - Returning true immediately stops the search
      once a valid path is found.

    Time: O(m * n * 4^L)
          where:
          m = number of rows
          n = number of columns
          L = length of the word

    Space: O(L)
           Recursive call stack
           (excluding the board and input)
*/

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int m,n; //sizes as global variables so we dont hv to pass them in any function

    //directions: Down, Up, Right, Left
    vector<vector<int>> directions = {
        {1,0},
        {-1,0}, 
        {0, 1},
        {0, -1}
    };

    bool find(vector<vector<char> >& board, int i, int j , int idx, string word){

        //base case
        //all characters matched
        if(idx == word.length()){
            return true;
        }

        //out of bounds or already visited
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$')
            return false;

        //character doesn't match
        if (board[i][j] != word[idx])
            return false;

        // Mark current cell as visited
        // store it as well in case of backtracking
        char temp = board[i][j];
        board[i][j] = '$';

        // Explore all 4 directions
        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (find(board, new_i, new_j, idx + 1, word))
                return true;
        }

        //back track
        board[i][j] = temp;

        return false;
    }

    bool exist(vector<vector<char> >& board, string word) {
        m = board.size(); //rows
        n= board[0].size(); //columns

        //try every cell 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(board[i][j] == word[0] && find(board, i , j, 0, word))
                    return true;
            }
        }
        return false;
    }
};