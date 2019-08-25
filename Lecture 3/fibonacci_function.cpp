#include <iostream>

using namespace std;

int fibonacci(int n){
	if(n==0 or n==1){
		return n;
	}

	int a = 0;
	int b = 1;

	int sum;

	for(int i=2;i<=n;i++){
		sum = a+b;
		a = b;
		b = sum;
	}

	return sum;
}

int main(){

	int n;
	cin>>n;

	cout<<fibonacci(n)<<endl;

	return 0;
}