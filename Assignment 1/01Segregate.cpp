//TC: O(n)
#include<bits/stdc++.h>
using namespace std;

vector<int> segregate(vector<int> arr){
	int sp = 0, ep = arr.size()-1;
	while(sp<ep){
		while(arr[sp] == 0 && sp<ep){
			sp++;
		}
		while(arr[ep] == 1 && sp<ep){
			ep--;
		}
		if(sp<ep){
		swap(arr[sp],arr[ep]);
		sp++;
		ep--;
		}	
	}
	return arr;
}

int main(){
	vector<int> arr = {1,1,0,0,1,0};
	vector<int> res = segregate(arr);
	for(auto p : res){
		cout<<p<<" ";
	}
}
