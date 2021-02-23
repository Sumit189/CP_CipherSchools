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

void printVerticleHelper(TreeNode* root, int hd, map<int, vector<int>> &mp){
    if(root == NULL){
        return;
    }
    mp[hd].push_back(root->data);
    printVerticleHelper(root->left, hd-1, mp);
    printVerticleHelper(root->right , hd+1, mp);
};

void printVerticle(TreeNode* root){
    int hd = 0;
    map<int, vector<int>> mp;
    printVerticleHelper(root, hd, mp);
    for(auto mp_val : mp){
        cout<<mp_val.first<<" --> ";
        for(auto val : mp_val.second){
            cout<<val<<" ";
        }
        cout<<endl;
    }
        
}


void printtopHelper(TreeNode* root, int hd, map<int, vector<int>> &mp){
    if(root == NULL){
        return;
    }
    mp[hd].push_back(root->data);
    printtopHelper(root->left, hd-1, mp);
    printtopHelper(root->right , hd+1, mp);
};

void printtop(TreeNode* root){
    int hd = 0;
    map<int, vector<int>> mp;
    printtopHelper(root, hd, mp);
    for(auto mp_val : mp){
        cout<<mp_val.first<<" --> "<<mp_val.second[0]<<" ";
        cout<<endl;
    }
       
}


void printBottomHelper(TreeNode* root, int hd, map<int, vector<int>> &mp){
    if(root == NULL){
        return;
    }
    mp[hd].push_back(root->data);
    printBottomHelper(root->left, hd-1, mp);
    printBottomHelper(root->right , hd+1, mp);
};

void printBottom(TreeNode* root){
    int hd = 0;
    map<int, vector<int>> mp;
    printBottomHelper(root, hd, mp);
    for(auto mp_val : mp){
        cout<<mp_val.first<<" --> ";
        int size = mp_val.second.size();
        if(size > 2){
            int mid = size/2; 
            cout<<mp_val.second[mid];
         } 
         else
         cout<<mp_val.second[size-1];
        cout<<endl;
    }
       
}

void leftViewUtil(TreeNode* root, int level, map<int,int> &mp){
    if(root == NULL)
    return;

    if(mp.find(level) ==  mp.end()){
       mp[level] = root->data;
    }
    leftViewUtil(root->left, level+1, mp);
    leftViewUtil(root->right, level+1, mp);
}

void leftView(TreeNode* root){
    int level = 1;
    map<int,int> mp;
    leftViewUtil(root, level,mp);
    for(auto mp_val : mp){
        cout<<mp_val.first<<" -> "<<mp_val.second<<endl;
    }
}

void rightViewUtil(TreeNode* root, int level, map<int, int> &mp){
    if(root == NULL)
    return;

    if(mp.find(level) == mp.end()){
        mp[level] = root->data;
    }

    rightViewUtil(root->right, level+1, mp);
    rightViewUtil(root->left, level+1, mp);    
}
void rightView(TreeNode* root){
    int level = 1;
    map<int, int> mp;
    rightViewUtil(root, level, mp);
    for(auto mp_val : mp){
        cout<<mp_val.first<<" -> "<<mp_val.second<<endl;
    }
}


int main(){
    vector<int> arr = {5,3,4,10,12,7,8,6};
    int size = arr.size();
    TreeNode *root =  NULL;
    for(int i = 0;  i < size; i++){
        root = insert(root, arr[i]);
    }
    cout<<"Vertical"<<endl;
    printVerticle(root);
    cout<<endl<<"Left"<<endl;
    leftView(root);
    cout<<endl<<"Right"<<endl;
    rightView(root);
    cout<<endl<<"Top"<<endl;
    printtop(root);
    cout<<endl<<"Bottom"<<endl;
    printBottom(root);
    return 0;
}
