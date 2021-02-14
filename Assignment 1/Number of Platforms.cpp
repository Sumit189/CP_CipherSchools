//Time Complexity O(n+m)

#include<bits/stdc++.h>
using namespace std;

void find_min_platforms(int arr[], int dept[], int size1, int size2){
	sort(dept,dept+size1);
	sort(arr,arr+size2);
	int i=1,j=0;
	int plt=1, min_plt=1;
	
	
	while (i<size1 && j<size2){
		if(arr[i] >= dept[j]){
			j++;
			plt--;
		}
		else{
			i++;
			plt++;
		}
		
		min_plt = max(min_plt,plt);
	}
	cout<<min_plt;  
}

int main(){
	int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int size = sizeof(arr)/sizeof(arr[0]);
    int size2 = sizeof(dep)/sizeof(dep[0]);
    find_min_platforms(arr,dep,size,size2);
}
