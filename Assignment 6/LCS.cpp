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



void inorder(TreeNode* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

TreeNode* LCS(TreeNode * root, int l, int r){
    while(root != NULL){
        if(root-> data > l  && root->data > r){
            root =  root->left;
        }
        else if(root->data < l && root->data < r){
            root = root->right;
        }
        else{
            break;
        }
    }
    return root;
}


int main(){
    vector<int> arr = {20, 4, 22, 8, 12, 10, 4};
    int size = arr.size();
    TreeNode *root =  NULL;
    for(int i = 0;  i < size; i++){
        root = insert(root, arr[i]);
    }
    root = LCS(root, 10, 14);
    inorder(root);
    return 0;
}
