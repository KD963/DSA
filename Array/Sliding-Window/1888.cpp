/* Minimum Number of Flips to Make the Binary String Alternating
You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

Type-1: Remove the character at the start of the string s and append it to the end of the string.
Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

The string is called alternating if no two adjacent characters are equal.

For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
 

Example 1:

Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "111000";
    int n = s.size();
    string str = s + s;
    string alt1 = "";
    string alt2 = "";
    int diff1 = 0;
    int diff2 = 0;
    int left = 0;
    int res = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(i%2 == 0) {
            alt1 += "1";
        } else {
            alt1 += "0";
        }

        if(i%2 == 0) {
            alt2 += "0";
        } else {
            alt2 += "1";
        }
    }

    for(int right = 0; right < n; right++) {
        if(str[right] != alt1[right]) {
            diff1++;
        }
        if(str[right] != alt2[right]) {
            diff2++;
        }

        if(right - left + 1 > n) {
            if(str[left] != alt1[left]) {
                diff1--;
            }
            if(str[left] != alt2[left]) {
                diff2--;
            }
            left++;
            
        }
        if(right - left + 1 == n) {
            res = min(res, min(diff1,diff2));
        }
        
    }
    cout << res;

}