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

TreeNode* KthSmallest(TreeNode* root, int k){
    if(root == NULL)
    return NULL;

    TreeNode* left = KthSmallest(root->left, k);
    if(left != NULL){
        return left;
    }
    k--;
    if(k == 0){
        return root;
    }

    return KthSmallest(root->right, k);
}


int main(){
    vector<int> arr = {20, 4, 22, 8, 12, 10, 4};
    int size = arr.size();
    TreeNode *root =  NULL;
    for(int i = 0;  i < size; i++){
        root = insert(root, arr[i]);
    }
    root = KthSmallest(root, 3);
    cout<<root->data;
    return 0;
}
