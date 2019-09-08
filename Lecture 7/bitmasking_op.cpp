#include <iostream>

using namespace std;

int setbitsCount(int n){
	
	int count = 0;

	while(n!=0){
		int temp = (n&1);
		count += temp; //count = count + temp

		n = n>>1;
	}

	return count;
}

int main(){

	// cout<<(5&7)<<endl;
	// cout<<(5|7)<<endl;
	// cout<<(5^7)<<endl;

	// cout<<(5>>1)<<endl;
	// cout<<(5<<1)<<endl;

	// cout<<setbitsCount(7)<<endl;
	// cout<<setbitsCount(13)<<endl;

	cout<<__builtin_popcount(7)<<endl;
	cout<<__builtin_popcount(13)<<endl;

	return 0;
}