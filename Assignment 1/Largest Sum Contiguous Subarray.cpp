//Time complexity:  O(n)

#include<bits/stdc++.h>
using namespace std;

void print_MAXsubSum(vector<int> arr){
	int max_so_far=0;
	int sum=0;
	int start=0, end=0;
	for(int i=0; i<arr.size()-1; i++){
		sum+=arr[i];
		if(sum>max_so_far){
			max_so_far=sum;
			end=i;
		}
		if(sum<0){
			start=i+1;
			sum=0;
		}
	}
	cout<<"Start from: "<<start<<" End: "<<end<<" SUM= "<<max_so_far;
}

int main(){
	vector<int> arr = {-2,-3,4,-1,-2,1,5,-3};
	print_MAXsubSum(arr);
}
