/* Move Zeroes
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> nums {0,1,0,3,12};

    int n = nums.size();

    int p1 = 0;
    int p2 = 0;

    while(p2 < n) {
        if(nums[p2] != 0) {
            swap(nums[p1], nums[p2]);
            p1++;
        }
        p2++;
    }

    for(int i : nums) {
        cout << i << " ";
    }
}