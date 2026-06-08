#include <string>
using namespace std;

class Solution{
    public:
    int myAtoi(string s){
        int n= s.size();

        int i=0;
        //1. Ignore leading whitespace characters
        while(i<n && s[i] == ' ') i++;

        //2. Check for an optional sign character
        int sign = 1; // Default sign is positive
        while(i<n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-') sign = -1; // If the sign is '-', set sign to -1
            i++;
        }

        //Build the answer 
        long long ans=0;
        while(i<n && isdigit(s[i])){
            int digit = s[i] - '0'; // Convert the current character to its corresponding digit
            if(ans > (INT_MAX - (s[i] - '0')) / 10){
                // If the answer exceeds the range of a 32-bit signed integer, return the appropriate limit
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            ans = ans * 10 + digit; // Update the answer by adding the current digit
            i++;
        }
        return sign * ans; // Return the final result by applying the sign to the answer
    }
};