/*  Frequency of the Most Frequent Element
The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

Example 1:

Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> nums {1,2,4};
    int k = 5;

    int totalSum = 0, res = 0;
    int left = 0, right = 0;

    while(right < nums.size()) {
        totalSum += nums[right];

        while(nums[right] * (right - left + 1) > k + totalSum) { // nums[right] * window_len > k + totalSum
            totalSum -= nums[left];
            left++;
        }
        res = max(res, right - left + 1);
        right++;
    }
    cout << res;

}