/*
Problem: Find the Prefix Common Array of Two Arrays
Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
Difficulty: Medium

Description:
You are given two 0-indexed integer permutations nums1 and nums2 of size n.
A prefix common array of nums1 and nums2 is an array ans of size n such that a
ns[i] is equal to the count of numbers that are present at or before the index i in both nums1 and nums2.
Return the prefix common array of nums1 and nums2.

Approach:
- Create an answer array ans of size n initialized to 0.
- Create a frequency array freq of size n+1 initialized to 0 to count occurrences of
    numbers in both arrays.
- Initialize a variable common to keep track of the count of common elements.
- Iterate through the arrays from 0 to n-1:
    - Increment the frequency of nums1[i] and check if it becomes 2 (indicating it's common in both arrays), if so, increment common.
    - Increment the frequency of nums
    - Increment the frequency of nums2[i] and check if it becomes 2, if so, increment common.
    - Set ans[i] to the current value of common.
- Return the ans array.

Why this works:
By using a frequency array, we can efficiently track how many times each number has appeared in both arrays. 
When a number's frequency reaches 2, it means it has appeared in both arrays, and we can count it as a common element.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
using namespace std;

class Solution{
    public:
    vector<int> findThePrefixCommonArray(vector<int>& nums1, vector<int>& nums2){
        int n= nums1.size();
        vector<int> ans(n,0); //to store the count of common elements at each index

        //this stores the frequency of each number
        //how many time x has appeared in nums1 and nums2 BOTH
        vector<int> freq(n+1, 0);

        int common=0; //to keep track of common elements

        for(int i=0; i<n; i++){
            freq[nums1[i]] ++; //increment frequency for nums1[i]

            if(freq[nums1[i]] == 2){
                common++;
            }

            freq[nums2[i]] ++; //increment frequency for nums2[i]

            if(freq[nums2[i]] == 2){
                common++;
            }

            ans[i] = common; //store the count of common elements at index i
            
        }
        return ans; //return the result array
    }
};