#include <iostream>

using namespace std;

string ultraFast(string s1,string s2){



	for(int i=0;i<s1.length();i++){

		if(s1[i]==s2[i]){
			// cout<<'0';
			s1[i] = '0';
		}else{
			// cout<<'1';
			s1[i] = '1';
		}

	}

	return s1;
}

//TODO

// void rotate(int arr[4][4],int n){

// 	for(int row=0;row<n/2;row++){

// 		for(int col=row;col<n-1-row;col++){

// 			//Col change

// 		}

// 	}

// }

int count = 0;

void subsetSum(int arr[],int i,int n,int sum){

	subsetSum(arr,i+1,n,sum);
	subsetSum(arr,i+1,n,sum+arr[i]);

	//TODO
}

void generateParathesis(int n,int openingB,int closingB,string ans){
	if(closingB==n){
		//string -> build
		cout<<ans<<endl;
		return;
	}

	if(openingB > closingB){
		generateParathesis(n,openingB,closingB+1,ans+')');
	}

	if(openingB < n){
		generateParathesis(n,openingB+1,closingB,ans+'(');
	}
}

int optimalGame(int arr[],int i,int j){
	if(i>j){
		return 0;
	}

	int result;

	int first = arr[i] + min(optimalGame(arr,i+2,j),optimalGame(arr,i+1,j-1));
	int last = arr[j] + min(optimalGame(arr,i+1,j-1),optimalGame(arr,i,j-2));

	result = max(first,last);

	return result;
}

int tillingProblem(int n){
	// if(n==1){
	// 	return 1;
	// }

	// if(n==2){
	// 	return 2;
	// }
	if(n==1 or n==2){
		return n;
	}

	int horizontal = tillingProblem(n-2);
	int vertical = tillingProblem(n-1);

	int total=horizontal+vertical;
	return total;
}

int main(){

	// string s1 = "10111";
	// string s2 = "10000";

	// cout<<ultraFast(s1,s2)<<endl;

}