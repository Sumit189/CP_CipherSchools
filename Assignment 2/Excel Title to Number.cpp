#include<bits/stdc++.h>
using namespace std;
void title_toNum(string s){
	int res=0;
	for(auto c : s){
		res*=26;
		res+=c-'A'+1;
	}
	cout<<res;
}
int main(){
	string s = "CDA";
	title_toNum(s);
}
