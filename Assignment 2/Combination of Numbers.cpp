#include<bits/stdc++.h>
using namespace std;

void combo_helper(int arr[], int data[], int start, int end, int index, int k){
	if(index == k){
		for(int j = 0; j < k; j++){
			cout<<data[j]<<" ";
		}
		cout<<endl;
		return;
	}
	
	for(int i = start; i <= end; i++){
		data[index]=arr[i];
		combo_helper(arr,data,i+1,end,index+1,k);
	}
	
}

void printCombo(int arr[], int n, int k){
	int data[k];
	combo_helper(arr,data,0,n-1,0,k);
}


int main(){
	int arr[] = {1,2,3,4};
	int k = 3;
	int size = sizeof(arr)/sizeof(arr[0]);
	printCombo(arr,size,k); 
}
