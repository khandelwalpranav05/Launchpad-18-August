#include <iostream>

using namespace std;

int main(){

	int n;
	cin>>n;

	for(int row = 1; row<=n; row++){

		int val = row%2==0 ? 0 : 1;

		for(int col=1;col<=row;col++){
			cout<<val<<" ";

			// if(val==0){
			// 	val = 1;
			// }else{
			// 	val = 0;
			// }

			val = 1 - val;
		}

		cout<<endl;
	}

	return 0;
}