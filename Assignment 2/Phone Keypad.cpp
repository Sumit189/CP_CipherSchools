#include<bits/stdc++.h>
using namespace std;


vector<string> alp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void alphabets(vector<int> num, int start, int end, char str[]){
	if(start==end){
		cout<<str<<" ";
		return;
	}
	for(int i=0; i<alp[num[start]].size();i++){
		str[start]=alp[num[start]][i];
		alphabets(num,start+1,end,str);
		if(num[start]==0 || num[start]==1){
			return;
		}
	}
}

int main(){
	vector<int> numbers = {2,3,4};
	vector<string> res;
	char str[numbers.size()+1];
	alphabets(numbers,0,numbers.size(),str);
	
	for(auto val: res){
		cout<<val<<" ";
	}

	return 0;	
}
