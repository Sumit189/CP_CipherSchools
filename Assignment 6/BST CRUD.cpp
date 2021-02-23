
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

TreeNode* minNode(TreeNode *root){
     TreeNode* current = root;
     while (current && current->left != NULL)
        current = current->left;
    return current;
}

TreeNode *deleteNode(TreeNode* root, int data){
    if(root == NULL){
        return root;
    }    
    if(data > root->data){
        root->right = deleteNode(root->right, data);
    }
    else if(data < root->data){
        root->left = deleteNode(root->left, data);
    }
    else{
        if(root->left == NULL){
            TreeNode* temp = root->right;
            delete(root);
            return temp;
        }
        if(root->right == NULL){
            TreeNode* temp = root->left;
            delete(root);
            return temp;
        }

        TreeNode *tmp = minNode(root->right);
        root->data = tmp->data;
        root->right = deleteNode(root->right, tmp->data);
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

int main(){
    vector<int> arr = { 8, 6, 7, 12, 5, 1, 9 };
    TreeNode *root =  NULL;
    for(int  i = 0; i < arr.size(); i++){
        root = insert(root, arr[i]);
    }
    inorder(root);
    root =  deleteNode(root, 6);
    cout<<"\nAfter Delete"<<endl;
    inorder(root);
    return 0;
}
