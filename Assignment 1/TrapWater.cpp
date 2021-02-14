//TC: O(n*n)
#include<bits/stdc++.h>
using namespace std;

void trap_water(vector<int> arr, int n){
	int res=0;
	for(int i=1;i<n;i++){
		int left = arr[i];
		
		for(int j=0;j<i;j++)
		left = max(left,arr[j]);
		
		int right = arr[i];
		for(int j=i+1; j<n;j++)
		right = max(right,arr[j]);
		
		res+= (min(left,right)-arr[i]);
	}
	cout<<res;
}

int main(){
	vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int size = arr.size();
	trap_water(arr,size);
}
