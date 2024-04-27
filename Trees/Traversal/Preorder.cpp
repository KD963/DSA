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
void recursivePreorder(TreeNode* root, vector<int> &ans) {
    if(!root) return;
    ans.push_back(root->val);
    recursivePreorder(root->left,ans);
    recursivePreorder(root->right,ans);
}
// Recursive Way of preorder
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    recursivePreorder(root,ans);
    return ans;  
}

// Iterative Way
vector<int> preorderIterative(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        if(curr->right) {
            st.push(curr->right);
        }
        if(curr->left) {
            st.push(curr->left);
        }
    }
    return ans;
}

// Another way of Iterative 
vector<int> preorderIterative2(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    TreeNode* curr = root;
    stack<TreeNode*> st;
    while(curr || !st.empty()) {
        if(curr) {
            ans.push_back(curr->val);
            st.push(curr);
            curr = curr->left;
        } else {
            curr = st.top();
            st.pop();
            curr = curr->right;
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
    cout << "PreOrder Recursive Traversal -------- " << endl;
    vector<int> res1 = preorderTraversal(root);
    PrintArray(res1);

    cout << "PreOrder Iterative Traversal -------- " << endl;
    vector<int> resI = preorderIterative(root);
    PrintArray(resI);

    cout << "PreOrder Another Iterative Traversal -------- " << endl;
    vector<int> resII = preorderIterative2(root);
    PrintArray(resII);

    return 0;
    

}