#include<bits/stdc++.h>
using namespace std;

void num_toTitle(int n){
	int rem=0;
	string s;
	int index=0;
	while(n>0){
		rem = n%26;
		if(rem==0){
			s[index]='Z';
			index++;
			n = (n/26)-1;
		}
		else{
			s[index]=(rem-1)+'A';
			index++;
			n/=26;
		}
	}
	s[index]='\0';
//	reverse(s,s+s.size());
	cout<<s;
}

int main(){
	int n = 2133;
	num_toTitle(n);
}
