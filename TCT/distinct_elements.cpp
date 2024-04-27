#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> A {1,2,1,3,4,3};
    int B = 3;

    unordered_set<int> hs;

    int left = 0;
    vector<int> ans;
    int right = B-1;
    while(right < A.size()) {
        hs.insert(A[right]);
        right++;
        left++;
    }
    ans.push_back(hs.size());
    hs.empty();
    for(auto i : hs) {
        cout << i << " ";
    }
}