#include<bits/stdc++.h>
using namespace std;
    int climbStairs(int n, int m) {
        int dp[n];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n ; i++){
            dp[i] = 0;
            for(int j = 0; j <= m && j <= i; j++){
                dp[i] += dp[i-j];
            }
        }
        return dp[n-1];    
    }
int main(){
    int n = 4;
    cout<<climbStairs(n+1,2);
}
