// Time Complexity O(1) becuase we are only checking for the condition 1 time.

#include<bits/stdc++.h>
using namespace std;

bool meet(int x1, int x2, int v1, int v2){
	if(x1 < x2 && v1 <= v2 ){
		return false;
	}
	if(x1 > x2 && v1 >= v2){
		return false;
	}
	if(x1 < x2){
		swap(x1, x2);
		swap(v1, v2);
	}
	
	return ((x1-x2)%(v1-v2)==0);
}

int main(){
	int x1 = 6, x2 = 4, v1 = 6, v2 = 8;
	if(meet(x1, x2, v1, v2)){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}
