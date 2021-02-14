//Time Complexity: O(n);
#include<bits/stdc++.h>
using namespace std;

void stonks(int price[], int n){
	if(n==1){
		return;
	}
	int profit=0;
	int i=0;
	while(i<n-1){
		while((i<n-1) && (price[i+1] <= price[i]))
		i++;
		
		if(i==n-1){
			break;
		}
		
		int buy = i++;
		while((i<n) && (price[i]>=price[i-1]))
		i++;
		int sell = i-1;
		profit += price[sell]-price[buy];
	}
	cout<<"Profit: "<<profit;
}

int main(){
	int price[] ={100, 180, 260, 310, 40, 535, 695};
	int n = sizeof(price)/sizeof(price[0]);
	stonks(price,n);
	return 0;
}
