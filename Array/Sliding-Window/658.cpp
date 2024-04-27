/* Find K closest Elemnts
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 */

#include <bits/stdc++.h>

using namespace std;

void printArr(vector<int> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](int a, int b) {
            return abs(a - x) < abs(b - x) || (abs(a - x) == abs(b - x) && a < b);
        });

        vector<int> ans(arr.begin(), arr.begin() + k);
        sort(ans.begin(), ans.end());

        return ans;
}

int main() {
    vector<int> arr {1,2,3,4,5};
    int x = 3;
    int k = 4;

    int n = arr.size();
    int left = 0;
    int right = n - k;

    while(left < right) {
        int mid = left + (right - left) / 2;

        if(x - arr[mid] <= arr[mid+k] - x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    vector<int> newarr(arr.begin() + left, arr.begin() + left + k);

    printArr(newarr);

    return 0;

}