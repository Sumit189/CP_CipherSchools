#include<bits/stdc++.h>   
using namespace std; 
  
int LCS( string& s, string& s2) {
    int size1 = s.size();
    int size2 = s2.size(); 
    int max_size = 0;
    vector<vector<int>> dp(size1+1, vector<int> (size2+1,0));
    for(int i = 0; i <= size1; i++){
        for(int j = 0; j <= size2; j++){
            if( i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                max_size = max(max_size, dp[i][j]);
            }
            else{
                //  dp[i][j] = 0;
                 dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }    
    return max_size;
} 
  
int main() { 
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout<<LCS(s1,s2);

    return  0;  
} 
