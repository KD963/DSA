/* Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.
Example 1:

Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> nums {2,2,2,2,5,5,5,8};
    int k = 3;
    int threshold = 4;
    int ans = 0;
    int totalSum = 0;
    int left = 0;
    int right = 0;
    int window_len = 0;

   
    while(window_len < k && k < nums.size()) {
        totalSum += nums[right];
        right++;
        window_len++;
    }
    
    int avgSum = totalSum/k;
    if(avgSum >= threshold) {
        ans++;    
    } 
    while(right < nums.size()){
        totalSum -= nums[left];
        left++;
        window_len--;

        totalSum += nums[right];
        right++;
        window_len++;

        if(totalSum/k >= threshold) {
            ans++;
        }
    }
    
    cout << ans;
    

    
}