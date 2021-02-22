#include<bits/stdc++.h>
using namespace std;

void max_window(vector<int>& arr , int k){
    int size = arr.size();
    deque<int> q(k);
    int i = 0;
    for(i; i < k; i++){
        while(!q.empty() && arr[i] >= arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
        for(; i < size; i++){
            while(!q.empty() && q.front() <= i-k){
                q.pop_front();
            }
            while(!q.empty() && arr[i] >= arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        cout << arr[q.front()]<<" ";
        }
}

int main(){
    vector<int> arr = {1,2,4,2,4,6,2,6,2,2};
    int k = 3;
    max_window(arr,k);
    return 0;
}
