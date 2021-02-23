void preorder(TreeNode *root){
  if(root != NULL){
  cout<<root->data<<endl;
  preordeR(root->left);
  preordeR(root->right);
  }
}


void ineorder(TreeNode *root){
  if(root != NULL){
  preordeR(root->left);
  cout<<root->data<<endl;
  preordeR(root->right);
  }
}


void postorder(TreeNode *root){
  if(root != NULL){
  preordeR(root->left);
  preordeR(root->right);
  cout<<root->data<<endl;
  }
}
