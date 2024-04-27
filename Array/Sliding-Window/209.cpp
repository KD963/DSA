/* Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> nums {2,3,1,2,4,3};
    int target = 7;
    int sum = 0;
    int min_res = 0;
    int left = 0; 

    for(int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while(sum >= target) {
            min_res = min(min_res, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    cout << min_res;
}