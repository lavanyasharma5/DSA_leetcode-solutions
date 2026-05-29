/*
problem: Minimum Element After Replacement With Digit Sum
link: https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/
difficulty: Easy

Description:
You are given a 0-indexed integer array nums. You can apply the following operation on nums any number of times:
- Choose an index i such that 0 <= i < nums.length and nums[i] >= 10.
- Replace nums[i] with the sum of the digits of nums[i].
Return the minimum element in nums after applying the operation any number of times.

Approach:
- We can iterate through each number in the array 
- calculate the sum of its digits until we get a single digit number (less than 10)
- We keep track of the minimum single digit number we encounter during this process

Time Complexity: O(n * d) where n is the number of elements in the array and d is the number of digits in the largest number
Space Complexity: O(1) 
*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    int minElement(vector<int>& nums){
        int ans= INT_MAX;

        //calculate the sum of digits for each number and find the minimum
        for(int num: nums){
            int sum=0;
            //calculate the sum of digits for the current number
            while(num > 0){
                sum += num % 10; //add the last digit to the sum
                num /= 10; //remove the last digit from the number
            }
            ans= min(ans, sum); //update the minimum sum of digits found so far
        }
        return ans;
    }
};
