#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int mat[4][4], int size, int k){
	int smallest = INT_MAX;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i<size;i++){
		for(int j=0; j<size;j++){
			pq.push(mat[i][j]);
		}
	}
	
	for(int i=0; i<k;i++){
		smallest = pq.top();
		pq.pop();
	}
	return smallest;
}

int main(){
	    int mat[4][4] = {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 25, 29, 37, 48 },
        { 32, 33, 39, 50 },
    };
    cout << "7th smallest element is "
         << kthSmallest(mat, 4, 7);
}
