#include <bits/stdc++.h>
using namespace std;

int maxHeap(vector<int> arr, vector<int> arr2){
    int size = arr.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < size; i++){
        pq.push(arr[i]);
    }
    int i = 0;
    while(i != arr2.size()){
        cout<<pq.top()<<" ";
        pq.pop();
        pq.push(arr2[i]);
        i++;
    }
    return pq.top();
}

int main(){
    vector<int> arr = {1, 3, 5, 7, 9};
    vector<int> arr2 = {2, 4, 6, 8, 10};
    cout<<maxHeap(arr, arr2);
    return 0;
}
