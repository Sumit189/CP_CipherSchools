//TC: O(nlogn)
#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> sort_alternative(vector<int> arr){
	sort(arr.begin(),arr.end());
	int j = arr.size()-1;
	int i = 0;
	vector<int> res;
	for(i; i < arr.size()/2 ;i++){
		res.pb(arr[i]);
		res.pb(arr[j--]);
	}
	if(arr.size()%2!=0){
		res.pb(arr[i]);
	}
	return res;
}

int main(){
	vector<int> arr = {1,2,3,4,5,6,7,8,9};	
	vector<int> res = sort_alternative(arr);
	for(auto r : res){
		cout<<r<<" ";
	}
	return 0;
}
