#include<bits/stdc++.h>   
using namespace std; 
  
int count( int arr[], int m, int n ) { 
    int i, j, x, y;   
    vector<vector<int>> table (n+1, vector<int>(m,0));
    for (i = 0; i < m; i++) 
        table[0][i] = 1; 
   
    for (i = 1; i < n + 1; i++){ 
        for (j = 0; j < m; j++){ 
            x = (i-arr[j] >= 0) ? table[i - arr[j]][j] : 0;  
            y = (j >= 1) ? table[i][j - 1] : 0; 
            table[i][j] = x + y; 
        } 
    } 
    return table[n][m - 1]; 
} 
  
int main() { 
    int arr[] = {1, 2, 3}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    int n = 4; 
    cout << count(arr, m, n); 
    return 0; 
} 
