#include <iostream>

using namespace std;

int main(){

	// bool p = 12;
	// int p = 12;

	int  i = 123;

	cout<<i<<endl;

	cout<<"***********************"<<endl;

	int n = 6;
	int r = 4;
	int nr = n - r;

	int n_fact = 1;
	for(i = 1;i<=n;i++){
		cout<<i<<endl;
		n_fact = n_fact * i;
	}

	cout<<"*********************"<<endl;

	int r_fact = 1;
	for(int i = 1;i<=r;i++){
		cout<<i<<endl;
		r_fact = r_fact * i;
	}


	cout<<"*********************"<<endl;

	int nr_fact = 1;
	for(int i = 1;i <= n-r;i++){
		cout<<i<<endl;
		nr_fact = nr_fact*i;
	}

	cout<<"*********************"<<endl;

	cout<<i<<endl;

	cout<<"************************"<<endl;

	int factorial = n_fact/(r_fact*nr_fact);

	cout<<factorial<<endl;

	return 0;

	cout<<"skjvskvnskjvnsfs";

	int x = 1324;

	cout<<x<<endl;
}

// #include <iostream>

// using namespace std;

// int main(){

// 	if(123){
// 		int i = 0;
// 		cout<<i<<endl;
// 	}else{

// 		cout<<i<<endl;
// 		int  p = 23;
// 		cout<<"This is else"<<endl;
// 	}

// 	cout<<p<<endl;
// 	cout<<i<<endl;

// 	return 0;
// }
