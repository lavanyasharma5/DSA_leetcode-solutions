/*
Problem: Find Closest Number to Zero
Link: https://leetcode.com/problems/find-closest-number-to-zero/
Difficulty: Easy

Idea:
Compare absolute values.
Smaller absolute value -> closer to 0
If tie → choose positive number.

Time: O(n)
Space: O(1)
*/

#include<vector>
#include<cmath>
using namespace std;

class soluion{
    public:
    int findClosestNumber(vector<int>& nums){
        int ans= INT_MAX; //initialise ans to max value 

        for(int i=0; i<nums.size(); i++){

            // If the absolute value of the current element is less than the absolute value of ans
            // we update ans to the current element.
            if(abs(nums[i]) < abs(ans)){
                ans= nums[i];
            }
            // If the absolute value of the current element is equal to the absolute value of ans 
            // and the current element is greater than ans, we pick the greater number 
            else if(abs(nums[i]) == abs(ans) && nums[i] > ans){
                ans= nums[i];
            }
        }
        return ans;
    }

};