#include<bits/stdc++.h>
using namespace std;

struct Intervals{
    int start;
    int end;
};

bool compare(Intervals a, Intervals b){
    return (a.start < b.start);
}

void merge_intervals(Intervals arr[], int size){
    if(size <= 0)
    return;

    stack<Intervals> st;
    sort(arr, arr+size, compare);
    st.push(arr[0]);

    for(int i = 0; i < size; i++){
        Intervals top = st.top();
        if(top.end < arr[i].start){
            st.push(arr[i]);
        }
         else if (top.end < arr[i].end){ 
            top.end = arr[i].end; 
            st.pop(); 
            st.push(top); 
        } 
    }
    while (!st.empty()){ 
        Intervals t = st.top(); 
        cout << "[" << t.start << "," << t.end << "] "; 
        st.pop(); 
    }
}

int main(){
    Intervals arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} }; 
    int size = sizeof(arr)/sizeof(arr[0]);
    merge_intervals(arr,size);
    return 0;
}
