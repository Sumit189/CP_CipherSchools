#include<bits/stdc++.h>   
using namespace std; 
  
int min(int x, int y, int z) { 
    return min(min(x, y), z); 
}

int edit_distance( string& s, string& s2) {
    int size1 = s.size();
    int size2 = s2.size(); 
    int max_size = 0;
    vector<vector<int>> dp(size1+1, vector<int> (size2+1,0));

    for(int i = 0; i <= size1; i++){
        for(int j = 0; j <= size2; j++){
            if( i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(s[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                 dp[i][j] = 1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
            }
        }
    }    
    return dp[size1-1][size2-1];
} 
  
int main() { 
    string s1 = "sunday";
    string s2 = "saturday";
    cout<<edit_distance(s1,s2);
    return  0;  
} 
