#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

template<typename T2>
void merge(vector<T2> &arr, int l, int m, int r){
	int i,j,k;
	int p = m-l+1;
	int q = r-m;
	
	T2 left[p], right[q];
	for(int i=0;i<p;i++){
		left[i]=arr[l+i];
	}
	for(int j=0;j<q;j++){
		right[j]=arr[m+1+j];
	}
	i=0;
	j=0;
	k=l;
	while(i<p && j<q){
		if(left[i]<=right[j]){
			arr[k]=left[i];
			i++;	
		}
		else{
			arr[k]=right[j];
			j++;
		}
		k++;	
	}
	
	while(i<p){
		arr[k]=left[i];
		i++;
		k++;
	}
	while(j<q){
		arr[k]=right[j];
		j++;
		k++;
	}
}

template<typename T1>
void mergesort(vector<T1> &arr, int l, int r){
	if(l>=r)
		return;
	int m =l+(r-l)/2;
	mergesort<T1>(arr,l,m);
	mergesort<T1>(arr,m+1,r);
	merge<T1>(arr,l,m,r);
}

template<typename T3>
void print_All(vector<T3> arr, int size){
	int i;
    for (i = 0; i < size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
	vector<string> arr;
	int n;
	string a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		arr.push_back(a);
	}
	int size=n;
	mergesort<string>(arr,0,size-1);
	print_All<string>(arr,size);
}
