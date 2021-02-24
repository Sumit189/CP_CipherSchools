#include<bits/stdc++.h>
using namespace std;

int ls(string str, int n){
    if(str == ""){
        return 0;
    }
    map<char, int> mp;
    for(int i = 0; i < n; i++)
    mp[str[i]] = -1;

    int max_so_far = INT_MIN;
    int i = 0;
    for(int j = 0; j < n; j++){
        i = max(i, mp[str[j]]+1);
        max_so_far = max(max_so_far, j-i+1);
        mp[str[j]] = j;
    }
    return max_so_far;
}

int main(){
    string str = "dvdf";
    int n = str.size();
    cout<<ls(str, n);
}
