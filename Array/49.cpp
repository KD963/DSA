/* Group Anagrams
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

*/

#include <bits/stdc++.h>
using namespace std;

void printArray(vector<vector<string>> a) {
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<string> strs {"eat","tea","tan","ate","nat","bat"};

    unordered_map<string, vector<string>> mp;

    vector<vector<string>> ans;

    for(auto &str : strs) {
        string key = str;
        sort(key.begin(),key.end());
        mp[key].emplace_back(str);
    }

    for(auto &word : mp) {
        ans.emplace_back(word.second);
    }

    printArray(ans);

    return 0;
}

