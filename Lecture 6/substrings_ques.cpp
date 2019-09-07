#include <iostream>

using namespace std;

void printSubstring(string str){

	for(int i=0;i<str.length();i++){

		for(int j=1;j<=str.length()-i;j++){

			cout<<str.substr(i,j)<<endl;

		}

	}
}

int countPalindromicSubstring(string str){
	
}

int main(){

	// string str = "Launchpad";

	string str = "naman";
	printSubstring(str);
	// cout<<str.substr(1,2)<<endl;

	// cout<<str.substr(3)<<endl;

	return 0;
}