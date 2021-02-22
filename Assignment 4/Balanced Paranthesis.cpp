#include<bits/stdc++.h>

using namespace std;

bool isBalanced(string& str){
    if(str == ""){
        return true;
    }
    stack<char> st;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
            st.push(str[i]);
        else{
            char top = st.top(); st.pop();
            if( !(str[i] == ')' && top == '(') && !(str[i] == '}' && top == '{') && !(str[i] == ']' && top == '[') ) {
                return false;
            } 
        }
    }
    if(st.empty()){
        return true;
    }
    return false;
}

int main(){
    string str = "({{})";
    if(isBalanced(str)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    return 0;
}
