/* Minimum Window Substring
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

     int m = s.size();
        int n = t.size();
        int left = 0;
        string min_window = "ABC";
        string curr_window = "A";

        min_window = min(min_window.size(), curr_window.size());
        cout << min_window;
        // need to write code

    // for(int right = 0; right < n; right++) {
    //     if(s[left] == t[right]) {
    //         curr_window += s[left];
    //         left++;
    //         right++;
    //     } else {
    //         curr_window += s[left];
    //         min_window = min(min_window.size(), curr_window.size());

    //     }
    // }
        
}