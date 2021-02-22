#include<bits/stdc++.h>
using namespace std;

vector<int> dp(10);
vector<bool> visited(10);

int max_sum(vector<int>& a, int start, int size){
    if(start >= size)
    return 0;
    if(visited[start])
        return dp[start];
    visited[start] = true;
    dp[start] = max(max_sum(a, start+1, size), a[start] + max_sum(a,start+2,size));
    return dp[start];
}

int main(){
    vector<int> arr = {1, 2, 3};
    int size = arr.size();
    cout<<max_sum(arr, 0, size);
    return 0;
}
