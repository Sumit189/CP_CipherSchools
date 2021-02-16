#include<bits/stdc++.h>
using namespace std;
void permute(string str, int start, int end){
	if(start==end){
		cout<<str<<" ";
	}
	for(int i=start;i<=end;i++){
		swap(str[i],str[start]);
		permute(str,start+1,end);
		swap(str[i],str[start]);
	}
}
int main(){
	string str = "ABC";
	permute(str, 0, str.size()-1);
}
