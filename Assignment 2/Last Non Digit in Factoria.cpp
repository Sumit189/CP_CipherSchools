#include<bits/stdc++.h>
using namespace std;
int digit[10];

int factorial(int a){
	if(a<=1){
		return 1;
	}
	return a*factorial(a-1);
}

void generate_first10(){
	int val = 0;
	digit[0] = 1;
	for(int i=1; i < 10; i++){
		val = factorial(i);
		int num_of_digit = (int)log10(val);
		while(val > 0){
			int calc = val%10;
			if(calc != 0){
				digit[i]=calc;
				break;
			}
			val/=10;
		}
	}
}

int find_lastNonZero(int n){
	if(n<10){
		return digit[n];
	}
	
	if(((n/10)%10)%2 == 0){
		return (6*find_lastNonZero(n/5)*digit[n%10])%10;
	}
	else{
		return (4*find_lastNonZero(n/5)*digit[n%10])%10;
	}
}

int main(){
	generate_first10();
	int n = 14;
	cout<<find_lastNonZero(n);
}
