/* Trapping Rain water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
  
*/

#include <bits/stdc++.h>

using namespace std;

// using two pointer approach
int trap(vector<int> &height) {
    int n = height.size();
    int left = 0, right = n-1;
    int leftMax = height[left];
    int rightMax = height[right];
    int ans = 0;

    while (left < right) {
        if(leftMax < rightMax) {
            left++;
            leftMax = max(leftMax,height[left]);
            ans += leftMax - height[left];
        } else {
            right--;
            rightMax = max(rightMax,height[right]);
            ans += rightMax - height[right];
        }
    }
    
    return ans;


}

int main() {
    vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1};
    int ans = trap(height);
    cout << ans;
    return 0;
}