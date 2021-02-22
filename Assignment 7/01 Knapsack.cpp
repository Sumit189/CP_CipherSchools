#include<bits/stdc++.h>   
using namespace std; 
  
int min(int x, int y, int z) { 
    return min(min(x, y), z); 
}

int knapsack(int W, vector<int> wt, vector<int> val) {
    int size1 = val.size();
    int max_size = 0;
    vector<vector<int>> dp(size1+1, vector<int> (W+1,0));

    for(int i = 0; i <= size1; i++){
        for(int j = 0; j <= W; j++){
            if(i == 0 || j == 0)
            dp[i][j] = 0;
            else if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1]+dp[i - 1][j - wt[i-1] ], dp[i-1][j]);
            }
            else{
                 dp[i][j] = dp[i-1][j];
            }
        }
    }    
    return dp[size1][W];
} 
  
int main() { 
    vector<int> w = {10, 20, 30};
    int W = 50;
    vector<int> val = {60, 100, 120};
    cout<<knapsack(W, w, val);
    return  0;  
} 
