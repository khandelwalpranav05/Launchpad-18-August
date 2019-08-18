#include <iostream>

using namespace std;

int main(){

	cout<<"Hello World!";
	cout<<endl;

	cout<<"Hello World!"<<endl;

	// int a = 10;
	// int b = 10;
	// int c = 5;

	int a=10,b=20,c=30;

	if(a>=b and a>=c){
		cout<<a<<endl;

	}else if(b>=a and b>=c){
		cout<<b<<endl;

	}else{
		cout<<c;
		cout<<endl;
	}

	return 0;
}