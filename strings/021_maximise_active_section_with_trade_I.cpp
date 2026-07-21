/*
Problem: Maximize Active Section with Trade I
Link: https://leetcode.com/problems/maximize-active-section-with-trade-i/
Difficulty: Medium

Description:
Given a binary string representing active (1) and inactive (0) sections,
perform exactly one valid trade to maximize the number of active sections.

A trade consists of:
1. Converting one block of consecutive 1's surrounded by 0's into 0's.
2. Converting the newly merged block of consecutive 0's surrounded by 1's into 1's.

Return the maximum number of active sections after one trade.

Approach:
1. Traverse the string block by block instead of character by character.
2. Count the total number of existing 1's.
3. Track the length of the previous zero block.
4. Whenever another zero block is found, calculate the gain obtained by
   merging the two zero blocks separated by a single one block.
5. Keep the maximum possible gain and add it to the original count of 1's.

Why it works:
- Removing a surrounded block of 1's merges its neighboring zero blocks.
- The removed 1's are added back when the merged zero block is flipped,
  so they contribute no net gain.
- The only new active sections come from the surrounding zero blocks,
  making the gain equal to the sum of the two adjacent zero block lengths.
- Scanning the string block by block allows us to compute the maximum gain
  in a single pass.

Time: O(n)
Space: O(1)
*/

#include<string>
#include<algorithm>
using namespace std;

class Solution{
public:
    int maxActiveSectionsAfterTrade(string s){
        int n= s.size();

        int ans=0; // Count of existing 1's
        int preZeroes = INT_MIN; // Length of the previous zero block
        int maxZeroes = 0; //Maximum gain obtained so far

        for(int i=0; i<n;){ // Traverse the string block by block
            int j=i; // Find the end of the current block of identical characters

            while(j<n && s[j]==s[i]){ // Move j to the end of the current block
                j++;
            }

            int blocklength = j-i; // Length of the current block

            // If the current block is a block of 1's, add its length to the count of existing 1's
            if(s[i] == '1'){
                ans += blocklength;
            }
            else{
                // If the current block is a block of 0's, calculate the gain obtained by merging it with the previous zero block
                maxZeroes = max(maxZeroes, blocklength);
                preZeroes = blocklength; // Update the length of the previous zero block
            }

            i=j; // Move to the next block
        }
        // If there are no 1's in the string, we can flip one block of 0's to 1's, so the maximum gain is the length of the longest block of 0's
        return ans + maxZeroes;
    }
};