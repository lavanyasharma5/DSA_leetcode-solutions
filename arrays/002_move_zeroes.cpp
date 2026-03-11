/*
Problem: Move Zeroes
Link: https://leetcode.com/problems/move-zeroes/
Difficulty: Easy

Idea:
We move all non-zero numbers to the front of the array.
We use two pointers.

i → scans the array
j → position where next non-zero should go

When we find a non-zero number,
we swap it with position j and move j forward.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class solution{
    public:
    void moveZeroes(vector<int> &nums){
        int j=-1;
        //find the first zero
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                j=i;
                break;
            }
        }
        if(j==-1) return; //no zeroes

        for(int i=j+1; i<nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};