#include <iostream>

using namespace std;

int main(){

	// int x;
	// cout<<(&x)<<endl;

	// float f;
	// cout<<(&f)<<endl;

	// bool b;
	// cout<<(&b)<<endl;

//******************************

	// int x = 10;

	// int* xptr = &x;

	// cout<<(&x)<<endl;
	// cout<<(xptr)<<endl;	

	// // char c = 'A';
	// // int *y = &c;

	// cout<<(*xptr)<<endl; //cout<<10<<endl
	// 						//cout<<x<<endl

//******************************
	// int x = 10;
	// int* xptr;

	// cout<<(*xptr)<<endl;

//*****************************

	// int x; //0
	// float f; //0
	// bool b; //0

	// cout<<x<<endl;
	// cout<<f<<endl;
	// cout<<b<<endl;

//******************************

	// int x = 10;
	// cout<<x<<endl;
	// int *xptr = &x;

	// cout<<*xptr<<endl;

	// *xptr = *xptr + 1;

	// cout<<x<<endl;

//*****************************

	int x = 10;

	cout<<x<<endl;

	int* xptr = &x;

	*xptr = *xptr + 2;

	int &z = x;

	z++;

	cout<<x<<endl;
	cout<<z<<endl;
	cout<<(*xptr)<<endl;

	int* zptr = &z;

	*zptr = *zptr + 2;

	cout<<x<<endl;
	cout<<(zptr)<<endl;
	cout<<(&x)<<endl;

//*****************************

	return 0;
}