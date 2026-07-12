/*
    Problem: 1331. Rank Transform of an Array
    Link: https://leetcode.com/problems/rank-transform-of-an-array/
    Difficulty: Easy

    Description:
    Given an array of integers, replace each element with its rank.
    The smallest unique element gets rank 1, the next smallest gets rank 2,
    and so on. Equal elements receive the same rank.

    Approach:
    1. Create a copy of the original array.
    2. Sort the copied array.
    3. Traverse the sorted array and assign ranks only to unique values.
    4. Store each value and its rank in an unordered_map.
    5. Traverse the original array and replace every element with its mapped rank.

    Why it works:
    - Sorting places all unique values in increasing order.
    - Assigning ranks during this traversal guarantees the smallest possible ranks.
    - Using a hash map allows each original element to be replaced in O(1) time.

    Time: O(n log n)
    Space: O(n)
*/

#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution{
    public:
    vector<int> arrayRankTransform(vector<int>& arr){
        //craete a copy of the soriginal array anf sort to get the ranks
        vector<int> sorted= arr;
        //sort the copy array
        sort(sorted.begin(), sorted.end());
        //create a map to store the rank of each unique number
        unordered_map<int, int> rankMap;

        int rank=1;
        for(int num: sorted){
            //if the number is not already in the map, assign it a rank
            if(rankMap.find(num) == rankMap.end()){
                rankMap[num] = rank;
                rank++; //increment the rank for the next unique number
            }
        }
        //replace each number in the original array with its rank using the map
        for(int &num: arr){
            num= rankMap[num];
        }
        //return the transformed array with ranks
        return arr;
    }
};