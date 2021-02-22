#include<bits/stdc++.h>
using namespace std;

bool isDuplicate(string str){
    stack<char> st;
    for(char c: str){
        if(c == ')'){
            int open_count = 0 ;
            char top = st.top();
            st.pop();
            while(top!='('){
                open_count++;
                top = st.top();
                st.pop();
            }
            if(open_count < 1){
                return true;
            }
        }
        else{
            st.push(c);
        }
    }
    return false;
}

int main(){
    string exp = "((a+(b))+(c+d))";
    if(isDuplicate(exp)){
        cout<<"Duplicate Found";
    }
    else{
        cout<<"No Duplicates";
    }
}
