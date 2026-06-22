/*
problem: 1189. Maximum Number of Balloons
link: https://leetcode.com/problems/maximum-number-of-balloons/
difficulty: easy

Description:
Given a string text, determine the maximum number of times the word
"balloon" can be formed using the characters in text.

Each character in text can be used at most once.
The word "balloon" requires:
b -> 1 time
a -> 1 time
l -> 2 times
o -> 2 times
n -> 1 time

Approach:
1. Count the frequency of every character in text.
2. Check the frequencies of the required characters:
   - b
   - a
   - l
   - o
   - n
3. Since 'l' and 'o' are needed twice in each "balloon",
   divide their frequencies by 2.
4. The character that runs out first determines how many
   complete "balloon" words can be formed.
5. Return the minimum among:
      freq['b'],
      freq['a'],
      freq['l'] / 2,
      freq['o'] / 2,
      freq['n']

Time: O(n)
Space: O(1)
*/

#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    int maxNumberOfBalloons(string text){
        string word= "balloon";
        if(word.size() > text.size()) return 0;

        vector<int> count(26,0);
        for(char ch : text){
            count[ch - 'a'] ++;
        }
        return min({
            count['b' - 'a'],
            count['a' - 'a'],
            count['l' - 'a'] / 2,
            count['o' - 'a'] / 2,
            count['n' - 'a']
        });
    }
};