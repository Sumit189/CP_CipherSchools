//Time Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;

int findMissing(vector<int> arr, int n){
	if(n == 0){
		return 1;
	}
	int res = 0;
	for(int i = 0; i < n; i++){
		if((arr[i]^(i+1))!=0){
			res=i+1;
			break;
		}
	}
	return res;
}

int main(){
	vector<int> arr = {1,2,3,4,5,7,8,9,10}; 
	int res = findMissing(arr,arr.size());
	cout<<"Missing Value: "<<res;

	return 0;
}
