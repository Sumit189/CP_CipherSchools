#include<bits/stdc++.h>   
using namespace std; 
  
int min(int x, int y, int z) { 
    return min(min(x, y), z); 
}

int min_cost(vector<vector<int>> cost) {
    
    int r = cost.size(), c = cost[0].size();
    vector<vector<int>> dp (r+1, vector<int> (c+1,0));

    dp[0][0] =  cost[0][0];
    for(int i = 1; i < r; i++){
        dp[i][0] = dp[i-1][0] + cost[i][0];
    }
    for(int j = 1; j < c; j++){
        dp[0][j] = dp[0][j-1] + cost[0][j];
    }
    for(int i = 1 ; i < r; i++){
        for(int j = 1; j < c; j++){
            dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + cost[i][j];
        }
    }
    return dp[r-1][c-1];
} 
  
int main() { 
    vector<vector<int>> cost(3, vector<int>(3,0));
    cost =  {{1, 2, 3},
             {4, 8, 2},
             {1, 5, 3}};
    cout<<min_cost(cost);
    return  0;  
} 
