//Given a string str consisting of a sentence, the task is to reverse every word of the sentence except the first and last character of the words.
#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

string reverseWord(string str){
	//cout<<str<<endl;
	int n = str.length();
	int i = 1;
	int j = n-2;

	while(i<j){
		char temp = str[i];
		str[i] = str[j];
		str[j]=temp;
		i++;
		j--;
	}
	return str;

}

int main(int argc, char const *argv[])
{
	char arr[40] = "lazy fox jumps over";

	char* tok = strtok(arr," ");

	while(tok != NULL){
		cout<<reverseWord(tok)<<" ";
		tok = strtok(NULL," ");

	}
	cout<<endl;

	return 0;
}