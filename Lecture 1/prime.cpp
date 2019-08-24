#include <iostream>

using namespace std;

int main(){

	int n;
	cout<<"Enter the Number"<<endl;
	cin>>n;

	cout<<"Entered"<<endl;
	int i = 2;

	while(i<n){

		if(n%i==0){
			cout<<"Not Prime"<<endl;
			break;
		}

		i = i + 1;

	}

	if(i==n){
		cout<<"Prime"<<endl;
	}

	return 0;
}