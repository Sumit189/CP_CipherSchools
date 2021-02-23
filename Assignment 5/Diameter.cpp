int height(struct node* node){
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}
int diameter(struct node* tree){
    if (tree == NULL)
        return 0;
    int lheight = height(tree->left);
    int rheight = height(tree->right);
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
    return max(lheight + rheight + 1,
            max(ldiameter, rdiameter));
}
