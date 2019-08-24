#include <iostream>

using namespace std;

int main(){

	// int x = 10;

	// x == 10 ? cout<<"Yes"<<endl : cout<<"No"<<endl;

	// if(x==10){
	// 	cout<<"Yes"<<endl;
	// }else{
	// 	cout<<"No"<<endl;
	// }

	// int no = 23;

	// no%2 ? cout<<"Even"<<endl : cout<<"Odd"<<endl;


	int n;
	cin>>n;

	for(int row = 1;row<=n;row++){

		//Spaces
		for(int space = 1;space <= n - row; space++){
			cout<<" ";
		}

		//Stars
		for(int star = 1;star <= 2*row - 1;star++){
			cout<<"*";
		}

		cout<<endl;
	}

	return 0;
}