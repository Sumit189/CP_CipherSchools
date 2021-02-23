#include<bits/stdc++.h>
using namespace std;

int ls(string str, int n){
    map<char, int> mp;
    int max_so_far = INT_MIN;
    int count = 0;
    stack<char> st;
    for(int i = 0; i < n; i++){
        if(mp[str[i]] == 0){
            count++;
            st.push(str[i]);
            mp[str[i]]++;
        }
        else{
            while(!st.empty()){
                mp[st.top()] = 0;
                st.pop();
            }
            max_so_far =  max(max_so_far, count);
            count = 0;
        }
    }
    return max_so_far;
}

int main(){
    string str = "ABDEFGABEF";
    int n = str.size();
    cout<<ls(str, n);
}
