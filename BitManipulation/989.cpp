/* Add to Array-Form of Integer

Problem Statement

The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234 */


#include<bits/stdc++.h>

using namespace std;

void printArray(vector<int> &a) {
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> num {2,1,5};
    int k = 806;
    int n = num.size();
    for(int i = n-1; i >= 0; i--) {
        num[i] += k;
        k = num[i]/10;
        num[i] = num[i]%10;
    }

    while(k) {
        num.insert(num.begin(), k%10);
        k/=10;
    }

    printArray(num);

    return 0;

}