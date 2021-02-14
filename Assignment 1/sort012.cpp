//TC: O(n)
#include<bits/stdc++.h>
using namespace std;

vector<int> sort012(vector<int> arr){
	int op=0, sp=arr.size()-1;
	int start=0;
	while(start<=sp){
		switch(arr[start]){
			case 0:
				swap(arr[op++],arr[start++]);
				break;
			case 1:
				start++;
				break;
			case 2:
				swap(arr[sp--],arr[start]);
				break;
		}
	}
	return arr;
}

int main(){
	vector<int> arr = {0,1,2,2,1,1,0};
	vector<int> res = sort012(arr);
	for(auto p : res){
		cout<<p<<" ";
	}
}
