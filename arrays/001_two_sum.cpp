/*
Problem: Two Sum
Link: https://leetcode.com/problems/two-sum/
Difficulty: Easy

Approach:
Use a hashmap to store numbers we have seen.
For each number check if (target - number) already exists.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
#include <unordered_map>
using namespace std;

class solution{
    public:
    vector<int> twoSum(vector<int> &nums, int target){
        unordered_map<int, int> mpp; // number -> index
        for(int i=0; i<nums.size(); i++){
            int n= nums[i];
            int num= target-x;
            if(mpp.find(num) != mpp.end()){
                return {mpp[num], i};
            }
            mpp[n]= i;
        }
        return {-1, -1}; //not found 
    }
}