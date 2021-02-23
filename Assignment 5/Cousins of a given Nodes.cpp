int getLevel(Node *root, Node *node, int level) {
    if (root == NULL) 
        return 0; 
    if (root == node) 
        return level;   
    int downlevel = getLevel(root->left, 
                             node, level + 1); 
    if (downlevel != 0) 
        return downlevel;     
    return getLevel(root->right, node, level + 1); 
} 
void printGivenLevel(Node* root, Node *node, int level) { 
    
    if (root == NULL || level < 2) 
        return; 
  
    if (level == 2){ 
        if (root->left == node || root->right == node) 
            return; 
        if (root->left) 
            cout << root->left->data << " "; 
        if (root->right) 
            cout << root->right->data; 
    } 
    else if (level > 2) 
    { 
        printGivenLevel(root->left, node, level - 1); 
        printGivenLevel(root->right, node, level - 1); 
    } 
} 
  

void printCousins(Node *root, Node *node) { 
    int level = getLevel(root, node, 1); 
    printGivenLevel(root, node, level); 
} 
