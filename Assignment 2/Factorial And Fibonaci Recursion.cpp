#include<bits/stdc++.h>
using namespace std;
int fibonaci(int a){
	if(a<=1){
		return a;
	}
	return fibonaci(a-1)+fibonaci(a-2);
}
int factorial(int a){
	if(a<1){
		return 1;
	}
	return a*factorial(a-1);
}


int main(){
	int a = 10;
	int fib = fibonaci(a);
	int fact = factorial(a);
	cout<<"Fib: "<<fib;
	cout<<"\nFactorial: "<<fact;
	return 0;
}
