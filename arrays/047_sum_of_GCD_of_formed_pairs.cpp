/*
    Problem: 3867. Sum of GCD of Formed Pairs
    Link: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/
    Difficulty: Medium

    Description:
    Given an integer array, first construct a prefixGcd array where:
    - prefixMax[i] is the maximum element from index 0 to i.
    - prefixGcd[i] = gcd(nums[i], prefixMax[i]).

    Sort the prefixGcd array, then repeatedly pair the smallest
    remaining element with the largest remaining element.
    Compute the GCD of each pair and return the sum of all GCD values.
    If one element remains unpaired, ignore it.

    Approach:
    1. Build the prefix maximum array.
    2. Compute the prefixGcd array using Euclid's GCD algorithm.
    3. Sort the prefixGcd array.
    4. Use two pointers to pair the smallest and largest elements.
    5. Compute the GCD of every pair and accumulate the answer.

    Why it works:
    - The prefix maximum array provides the required maximum value
      for every index.
    - Computing gcd(nums[i], prefixMax[i]) correctly constructs
      the prefixGcd array.
    - Sorting allows pairing the smallest and largest elements
      exactly as specified.
    - Two pointers efficiently process every valid pair once.

    Time: O(n log n)
    Space: O(n)
*/

#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution{
public:
    long long gcdSum(vector<int>& nums) {
        int n= nums.size();

        //1. Build the prefix maximum array
        vector<int> prefixMax(n);
        //the first element of prefixMax is the first element of nums
        prefixMax[0] = nums[0];

        for(int i=1; i<n; i++){
            prefixMax[i] = max(prefixMax[i-1], nums[i]);
        }

        //2. Build the prefixGcd array
        vector<int> prefixGcd(n);
        for(int i=0; i<n; i++){
            prefixGcd[i] = gcd(nums[i], prefixMax[i]);
        }

        //3. Sort the prefixGcd array
        sort(prefixGcd.begin(), prefixGcd.end());

        //4. Use two pointers to pair the smallest and largest elements
        long long ans = 0;
        int left = 0, right = n - 1;
        while(left < right){
            ans += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return ans;
    }
};