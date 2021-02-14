//Time Complexity : O(logn)
#include<bits/stdc++.h>
using namespace std;

int binary_Search(vector<int> arr, int low, int high, int x){
	if(low>=high){
		return -1;
	}
	
	int mid = low+(high-low)/2;
	if(arr[mid]==x){
		return mid;
	}
	
	if(x>=arr[mid]){
		return binary_Search(arr, mid+1,high,x);
	} 
	return binary_Search(arr,low,mid,x);
}

int main(){
	vector<int> arr ={2,4,6,8,10,12};
	int x = 12;
	int res = binary_Search(arr,0,arr.size(),x);
	cout<<res;
}
