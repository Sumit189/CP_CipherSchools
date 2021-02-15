#include<bits/stdc++.h>
using namespace std;

void find_max(string num, int k, string &res){
	if(k==0){
		return;
	}
	int size = num.size();
	for(int i=0; i<size-1; i++){
		for(int j=i+1; j<size; j++){
			if(num[i]<num[j]){
				swap(num[i],num[j]);
				if(num.compare(res)>0){
					res = num;
				}
				find_max(num,k-1,res);
				swap(num[i],num[j]);
			}
		}
	}
}

int main(){
	string num = "1185";
	int k = 6;
	string res = num;
	find_max(num, k, res);
	cout<<res;
	return 0;
}
