/* Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 */

#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLL(ListNode* head) {
    while(head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}
ListNode* swapInPair(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* dummy = new ListNode(0);
    ListNode* prev = dummy;
    ListNode* curr = head;

    while (curr && curr->next) {   
        // save pointers
        ListNode* nextPair = curr->next->next;
        ListNode* second = curr->next;

        // reverse
        second->next = curr;
        curr->next = nextPair;
        prev->next = second;

        // update pointers;
        prev = curr;
        curr = nextPair;
    }
    
    return dummy->next;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next =  new ListNode(2);
    head->next->next =  new ListNode(3);
    head->next->next->next =  new ListNode(4);

    printLL(head);
    cout << "after swapping -- " << endl;
    ListNode* res = swapInPair(head);
    printLL(res);
    return 0;
}