#include <iostream>

using namespace std;

int sqrt(int n){
	int ans = 1;

	while(ans*ans<=n){
		ans = ans + 1;
	}

	return ans-1;
}

int main(){

	cout<<sqrt(25)<<endl;

	return 0;
}