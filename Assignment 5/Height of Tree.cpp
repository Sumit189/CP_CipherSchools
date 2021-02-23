int maxDepth(node* node) { 
    if (node == NULL) 
        return -1; 
    else{ 
        int lDepth = maxDepth(node->left); 
        int rDepth = maxDepth(node->right); 
        if (lDepth > rDepth) 
            return(lDepth + 1); 
        else return(rDepth + 1); 
    } 
} 
