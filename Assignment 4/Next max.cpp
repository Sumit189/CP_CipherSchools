#include<bits/stdc++.h>
using namespace std;
void next_greater(vector<int> &arr){
    stack<int> st;

    for(int i = 0; i < arr.size(); i++){
        if(st.empty()){
            st.push(arr[i]);
            continue;
        }

        while(!st.empty() && arr[i] > st.top()){
            cout<<st.top()<<" -> "<<arr[i]<<endl;
            st.pop();
        }
        st.push(arr[i]);
    }
    
    while(!st.empty()){
        cout<<st.top()<<" -> "<<-1<<endl;
        st.pop();
    }
}
int main(){
    vector<int> arr = {1,8,4,5,3,6};
    next_greater(arr);
    return 0;
}
