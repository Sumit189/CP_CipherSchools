//TC O(n/5)
#include<bits/stdc++.h>
using namespace std;

int find_trailingZeros(int a){
	int count=0;
	for(int i=5; a/i>=1; i*=5){
		count+=a/i;
	}
	return count;
}

int main(){
	int num = find_trailingZeros(100);
	cout<<num;
}
