//Time Complexity O(n)

#include<bits/stdc++.h>
using namespace std;


int getCandidate(vector<int>& vec){
	int candidateIndex = 0, count = 1;
	for(int i=1; i < vec.size(); i++){
		if(vec[i] == vec[candidateIndex]){
			count++;
		} else{
			count--;
		}
		if(count == 0){
			candidateIndex = i;
			count = 1; 
		}
	}
	return candidateIndex;
}

int majorityElem( vector<int>& vec){
	int candidate =  getCandidate(vec);
	int freq = 0;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] == vec[candidate]){
			freq++;
		}
	}
	if(freq > vec.size()/2){
		cout << vec[candidate]<<" "; 
	}else{
		cout << "NO ";
	}
}

int main(){
	vector<int> arr = {2,2,2,3,3,3,3,3};
	majorityElem(arr);
	return 0;
}
