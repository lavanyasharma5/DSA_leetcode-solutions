/*
problem: 1781. Sum of Beauty of All Substrings
link: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/
difficulty: Medium

Description:
The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.    
Example 1:
Input: s = "aabcb"
Output: 5

Approach:
1. Iterate through all possible starting indices of the string.
2. Maintain a frequency array of size 26 while extending the substring one character at a time.
3. For each substring, update the character frequency and find the maximum and minimum non-zero frequencies.
4. Compute the beauty as maxFreq - minFreq and add it to the answer.
5. Return the total beauty sum of all substrings.

Time Complexity: O(n^2 * 26) = O(n^2), where n is the length of the string.
Space Complexity: O(26) = O(1) for the frequency array, and O(1) for the variables used to compute beauty.
*/

#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n= s.size();
        int ans=0;

        for(int i=0; i<n; i++){
            //for each substring maintain a freq vector of the characters
            vector<int> freq(26,0);

            //keep adding characters one by one to get the subsequent substrings
            for(int j=i; j<n; j++){
                //update the frequency of the current character
                freq[s[j] - 'a'] ++;

                int maxi = 0;
                int mini = INT_MAX;

                //for each subsequent substring get the maximum and the minimum occuring character 
                for(int f: freq){
                    //only consider the characters which are present in the substring
                    if(f>0){
                        mini = min(mini, f);
                        maxi = max(maxi, f);
                    }
                }
                //add the beauty of the current substring to the answer
                ans += (maxi-mini);
            }
        }
        return ans;
    }
};