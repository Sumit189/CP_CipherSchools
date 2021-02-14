//Time complexity: Ologn

#include<bits/stdc++.h>

using namespace std;

int findPeak(vector<int> arr, int l, int r, int n){
	int m = l+(r -l)/2;
	if ((m == 0 || arr[m - 1] <= arr[m]) && (m == n - 1 || arr[m + 1] <= arr[m])){
        return m;
    }
	else if (m > 0 && arr[m - 1] > arr[m]){
        return findPeak(arr, l, (m - 1), n);
    }
	else 
		return findPeak(arr, (m+1), r, n);
}

int main(){
	vector<int> arr = {10, 20, 15, 38, 45, 90, 80};
	cout<<arr[findPeak(arr,0,arr.size()-1, arr.size())];
}
