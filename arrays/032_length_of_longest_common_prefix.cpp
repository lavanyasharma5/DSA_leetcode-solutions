/*
Problem: Find the Length of the Longest Common Prefix
Link: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
Difficulty: Medium

Description:
You are given two integer arrays arr1 and arr2.

A prefix of a number is formed by taking digits from the left side.
For example:
- Prefixes of 12345 are: 1, 12, 123, 1234, 12345

The task is to find the maximum length of a common prefix
between any pair of numbers where:
- one number is taken from arr1
- one number is taken from arr2
so like every number in arr1 is compared with every number in arr2 to find the longest common prefix.
Return the length of the longest common prefix.
If no common prefix exists, return 0.

Approach:
- Store all possible prefixes of numbers from arr1 in a hash set.
- For every number in arr2:
    - Generate its prefixes one by one.
    - Check if the prefix exists in the set.
    - Update the maximum prefix length found.

Why this works:
If a prefix from arr2 exists in the set,
it means the same prefix also appeared in arr1,
so we found a common prefix.

Time Complexity: O((n + m) * d)
Space Complexity: O(total prefixes stored)
*/

#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
    public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2){
        //store all prefixes of arr1 in a set
        unordered_set<int> prefixes;

        //for each number in arr1, insert all its prefixes into the set
        for(auto num: arr1){
            prefixes.insert(num);
            num /= 10;
        }
        int longest = 0;

        //for each number in arr2, check if any of its prefixes is in the set
        for(auto num: arr2){
            //check if any prefix of num is in the set
            if(prefixes.count(num)){
                longest = max(longest, (int)to_string(num).length());
            }
            num /= 10;
        }
        return longest; //return the length of the longest common prefix
    }
};