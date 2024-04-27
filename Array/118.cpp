/*
Pascal's Triangle
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/

#include <bits/stdc++.h>

using namespace std;

void printArray(vector<vector<int>> &a) {
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
} 

int main() {
    int n = 5;
    vector<vector<int>> ans;

    ans.push_back({1}); // first row 

    for(int i = 1; i < n; i++) {
        vector<int> row(i+1, 1);
        for(int j = 1; j < i; j++) {
            row[j] = ans[i-1][j-1] + ans[i-1][j];
        }

        ans.push_back(row);
    }

    printArray(ans);

    return 0;

}