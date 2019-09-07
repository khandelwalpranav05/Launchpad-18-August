#include <iostream>

using namespace std;

bool isPalindrome(string str){

	int left = 0;
	int right = str.length() - 1;

	while(left<=right){

		if(str[left]!=str[right]){
			return false;
		}

		left++;
		right--;

	}

	return true;

}

string toggle(string str){

	for(int i=0;i<str.length();i++){

		if(str[i]>='A' and str[i]<='Z'){
			str[i] = str[i] + 'a' - 'A';
		}else if(str[i]>='a' and str[i]<='z'){
			str[i] = str[i] + 'A' - 'a';
		}
	}

	return str;
}

int maxFrequency(string str){
	int freq[256] = {0};

	for(int i=0;i<str.length();i++){
		char cc = str[i];

		freq[cc]++;
	}

	int max = freq[0];

	for(int i=1;i<256;i++){
		if(freq[i] > max){
			max = freq[i];
		}
	}

	return max;
}

int main(){

	// string str = "NamaN";

	// cout<<isPalindrome(str)<<endl;
	// toggle(str);
	// // cout<<new_string<<endl;

	// cout<<str<<endl;

	// cout<<sizeof(str)<<endl;

	// string str = "aaabbcbdabbbc";
	// cout<<maxFrequency(str)<<endl;

	return 0;
}