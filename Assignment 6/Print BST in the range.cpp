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

void print_in_range(TreeNode* root, int l, int h){
    if(root != NULL){
        if(root->data > l && root->data <= h){
            cout<<root->data<<" ";
        }
        print_in_range(root->left, l, h);
        print_in_range(root->right, l, h);
    }
}

int main(){
    vector<int> arr = {10, 5, 1, 7, 40, 50};
    int size = arr.size();
    TreeNode *root =  NULL;
    for(int i = 0;  i < size; i++){
        root = insert(root, arr[i]);
    }
    print_in_range(root,7, 50);
    return 0;
}
