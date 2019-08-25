#include <iostream>

using namespace std;

int factorial(int val){
	int result = 1;

	for(int i=1;i<=val;i++){
		result = result*i;
	}

	return result;
}


int main(){

	int n = 6;
	int r = 4;
	int nr = n - r;

	// int n_fact = 1;
	// for(i = 1;i<=n;i++){
	// 	n_fact = n_fact * i;
	// }

	// int r_fact = 1;
	// for(int i = 1;i<=r;i++){
	// 	r_fact = r_fact * i;
	// }

	// int nr_fact = 1;
	// for(int i = 1;i <= n-r;i++){
	// 	nr_fact = nr_fact*i;
	// }

	// int factorial = n_fact/(r_fact*nr_fact);

	// cout<<factorial<<endl;

	// int n_fact = factorial(n);
	// int r_fact = factorial(r);
	// int nr_fact = factorial(nr);

	// int result = n_fact/(r_fact*nr_fact);
	// int result = factorial(n)/(factorial(r)*factorial(nr));
	// cout<<result<<endl;

	cout<<factorial(r)<<endl;

	return 0;
}
