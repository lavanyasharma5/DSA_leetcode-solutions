/*
Problem: Majority Element II (n/3 times)
Link: https://leetcode.com/problems/majority-element-ii/
Difficulty: Medium

Idea:
Find elements appearing more than n/3 times.

At most 2 such elements exist.

Use Moore’s Voting Algorithm (extended):
- Maintain 2 candidates and counts
- First pass finds candidates
- Second pass verifies them

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
    public:
    vector<int> majorityElement(vector<int>& nums){
        //Boyer-Moore Majority Vote Algorithm
        int n=nums.size();
        
        // We can have at max 2 majority elements in an array
        int count1=0, count2=0;
        // el1 and el2 are the 2 majority elements
        int el1=0, el2=0;

        //first pass to find the 2 majority elements
        for(int i=0; i<n; i++){

            // If count1 is 0 and the current element is not el2
            //then we can consider the current element as a potential majority element and update el1 and count1 accordingly.
            if(count1==0 && nums[i] != el2){
                count1++;
                el1=nums[i];
            }
            else if(count2==0 && nums[i] != el1){
                count2++;
                el2=nums[i];
            }
            // If the current element is equal to el1, we increment count1.
            else if(nums[i]==el1){
                count1++;
            }
            // If the current element is equal to el2, we increment count2.
            else if(nums[i]==el2){
                count2++;
            }
            // If the current element is different from both el1 and el2, we decrement both count1 and count2.
            else{
                count1--, count2--;
            }
        }
        vector<int> ls; // To store the majority elements
        count1=0, count2=0; // Reset counts for verification

        //second pass to verify the candidates
        for(int i=0; i<n; i++){
            if(nums[i]==el1) count1++;
            else if(nums[i]==el2) count2++;
        }

        // To be a majority element, it must appear more than n/3 times
        int mini= (n/3)+1;
        if(count1>=mini) ls.push_back(el1);
        if(count2>=mini && el2 != el1) ls.push_back(el2); // Check el2 != el1 to avoid duplicates if both candidates are the same

        return ls;
    }
};