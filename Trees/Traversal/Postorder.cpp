// preorder traversal of binary tree
// Data Left Right

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
void createTree(TreeNode* &root, int val) {
    if(root == NULL) {
        root = new TreeNode(val);
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if(curr->left == NULL) {
            curr->left = new TreeNode(val);
            return;
        } else {
            q.push(curr->left);
        }
        if(curr->right == NULL) {
            curr->right = new TreeNode(val);
            return;
        } else {
            q.push(curr->right);
        }
    }
}
void PrintArray(vector<int> A) {
    for(int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
void recursivePostorder(TreeNode* root, vector<int> &ans) {
    if(!root) return;
    recursivePostorder(root->left,ans);
    recursivePostorder(root->right,ans);
    ans.push_back(root->val);
}
// Recursive Way of preorder
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    recursivePostorder(root,ans);
    return ans;  
}

// Iterative Way using 2 stacks
vector<int> postorderIterative(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> st1, st2;
    st1.push(root);

    while(!st1.empty()) {
        root = st1.top();
        st1.pop();
        st2.push(root);

        if(root->left) {
            st1.push(root->left);
        }

        if(root->right) {
            st1.push(root->right);
        }
    }

    while (!st2.empty()) {
        ans.push_back(st2.top()->val);
        st2.pop();
    }
    return ans;
}
// Another Iterative way of postorder
vector<int> postorderIterative2(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> st;
    TreeNode* lastVisitedNode = NULL;
    TreeNode* curr = root;

    while(curr || !st.empty()) {
        while(curr) {
            st.push(curr);
            curr = curr->left;
        }

        TreeNode* temp = st.top();

        if(temp->right && temp->right != lastVisitedNode) {
            curr = temp->right;
        } else {
            ans.push_back(temp->val);
            st.pop();
            lastVisitedNode = temp;
        }
    }
    return ans;
}

int main() {
    // create Tree
    TreeNode* root = NULL;
    for(int i = 1; i <= 5; i++) {
        createTree(root,i);
    }
    cout << "Postorder Recursive Traversal -------- " << endl;
    vector<int> res = postorderTraversal(root);
    PrintArray(res);

    cout << "Postorder Iterative Traversal -------- " << endl;
    vector<int> resI = postorderIterative(root);
    PrintArray(resI);

    cout << "Postorder Another Iterative Traversal -------- " << endl;
    vector<int> resII = postorderIterative2(root);
    PrintArray(resII);

    return 0;
    

}