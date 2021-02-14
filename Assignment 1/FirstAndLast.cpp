//TC: O(logn)
#include<bits/stdc++.h>
using namespace std;

int frst(vector<int> arr, int start, int end, int x, int n){
	if(end >= start){
		int mid = start + (end - start)/2;
		if((mid == 0 || arr[mid-1] < x )&& arr[mid] == x){
			return mid;
		}
		else if(x > arr[mid]){
			return frst(arr,(mid+1),end,x,n);
		}
		else{
			return frst(arr,start,(mid-1),x,n);
		}
	}
	else{
		return -1;
	}
}

int last(vector<int> arr, int start, int end, int x, int n){
	if(end >= start){
		int mid = start + (end - start)/2;
		if((mid == n-1 || arr[mid+1] > x) && arr[mid] == x){
			return mid;
		}
		else if(arr[mid] > x){
			return last(arr,start,(mid-1),x,n);
		}
		else{
			return last(arr,(mid+1),end,x,n);
		}
	}
	return -1;
}


int main(){
	vector<int> arr = {0,1,2,2,2,3};
	cout<<frst(arr,0,arr.size()-1,2,arr.size())<<"\n";
	cout<<last(arr,0,arr.size()-1,2,arr.size());
}
