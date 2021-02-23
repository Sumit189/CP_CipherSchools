int addBT(Node* root) { 
    if (root == NULL) 
        return 0; 
    return (root->key + addBT(root->left) + addBT(root->right)); 
} 
