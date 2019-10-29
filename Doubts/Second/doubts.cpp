#include <bits/stdc++.h>
#include<iostream>

using namespace std;

// bool isCBNumber(int n){

// 	int arr[] = {2,3,5,7,11,13,17,19,23,29};

// 	for(int i=0;i<10;i++){
// 		if(n==arr[i]){
// 			return true;
// 		}
// 	}

// 	for(int i=0;i<10;i++){
// 		if(n%arr[i]==0){
// 			return false;
// 		}
// 	}

// 	return true;
// }

// bool inRange(int s,int e,bool visited[]){

// 	for(int i=s;i<=e;i++){
// 		if(visited[i]){
// 			return false;
// 		}
// 	}

// 	return true;
// }

// int cbNumberCount(){
// 	string str = "81615";

// 	int count = 0;

// 	bool visited[str.length()];

// 	for(int i = 1;i<=str.length();i++){
// 		for(int j=0;j<=str.length()-i;j++){

// 			string substr = str.substr(j,i);
// 			int num = stoi(substr);

// 			int l = j;
// 			int r = i+j-1;

// 			if(inRange(l,r,visited) and isCBNumber(num)){
// 				count++;

// 				for(int p = l;p<=r;p++){
// 					visited[p] = true;
// 				}

// 			}
// 		}
// 	}

// 	return count;
// }

void printLexicographical(int n,int curr){
	if(curr>n){
		return;
	}

	cout<<curr<<endl;

	if(curr==0){
		for(int i=1;i<=9;i++){
			printLexicographical(n,curr*10+i);
		}

	}else{

		for(int i=0;i<=9;i++){
			printLexicographical(n,curr*10+i);
		}

	}
}

int product(int mul,int arr[],int num_size){

	int carry = 0;

	for(int i=0;i<num_size;i++){

		int temp = arr[i]*mul + carry;

		arr[i] = temp%10;

		carry = temp/10;
	}

	while(carry){

		arr[num_size] = carry%10;
		carry = carry/10;
		num_size++;

	}

	return num_size;
}

void brokenCalculator(int n){

	int arr[1000];

	arr[0] = 1;
	int num_size = 1;

	for(int i=2;i<=n;i++){
		num_size = product(i,arr,num_size);
	}

	for(int i=num_size-1;i>=0;i--){
		cout<<arr[i];
	}

	cout<<endl;
}

int sanketStrings(string str,int k){

	int ans = 0;
	int count[] = {0,0};
	int left = 0;

	for(int i=0;i<str.length();i++){

		char ch = str[i];
		count[ch - 'a']++;

		if(min(count[0],count[1])>k){
			count[str[left] - 'a']--;
			left++;
		}else{
			ans++;
		}
	}

	return ans;
}

int main(){

	// printLexicographical(21,0);

	// brokenCalculator(6);

	cout<<sanketStrings("ababaaabbbbbb",3)<<endl;

	return 0;
}