#include <iostream>

using namespace std;

void printPattern(int n){

	for(int row = 1;row <= n; row++){

		for(int space = 1;space <= n - row; space++){
			cout<<" ";
		}

		for(int star = 1;star <= 2*row - 1;star++){
			cout<<"*";
		}

		cout<<endl;
	}

	for(int row = n-1;row>=1;row--){

		for(int space = 1;space <= n - row; space++){
			cout<<" ";
		}

		for(int star = 1;star <= 2*row - 1;star++){
			cout<<"*";
		}
		cout<<endl;
	}
}

int main(){

	int n;
	cin>>n;

	printPattern(n);

	return 0;
}