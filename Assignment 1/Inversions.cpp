//Time Complexity: O(n^2)
#include<bits/stdc++.h>

using namespace std;

int inversions(vector<int> arr){
	int inv_count=0;
	int n =arr.size();
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				inv_count++;
			}
		}
	}
	return inv_count;
}


int main(){
	vector<int> arr = {1,20,6,4,5};;
	cout<<inversions(arr);
}
