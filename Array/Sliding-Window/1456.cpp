/* Maximum Number of Vowels in a Substring of Given Length
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
*/

#include <bits/stdc++.h>
using namespace std;

bool isVowel(char s) {
    if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') {
        return true;
    }
    return false;
}

int main() {
    string s = "leetcode";
    int k = 3;

    int max_count = 0;
    int count = 0;

    for(int i = 0; i < k; i++) {
        if(isVowel(s[i])) {
            count++;
        }
    }
    max_count = count;

    for(int i = k; i < s.size(); i++) {
        if(isVowel(s[i])) {
            count++;
        }
        if(isVowel(s[i-k])) {
            count--;
        }
        max_count = max(max_count, count);
    }
    cout << max_count;
}