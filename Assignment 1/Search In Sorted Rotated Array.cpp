//Time Complexity: O(logn)
#include<bits/stdc++.h>
using namespace std;

int find_val(vector<int> arr, int x, int low, int high){
	if(low > high){
		return -1;
	}
	int mid = low + (high - low)/2;
	if(arr[mid] == x){
		return mid;
	}
	
	if(arr[low]<=arr[mid]){
		if(x>=arr[low] && x<=arr[mid]){
			return find_val(arr, x,low,mid-1);
		}
		
		return find_val(arr,x,mid+1,high);
	}
	if (x >= arr[mid] && x <= arr[high]){
		return find_val(arr,x,mid+1,high);
	}
	return find_val(arr,x,low,mid-1);
}
int main(){
	vector<int> arr = {6,7,8,9,10,11,1,2,3,4,5};
	int x = 2;
	int low = 0;
	int high = arr.size()-1;
	int res = find_val(arr,x,low,high);
	cout<<res;
}
