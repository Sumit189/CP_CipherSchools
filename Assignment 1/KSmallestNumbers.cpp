//Time Complexity: O(n^2logn)
#include<bits/stdc++.h>
using namespace std;
void find_smallest(vector<int> arr, int k){
	vector<int> c_arr = arr;
	sort(c_arr.begin(), c_arr.end());
	int kth_ = c_arr[k-1];
	int count=0;
	vector<int> res(k);
	int smallest =  kth_;
	
	for(int i = 0;i < arr.size(); i++){
		if(arr[i] <= smallest){
			if(count <= k){
			smallest = arr[i];
			res[count] = smallest;
			count++;
			}
			else{
				break;
			}
		}
	}
	for(auto val : res){
		cout<<val<<" ";
	}
}

int main(){
	vector<int> arr = {5,4,6,2,1};
	int k = 3;
	find_smallest(arr,k);
}
