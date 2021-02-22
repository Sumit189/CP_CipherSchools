#include<bits/stdc++.h>
using namespace std;

int min_jumps(vector<int> &arr, int n){
    vector<int> dp(n);
    dp[0] = 0;
    int i,j;
    for (i = 1; i < n; i++) {
        dp[i] = INT_MAX;
        for (j = 0; j < i; j++) {
            if (i <= j + arr[j] && dp[j] != INT_MAX) {
                dp[i] = min(dp[i], dp[j] + 1);
                break;
            }
        }
    }
    return dp[n-1];
}

int main(){
    vector<int> arr = { 1, 3, 6, 1, 0, 9 };
    int size = arr.size();
    cout<<min_jumps(arr, size);    
}
