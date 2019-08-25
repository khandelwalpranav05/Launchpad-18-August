#include <iostream>

using namespace std;

bool last(int nothing){
	if(nothing){
		return true;
	}else{
		return false;
	}

	cout<<"This is the last value "<<endl;
}

void third(){
	cout<<"This is the third function"<<endl;
	cout<<"**************************"<<endl;

	bool b = last(12);
	cout<<b<<endl;

	cout<<"last function value "<<last(0)<<endl;
}

int second(int a,int b,int c,char p,bool b){
	int sum = a+b+c+p+b;

	third();

	return sum;
}

float first(float a,float b){
	float mul = a*b;

	cout<<"This is the product "<<mul<<endl;

	cout<<"Second Function Value "<<second(a,b,10,'A',false)<<endl;

	return mul;
}

int main(){

	float first_call = first(1.3,2.6);

	cout<<"First call Value "<<first_call<<endl;

	return 0;
}