//Time Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> arr, vector<int> arr2){
	map<int,bool> mp;
	for(int i=0; i<arr.size();i++){
		mp[arr[i]]=true;
	}
	for(int i=0; i<arr2.size();i++){
		mp[arr2[i]]=true;
	}
	
	for(auto val : mp){
		cout<<val.first<<" ";
	}
}
int main(){
	vector<int> arr = {1,3,5,7,9};
	vector<int> arr2 = {2,4,6,8,10};
	merge(arr,arr2); 
}
