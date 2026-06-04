/*
problem: 14. Longest Common Prefix
link: https://leetcode.com/problems/longest-common-prefix/
difficulty: Easy

Description:
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Approach:
1. We can take the first string in the array as the initial prefix.
2. We then iterate through each string in the array and check if the current prefix is a prefix of the current string.
3. If it is not, we remove the last character from the prefix and check again until we find a common prefix or the prefix becomes empty.
4. If the prefix becomes empty, we return an empty string. 
5. Otherwise, we return the longest common prefix found after iterating through all the strings.

Time Complexity: O(n*m) where n is the number of strings and m is the length of the longest common prefix.
Space Complexity: O(1) since we are using only a constant amount of extra space for the prefix string.
*/

#include<string>
#include<vector>
using namespace std;

class Solution{	
	public:
		string longestCommonPrefix(vector<string>& str){
			//take the first string in the array about the 
            string prefix= str[0];

            //iterate through each string in the array
            for(int i=0; i<str.size(); i++){
                //check if the current prefix is a prefix of the current string
                while(str[i].find(prefix) != 0){
                    //if not, remove the last character from the prefix and check again
                    prefix.pop_back(); 
                }
                //if the prefix becomes empty, return an empty string
                if(prefix.empty()) return ""; 
            }
            return prefix;
		}
};