/*
problem: 3739. Count Subarrays With Majority Element II
link: https://leetcode.com/problems/count-subarrays-with-majority-element-ii/
difficulty: hard

Description:
You are given an integer array nums and an integer target.
Return the number of subarrays in which target appears
strictly more than half of the total elements, making it
the majority element.

Approach:
1. Replace every occurrence of target with +1 and every
   other element with -1.
2. Compute the prefix sum array of the transformed values.
3. A subarray has target as majority if its transformed
   sum is positive.
4. Maintain frequencies of previous prefix sums using an
   offset array to handle negative sums.
5. Incrementally track the number of valid previous prefix
   sums that produce a positive subarray sum.
6. Add the count of valid subarrays ending at each index
   to the final answer.

Example:
nums = [1,2,2,3], target = 2
After transformation:
[-1, 1, 1, -1]
Prefix sums:
[-1, 0, 1, 0]
Positive-sum subarrays correspond to subarrays where
target is the majority.
Answer = 5

Time: O(n)
Space: O(n)
*/

#include<vector>
using namespace std;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long cnt = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) nums[i] = 1;
            else nums[i] = -1;
        }

        vector<int> pref(n);
        pref[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }

        int shift = n;
        vector<int> freq(2 * n + 1, 0);

        freq[shift] = 1;

        long long valid = 0;
        int lastSum = 0;

        for (int i = 0; i < n; i++) {
            if (pref[i] > lastSum) {
                valid += freq[lastSum + shift];
            } else {
                valid -= freq[pref[i] + shift];
            }

            cnt += valid;
            freq[pref[i] + shift]++;
            lastSum = pref[i];
        }
        return cnt;
    }
};