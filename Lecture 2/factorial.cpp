#include<iostream>

using namespace std;

int main(){

	int n;
	cout<<"Enter the Number"<<endl;
	cin>>n;

	int mul = 1;

	for(int i=1;i<=n;i++){
		mul = mul*i;
	}

	cout<<mul<<endl;

	return 0;
}