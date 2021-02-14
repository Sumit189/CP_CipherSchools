//TC : n*log(n)
#include<bits/stdc++.h>
using namespace std;
void swap(int *a, int *b){
	int c =*a;
	*a = *b;
	*b = c;
}

int partition(vector<int>& arr, int low, int high){
	int pivot = arr[high];
	int i = low-1;
	for(int j=low; j<=high-1; j++){
		if(arr[j]<pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
		
	}
	swap(&arr[i+1],&arr[high]);
	return i+1;
}

void quicksort(vector<int>& arr,int low, int high){
	if(low<high){
		int pi = partition(arr, low, high);
		quicksort(arr, low, pi-1);
		quicksort(arr, pi+1, high);
	}
	
}

void printArray(vector<int> arr){
	for(auto val: arr){
		cout<<val<<" ";
	}
}

int main(){
	vector<int> arr = {0,1,4,2,4,7,1};
	quicksort(arr,0,arr.size());
	printArray(arr);
	return 0;
}
