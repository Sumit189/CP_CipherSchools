void printArray(int ints[], int len)  {  
    int i;  
    for (i = 0; i < len; i++)  {  
        cout << ints[i] << " ";  
    }  
    cout<<endl;  
} 

void printPathsRecur(node* node, int path[], int pathLen)  {  
    if (node == NULL)  
        return;  
    path[pathLen] = node->data;  
    pathLen++;  
    if (node->left == NULL && node->right == NULL)  {  
        printArray(path, pathLen);  
    }  
    else{  
        printPathsRecur(node->left, path, pathLen);  
        printPathsRecur(node->right, path, pathLen);  
    }  
}  
  
void printPaths(node* node)  {  
    int path[1000];  
    printPathsRecur(node, path, 0);  
}  
