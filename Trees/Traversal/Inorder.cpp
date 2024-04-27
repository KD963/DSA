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

void recursiveInorder(TreeNode* root, vector<int> &ans) {
    if(!root) return;
    recursiveInorder(root->left,ans);
    ans.push_back(root->val);
    recursiveInorder(root->right,ans);
}
// recursive way of inorder
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    recursiveInorder(root,ans);
    return ans;
}

// Iterative way of inorder
vector<int> inorderIterative(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while(curr || !st.empty()) {
        if(curr) {
            st.push(curr);
            curr = curr->left;
        } else {
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }
    return ans;
}

// Another Iterative way of inorder
vector<int> inorderIterative2(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()) {
        TreeNode* curr = st.top();
        if(curr->left) {
            st.push(curr->left);
            curr->left = NULL;
        } else {
            ans.push_back(curr->val);
            st.pop();
            if(curr->right) {
                st.push(curr->right);
            }
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
    cout << "InOrder Recursive Traversal -------- " << endl;
    vector<int> res = inorderTraversal(root);
    PrintArray(res);

    cout << "InOrder Iterative Traversal -------- " << endl;
    vector<int> resI = inorderIterative(root);
    PrintArray(resI);

    cout << "InOrder Another Iterative Traversal -------- " << endl;
    vector<int> resII = inorderIterative2(root);
    PrintArray(resII);


    return 0;
    

}