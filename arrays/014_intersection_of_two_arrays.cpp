/*
Problem: Intersection of Two Arrays
link: https://leetcode.com/problems/intersection-of-two-arrays/
Difficulty: Easy

Idea:
Sort both arrays and use two pointers.

If equal → add to answer (avoid duplicates)
by checking if its already added in ans and move both pointers
If smaller → move pointer respective to smaller element

Time: O(n log n)
Space: O(1) extra
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int a=nums1.size();
        int b=nums2.size();
        //sort both arrays to use two pointers
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0; //pointer for nums1
        int j=0; //pointer for nums2
        vector<int> ans;

        while(i<a && j<b){
            
            if(nums1[i]<nums2[j]){
                i++; //move pointer of smaller element
            }
            else if(nums1[i]>nums2[j]){
                j++; 
            }
            else{ //nums1[i] == nums2[j]
                //check if its already added in ans to avoid duplicates
                if(ans.empty() || ans.back() != nums1[i]){
                    ans.push_back(nums1[i]);
                }
                //move both pointers forward 
                i++;
                j++;
            }
        }
        return ans;
    }
};