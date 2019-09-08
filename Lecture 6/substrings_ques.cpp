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
	
	int result = 0;

	for(int i=0;i<str.length();i++){

		for(int j=0; i-j>=0 and i+j<str.length() ;j++){

			if(str[i-j]==str[i+j]){
				result++;
			}else{
				break;
			}
		}

		for(int j=0; i-j>=0 and i+j+1<str.length() ;j++){
			if(str[i-j]==str[i+j+1]){
				result++;
			}else{
				break;
			}
		}
	}

	return result;
}

int main(){

	// string str = "Launchpad";

	string str = "naman";
	printSubstring(str);
	// cout<<str.substr(1,2)<<endl;

	// cout<<str.substr(3)<<endl;

	cout<<"Number of Palindromic Substrings "<<countPalindromicSubstring(str)<<endl;	

	return 0;
}