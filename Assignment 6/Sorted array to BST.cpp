#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode *left, *right;
    TreeNode(){
        TreeNode(0);
    }

    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    
};

TreeNode* insert(TreeNode* root, int data){
    if(root == NULL){
        root = new TreeNode(data);
        return root;
    }
    else if(root->data < data){
        root->right = insert(root->right, data);
    }
    else{
        root->left = insert(root->left, data);
    }
    return root;
}


TreeNode* sortedTobst(vector<int> arr, int start, int end){
    if(start > end)
    return NULL;

    int mid = start + (end-start)/2;
    TreeNode *root = new TreeNode(arr[mid]);
    
    root->left = sortedTobst(arr, start, mid-1);
    root->right = sortedTobst(arr, mid+1, end);
    return root;
}

void inorder(TreeNode* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int size = arr.size();
    TreeNode *root =  NULL;
    root = sortedTobst(arr, 0, size-1);
    inorder(root);
    return 0;
}
