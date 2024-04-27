/*
Merge Strings Alternately
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
Return the merged string.
Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    string word1 = "abc", word2 = "pqr";

    string ans = "";

    int n = word1.size();
    int m = word2.size();

    int p1 = 0;
    int p2 = 0;

    while (p1 < n && p2 < m)
    {
        cout << "p1 " << p1 << endl;
        cout << "p2 " << p2 << endl;

        ans += word1[p1];
        ans += word2[p2];
        p1++;
        p2++;
        cout << "ans << " << ans;
    }
    return 0;
    
}