#include<bits/stdc++.h>
using namespace std;

int maxHeap(vector<int> arr, int k){
    int size = arr.size();
    priority_queue<int> pq;
    for(int i = 0; i < size; i++){
        pq.push(arr[i]);
    }
    for(int i = 1; i <k; i++)
        pq.pop();
    return pq.top();
}

int main(){
    vector<int> arr = {12, 3, 5, 7, 19};
    cout<<maxHeap(arr, 4);
    return 0;
}
