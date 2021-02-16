#include<bits/stdc++.h>
using namespace std;


int countDecode(string num, int n){
	if(n==0 || n==1){
		return 1;
	}
	if(num[0]=='0'){
		return 0;
	}
	int count = 0;

	if(num[n-1]>'0'){
		count+=countDecode(num,n-1);
	}
	
	if(num[n-2]=='1' || num[n-2]=='2' && num[n-1]<'7'){
		count+=countDecode(num,n-2);
	}
	return count;
}

int countDecoding(string num, int size){
	if(num.size()==0 || (num.size()==1 && num[0]=='0')){
		return 0;
	}
	return countDecode(num,size);
}

int main(){
	string num="1234";
	cout<<"\n"<<countDecoding(num,num.size());
}
