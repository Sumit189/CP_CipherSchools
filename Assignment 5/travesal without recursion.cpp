void preorder(TreeNode* root){
    if (root == NULL)
        return;

    stack<TreeNode*> nodeStack;
    nodeStack.push(root);
  
    while (nodeStack.empty() == false) {
        TreeNode* node = nodeStack.top();
        cout<<node->data;
        nodeStack.pop();

        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}

void postorder(TreeNode* root){
    stack<TreeNode*> s;
    s.push(root);
    
    stack<int> out;
 
    while (!s.empty()){
        TreeNode *curr = s.top();
        s.pop();
 
        out.push(curr->data)
        
        if (curr->left)
            s.push(curr->left);
 
        if (curr->right)
            s.push(curr->right);
    }
 
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}

void inorder(TreeNode* root){
   stack<TreeNode *> s;
    TreeNode *curr = root;
 
    while (curr != NULL || s.empty() == false){
        while (curr !=  NULL){
            s.push(curr);
            curr = curr->left;
        }
 
        curr = s.top();
        s.pop();
 
        cout << curr->data << " ";
        curr = curr->right;
 
    }
}
