/* Minimum Operations to Reduce X to Zero
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.
Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.
Example 1:
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:
Input: nums = [5,6,7,8,9], x = 4
Output: -1
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> nums {1,1,4,2,3};
    int x = 5;
    int left = 0, right = 0;
    int totalSum = 0;
    int max_window = -1;
    int currSum = 0;
    int n = nums.size();

    for(int num : nums) {
        totalSum += num;
    }
    int target = totalSum - x;
    while (right < n) {
        currSum += nums[right];

        while (left <= right && currSum > target) {
            currSum -= nums[left];
            left++;
        }

        if(currSum == target) {
            max_window = max(max_window, right - left + 1);
        }

        right++;
    }

    if(max_window == -1) {
        cout << -1;
    }

    cout << n - max_window;
    
    
}