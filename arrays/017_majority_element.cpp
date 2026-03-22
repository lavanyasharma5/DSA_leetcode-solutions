/*
Problem: Majority Element
Link: https://leetcode.com/problems/majority-element/
Difficulty: Easy

Idea:
Use Moore’s Voting Algorithm.

Keep a candidate and count.
If count becomes 0 → choose new candidate.
Increase count if same, decrease if different.

Majority element always exists.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
    public:
    int majorityElement(vector<int>& nums){
        int n= nums.size();
        //Boyer-Moore Majority Vote Algorithm
        int el=-1; //the candidate element for majority
        int count=0; //the count of the candidate element

        for(int i=0; i<n; i++){
            //if count is 0, we can choose the current element as the candidate
            if(count==0){
                el= nums[i];
                count=1; //reset the count to 1 for the new candidate
            }
            else if(el == nums[i]){
                //if the current element is the same as the candidate, we increment the count
                count++; 
            }
            else{
                //if the current element is different from the candidate, we decrement the count
                count--;
            }
        }
        //After the first pass, we have a candidate for the majority element, but we need to verify it
        int count1=0;
        for(int i=0; i<n; i++){
            if(nums[i] == el){
                count1++;
            }
        }
        //If the count of the candidate element is greater than n/2, we return it as the majority element. Otherwise, we return -1 to indicate that there is no majority element.
        if(count1 > n/2){
            return el;
        }else{
            return -1;
        }
    }

};