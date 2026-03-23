/*
Problem: Longest Consecutive Sequence
Link: https://leetcode.com/problems/longest-consecutive-sequence/
Difficulty: Medium

Idea:
Use unordered_set to store all elements.
For each number, check if it is the start of a sequence
(i.e., number-1 is not present).
Then count how long the sequence continues.

This avoids sorting and gives O(n) average time.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;

        int longest=1;
        //we can use hash set to check if the number exists in O(1) time
        unordered_set<int> st(nums.begin(), nums.end());

        for(auto it: st){
            //we only start counting if the previous number is not present in the set
            // this way we ensure that we are counting the longest sequence starting from the smallest number in the sequence
            if(st.find(it-1)==st.end()){
                int count=1; //founf the first number in the sequence
                int x= it; //we start counting from the current number
                
                // we keep counting until we find the next number in the sequence
                //we stop counting when we find a number that is not in the set
                // which means we have reached the end of the current sequence
                while(st.find(x+1)!=st.end()){
                    count++; 
                    x++; // we move to the next number in the sequence
                }
                longest = max(longest, count);
            }
        }       
        return longest;
    }
};