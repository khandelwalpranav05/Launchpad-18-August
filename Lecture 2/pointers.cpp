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

	// int x = 10;

	// cout<<x<<endl;

	// int* xptr = &x;

	// *xptr = *xptr + 2;

	// int &z = x;

	// z++;

	// cout<<x<<endl;
	// cout<<z<<endl;
	// cout<<(*xptr)<<endl;

	// int* zptr = &z;

	// *zptr = *zptr + 2;

	// cout<<x<<endl;
	// cout<<(zptr)<<endl;
	// cout<<(&x)<<endl;

//*****************************

	// int x = 10;

	// int* xptr = &x;

	// cout<<(xptr)<<endl;
	// cout<<(xptr + 1)<<endl;
	// cout<<*(xptr + 1)<<endl;

	// cout<<*(&x)<<endl;
	// cout<<(*xptr + 1)<<endl;

	// cout<<(&xptr)<<endl;

//********************************

	// char c = 'A';
	// char* cptr = &c;

	// // cout<<((int)c)<<endl;

	// cout<<((void*)cptr)<<endl;
	// cout<<((bool*)&c + 1)<<endl;

	// cout<<(&c + 1)<<endl;

//****************************

	// int x = 10;

	// int* xptr = &x;

	// int* xxptr = xptr;

	// cout<<(&x)<<endl;
	// cout<<xptr<<endl;
	// cout<<xxptr<<endl;

	// int* xxptr = *xptr; // int* xxptr = x // Not possible

//*****************************
	int x = 10;

	int* xptr = &x;	
	int** xxptr = &xptr;

	cout<<(&xptr)<<endl;
	cout<<(xxptr)<<endl;

	cout<<(xxptr + 1)<<endl; 

//***************************

	return 0;
}