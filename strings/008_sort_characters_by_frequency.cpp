/*
problem: Sort Characters By Frequency
link: https://leetcode.com/problems/sort-characters-by-frequency/
difficulty: Medium

Description:
Given a string s, count the frequency of each character and return
the unique characters sorted by decreasing frequency.
If two characters have the same frequency, sort them in alphabetical order.

Approach:
1. Count the frequency of each character.
2. Store each character and its frequency as a pair (character, frequency).
3. Sort the pairs using custom sorting criteria by lambda function:
   - Higher frequency comes first.
   - If frequencies are equal, alphabetical order is used.
4. Traverse the sorted pairs and add only the characters with non-zero frequency to the answer.
5. Return the final result.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution{
    public:

    typedef pair<char, int> pair;
    string frequencySort(string s){
        vector<pair> vec(123); // Create a vector of pairs to store characters and their frequencies

        // Count the frequency of each character in the string
        for(char &ch: s){
            int freq= vec[ch].second; // Get the current frequency of the character
            vec[ch] = {ch, freq+1}; // Update the frequency of the character 
        }
        auto lambda= [&](pair &p1, pair &p2){
            if(p1.second == p2.second) 
                return p1.first < p2.first; // If frequencies are equal, sort by character
            return p1.second > p2.second; // Sort by frequency in descending order
        };

        // Sort the vector of pairs based on the defined lambda function
        sort(vec.begin(), vec.end(), lambda); 

        string result = "";

        for(int i=0; i<vec.size(); i++){
            int freq= vec[i].second; // Get the frequency of the character
            char ch= vec[i].first; // Get the character

            string temp= string(freq, ch); // Create a string with the character repeated 'freq' times
            
            result += temp; // Append the temporary string to the result
        }
        return result;
    }
};