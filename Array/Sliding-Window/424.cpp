/* Longest Repeating Character Replacement
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa 
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "ABAB";
    int k = 2;
    unordered_map<char,int> mp;
    int max_len = 0;
    int max_freq = 0;
    int left = 0;
    for(int right = 0; right < s.size(); right++) {
        mp[s[right]]++;
        max_freq = max(max_freq,mp[s[right]]);

        while(right - left + 1 - max_freq > k) {
            mp[s[left]]--;
            left++;
        }

        max_len = max(max_len, right - left + 1);

        
    }
    cout << max_len;
}