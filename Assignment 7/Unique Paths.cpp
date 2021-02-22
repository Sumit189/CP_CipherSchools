#include<bits/stdc++.h>   
using namespace std; 

int unique_paths(vector<vector<int>> cost) {
    
    int r = cost.size(), c = cost[0].size();
    vector<vector<int>> dp (r+1, vector<int> (c+1,0));
    for(int i = 0; i < r; i++){
        dp[i][0] = 1;
    }
    for(int j = 0; j < c; j++){
        dp[0][j] = 1;
    }
    for(int i = 1 ; i < r; i++){
        for(int j = 1; j < c; j++){
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[r-1][c-1];
} 
  
int main() { 
    vector<vector<int>> paths(3, vector<int>(3,0));
    paths =  {{0, 0, 0},
             {0, 0, 0},
             {0, 0, 0}};
    cout<<unique_paths(paths);
    return  0;  
} 
