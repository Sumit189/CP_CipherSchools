#include<bits/stdc++.h>
using namespace std;
void prev_smallest(vector<int> &arr){
    stack<int> st;

    for(int i = 0; i < arr.size(); i++){
        while(!st.empty() && arr[i] <= st.top()){
            st.pop();
        }
       if(st.empty()){
           cout<<"_,";
       }
       else{
           cout<<st.top()<<",";
       }
       st.push(arr[i]);
    }
}
int main(){
    vector<int> arr = {1, 3, 0, 2, 5};
    prev_smallest(arr);
    return 0;
}
