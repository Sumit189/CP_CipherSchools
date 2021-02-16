#include<bits/stdc++.h>
using namespace std;

void powerset(string str, int size){
	int power = pow(2,size);
	
	for(int i=0; i<power; i++){
		for(int j=0; j<size; j++){
			if(i & (1<<j)){
				cout<<str[j];
			}
		}
		cout<<endl;
	}
}

int main(){
	string str = "456";
	powerset(str,str.size());	
}
