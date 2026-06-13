/*
problem: weighted word mapping
link: https://leetcode.com/discuss/interview-question/1240913/Google-or-Onsite-or-Weighted-Word-Mapping
difficulty: easy

Description:
Given a list of words and a list of weights for each letter in the alphabet
map each word to a single character based on the sum of the weights of its letters. 
The mapping is done such that the sum of weights is taken modulo 26, 
and then mapped to a character in reverse order (i.e., 0 -> z, 1 -> y, ..., 25 -> a 

Approach:
1. Initialize an empty string to store the result.
2. Iterate through each word in the input vector.
3. For each word, calculate the sum of weights for its characters.
4. Calculate the remainder of the sum when divided by 26.
5. Map the remainder to a character in reverse order and append it to the result string.

Time Complexity: O(n * m), where n is the number of words and m is the average length of the words. 
Space Complexity: O(1) for the result string, as it only stores the mapped characters.
*/
#include <vector>
#include <string>
using namespace std;

class Solution{
    public:
    string mapWordWeights(vector<string>& words, vector<int>& weights){
        string ans= "";

        //Iterate through each word in the input vector
        for(string word: words){
            //Calculate the sum of weights for the current word
            int sum =0;
            //Iterate through each character in the word to calculate the total weight
            for(char c: word){
                sum += weights[c-'a'];
            }
            //Calculate the remainder when the sum is divided by 26 to map it to a character
            int rem = sum % 26;

            //Reverse mapping to get the character
            // 0 -> z, 1 -> y, ..., 25 -> a
            char mapped = 'z' - rem;
            ans += mapped;
        }
        return ans;
    }
};