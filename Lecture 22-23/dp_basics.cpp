#include <iostream>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

// int fib(int n){
// 	if(n==1 or n==0){
// 		return n;
// 	}

// 	return fib(n-1) + fib(n-2);
// }

// int dp[100] = {0,1};

// int fibMemo(int n){
// 	if(n==1 or n==0){
// 		return n;
// 	}

// 	if(dp[n]!=0){
// 		return dp[n];
// 	}

// 	int fibn1 = fibMemo(n-1);
// 	int fibn2 = fibMemo(n-2);

// 	int fibn = fibn1 + fibn2;

// 	dp[n] = fibn;

// 	// for(int i=0;i<n;i++){
// 	// 	cout<<dp[i]<<" ";
// 	// }
// 	// cout<<endl;

// 	return fibn;
// }

// int fib_DP(int n){

// 	int storage[n+1] = {0,1};

// 	for(int i=2;i<=n;i++){
// 		storage[i] = storage[i-1] + storage[i-2];
// 	}

// 	return storage[n];
// }

// int fib_DPBetter(int n){

// 	int storage[3] = {0,1,0};

// 	for(int i=2;i<=n;i++){
// 		storage[i] = storage[i-1] + storage[i-2];
// 		//TODO
// 	}

// 	return storage[n];
// }

// int countBoardPath(int start,int end){
// 	if(start==end){
// 		return 1;
// 	}

// 	if(start>end){
// 		return 0;
// 	}

// 	int count = 0;

// 	for(int dice=1;dice<=6;dice++){
// 		count+=countBoardPath(start+dice,end);
// 	}

// 	return count;
// }


// int countBoardPathMemo(int start,int end,int BoardDP[]){
// 	if(start==end){
// 		return 1;
// 	}

// 	if(start>end){
// 		return 0;
// 	}

// 	if(BoardDP[start]!=0){
// 		return BoardDP[start];
// 	}

// 	int count = 0;

// 	for(int dice=1;dice<=6;dice++){
// 		count+=countBoardPathMemo(start+dice,end,BoardDP);
// 	}

// 	BoardDP[start] = count;

// 	for(int i=0;i<10;i++){
// 		cout<<BoardDP[i]<<"	 ";
// 	}
// 	cout<<endl;

// 	return count;
// }

// int countBoardPath_DP(int start,int end){

// 	int countBoardDP[end+1]={0};
// 	countBoardDP[end] = 1;

// 	for(int i=end-1;i>=start;i--){
// 		for(int dice = 1;dice<=6;dice++){

// 			if(i+dice>end){
// 				break;
// 			}

// 			countBoardDP[i]+=countBoardDP[i+dice];
// 		}
// 	}

// 	return countBoardDP[start];
// }

// int reduceToOne(int n){
// 	if(n==1){
// 		return 0;
// 	}

// 	int count1 = INT_MAX;
// 	int count2 = INT_MAX;
// 	int count3 = INT_MAX;

// 	if(n%3==0){
// 		count1 = 1 + reduceToOne(n/3);
// 	}

// 	if(n%2==0){
// 		count2 = 1 + reduceToOne(n/2);
// 	}

// 	count3 = 1 + reduceToOne(n-1);

// 	return min(count1,min(count2,count3));
// }

// int reduceToOneMemo(int n,int reduceDP[]){
// 	if(n==1){
// 		return 0;
// 	}

// 	if(reduceDP[n]!=0){
// 		return reduceDP[n];
// 	}

// 	int count1 = INT_MAX;
// 	int count2 = INT_MAX;
// 	int count3 = INT_MAX;

// 	if(n%3==0){
// 		count1 = 1 + reduceToOneMemo(n/3,reduceDP);
// 	}

// 	if(n%2==0){
// 		count2 = 1 + reduceToOneMemo(n/2,reduceDP);
// 	}

// 	count3 = 1 + reduceToOneMemo(n-1,reduceDP);

// 	reduceDP[n] =  min(count1,min(count2,count3));

// 	// for(int i=0;i<n;i++){
// 	// 	cout<<reduceDP[i]<<" "; 
// 	// }
// 	// cout<<endl;

// 	return reduceDP[n];
// }

// int reduceToOne_DP(int n){

// 	int reduceDP[n+1];
// 	reduceDP[0] = 0;
// 	reduceDP[1] = 0;
	
// 	for(int i=2;i<=n;i++){

// 		int count1 = INT_MAX;
// 		int count2 = INT_MAX;
// 		int count3 = INT_MAX;


// 		if(i%3==0){
// 			count1 = reduceDP[i/3] + 1;
// 		}

// 		if(i%2==0){
// 			count2 = reduceDP[i/2] + 1;
// 		}

// 		count3 = reduceDP[i-1] + 1;

// 		reduceDP[i] = min(count1,min(count2,count3));
// 	}

// 	return reduceDP[n];
// }

// int treeDP[10] = {1,1};

// int numberOfBST(int n){
// 	if(n==0){
// 		return 1;
// 	}

// 	if(treeDP[n]!=0){
// 		return treeDP[n];
// 	}

// 	int ans = 0;

// 	for(int i=1;i<=n;i++){
// 		ans += numberOfBST(i-1)*numberOfBST(n-i);
// 	}

// 	treeDP[n] = ans;

// 	for(int x=0;x<n;x++){
// 		cout<<treeDP[x]<<" ";
// 	}
// 	cout<<endl;

// 	return ans;
// }

// int catalanNumber(int n){

// 	int treeDP[n+1];
// 	treeDP[0] = 1;
// 	treeDP[1] = 1;

// 	for(int i=2;i<=n;i++){
// 		treeDP[i] = 0;
// 		for(int j=1;j<=i;j++){
// 			treeDP[i] += treeDP[j-1]*treeDP[i-j]; 
// 		}
// 	}

// 	return  treeDP[n];
// }

// int longestIncreasingSubsequence(int arr[],int n){

// 	int dp[n] = {1};

// 	int maxLength = 0;

// 	for(int x = 1;x<n;x++){
// 		dp[x] = 1;
// 		for(int y = 0;y<x;y++){

// 			if(arr[x] > arr[y]){
// 				dp[x] = max(dp[x],dp[y] + 1);
// 			}

// 		}

// 		maxLength = max(dp[x],maxLength);
// 	}

// 	return maxLength;
// }

// int longestCommonSubsequence(string s1,string s2){
// 	if(s1.length()==0 or s2.length()==0){
// 		return 0;
// 	}

// 	char ch1 = s1[0];
// 	char ch2 = s2[0];

// 	string ros1 = s1.substr(1);
// 	string ros2 = s2.substr(1);

// 	int result = 0;

// 	if(ch1==ch2){
// 		result = 1 + longestCommonSubsequence(ros1,ros2);
// 	}else{

// 		int check1 = longestCommonSubsequence(ros1,s2);
// 		int check2 = longestCommonSubsequence(s1,ros2);

// 		result = max(check2,check1);
// 	}

// 	return result;
// }

// int dp[10][10];

// int longestCommonSubsequenceMemo(char s1[],int i,char s2[],int j){
// 	if(s1[i]=='\0' or s2[j]=='\0'){
// 		dp[i][j] = 0;
// 		return 0;
// 	}

// 	if(dp[i][j]!=-1){
// 		return dp[i][j];
// 	}

// 	char ch1 = s1[i];
// 	char ch2 = s2[j];

// 	int result = 0;

// 	if(ch1==ch2){
// 		result = 1 + longestCommonSubsequenceMemo(s1,i+1,s2,j+1);
// 	}else{

// 		int check1 = longestCommonSubsequenceMemo(s1,i+1,s2,j);
// 		int check2 = longestCommonSubsequenceMemo(s1,i,s2,j+1);

// 		result = max(check2,check1);
// 	}

// 	dp[i][j] = result;

// 	for(int i=0;i<=5;i++){
// 		for(int j=0;j<=5;j++){
// 			if(dp[i][j]==-1){
// 				cout<<"* ";
// 			}else{
// 				cout<<dp[i][j]<<" ";
// 			}
// 		}
// 		cout<<endl;
// 	}
// 	cout<<"*************************"<<endl;

// 	return result;
// }

int longestCommonSubsequence_DP(char s1[],char s2[]){

	int lcsDP[6][6];

	for(int i = 5;i>=0;i--){

		for(int j = 5;j>=0;j--){

			if(i==5 or j==5){
				lcsDP[i][j] = 0;
				continue;
			}

			if(s1[i]==s2[j]){
				lcsDP[i][j] = 1 + lcsDP[i+1][j+1];
			}else{

				lcsDP[i][j] = max(lcsDP[i][j+1],lcsDP[i+1][j]);
			}

		}

	}

	return lcsDP[0][0];

}

int dp[10][10];

int editDistance(char s1[],int i,char s2[],int j){
	if(s1[i]=='\0'){
		dp[i][j] = sizeof(s2) - sizeof(s1);
		cout<<dp[i][j]<<"BASE"<<endl;
		return sizeof(s2) - sizeof(s1);
	}

	if(s2[j]=='\0'){
		dp[i][j] = sizeof(s1) - sizeof(s2);
		cout<<dp[i][j]<<"BASE"<<endl;
		return sizeof(s1) - sizeof(s2);
	}

	if(dp[i][j]!=-1){
		return dp[i][j];
	}

	char ch1 = s1[i];
	char ch2 = s2[j];

	int result = INT_MAX;

	if(ch1==ch2){

		result = editDistance(s1,i+1,s2,j+1);

	}else{

		int del = 1 + editDistance(s1,i+1,s2,j);
		int insertion = 1 + editDistance(s1,i,s2,j+1);
		int replace = 1 + editDistance(s1,i+1,s2,j+1);

		result = min(del,min(insertion,replace));
	}

	dp[i][j] = result;

		// for(int i=0;i<=sizeof(s1);i++){
		// 	for(int j=0;j<=sizeof(s2);j++){
		// 		if(dp[i][j]==-1){
		// 			cout<<"* ";
		// 		}else{
		// 			cout<<dp[i][j]<<" ";
		// 		}
		// 	}
		// 	cout<<endl;
		// }
		// cout<<"*************************"<<endl;

	return result;
}

int editDistance_DP(char s1[],char s2[]){

	int editDP[strlen(s1) + 1][strlen(s2) + 1];

	// cout<<strlen(s1)<<endl;
	// cout<<strlen(s2)<<endl;

	int check = 0;
	for(int j=strlen(s2);j>=0;j--){
		editDP[strlen(s1)][j] = check;
		check++; 
	}

	check = 0;
	for(int i=strlen(s1);i>=0;i--){
		editDP[i][strlen(s2)] = check;
		check++;
	}

	for(int i = strlen(s1);i>= 0;i--){

		for(int j = strlen(s2);j>= 0;j--){
			if(i==strlen(s1) or j==strlen(s2)){
				// editDP[i][j] =abs(abs(i-j) - abs(strlen(s1) - strlen(s2)));
				continue;
			}

			if(s1[i]==s2[j]){
				editDP[i][j] = editDP[i+1][j+1];
			}else{
				editDP[i][j] = 1 + min(editDP[i+1][j],min(editDP[i][j+1],editDP[i+1][j+1]));
			}
		}
	}

	// for(int i=0;i<9;i++){
	// 	for(int j=0;j<7;j++){
	// 		cout<<editDP[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	return editDP[0][0];
}

int knapDP[5][9];

int knapSack(int value[],int weight[],int si,int capacity,int n){
	if(si==n){
		knapDP[si][capacity] = 0;
		return 0;
	}

	if(knapDP[si][capacity]!=-1){
		return knapDP[si][capacity];
	}

	int valueInclude = INT_MIN;
	int valueExclude = INT_MIN;

	if(weight[si]<=capacity){
		valueInclude = value[si] + knapSack(value,weight,si+1,capacity - weight[si],n);
	}

	valueExclude =knapSack(value,weight,si+1,capacity,n);

	int result = max(valueInclude,valueExclude);

	knapDP[si][capacity] = result;

	for(int i=0;i<5;i++){
		for(int j=0;j<9;j++){
			if(knapDP[i][j]==-1){
				cout<<"-1 ";
			}
			else if(knapDP[i][j]==0){
				cout<<"00 ";
			}else{
				cout<<knapDP[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	cout<<"**************"<<endl;

	return result;
}

int knapSack_DP(int value[],int weight[],int capacity,int n){

	int storageKnapSack[n+1][capacity+1];

	for(int i=0;i<=n;i++){
		storageKnapSack[i][0] = 0; 
	}

	for(int j=0;j<=capacity;j++){
		storageKnapSack[0][j] = 0;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=capacity;j++){

			// if(i==0 or j==0){
			// 	storageKnapSack[i][j] = 0;
			// 	continue;
			// }

			if(weight[i]>j){
				storageKnapSack[i][j] = storageKnapSack[i-1][j];
			}else{
				storageKnapSack[i][j] = max(storageKnapSack[i-1][j],value[i] + storageKnapSack[i-1][j - weight[i]]);
			}

			cout<<storageKnapSack[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;


	return storageKnapSack[n][capacity];

}

int main(){

	// clock_t start = clock();
	// fib_DP(90);
	// clock_t end_1 = clock();
	// fibMemo(90);
	// clock_t end_2 = clock();
	
	// cout<<(end_1 - start)<<endl;
	// cout<<(end_2 - end_1)<<endl;

	// fibMemo(5);

	// int BoardDP[11] = {0};
	// BoardDP[10] = 1;
	// cout<<countBoardPathMemo(0,10,BoardDP)<<endl;

	// cout<<countBoardPath_DP(0,10)<<endl;

	// cout<<reduceToOne(21)<<endl;

	// int reduceDP[102] = {0}; 
	// cout<<reduceToOneMemo(101,reduceDP)<<endl;

	// cout<<reduceToOne_DP(21)<<endl;

	// cout<<numberOfBST(5)<<endl;

	// cout<<catalanNumber(5)<<endl;

	// int arr[] = {-1,9,2,-2,7,8,2};
	// cout<<longestIncreasingSubsequence(arr,7)<<endl;

	// cout<<longestCommonSubsequence("agehi","pgbei")<<endl;
	// char s1[] = "agehi";
	// char s2[] = "pgbei";

	// for(int i=0;i<=5;i++){
	// 	for(int j=0;j<=5;j++){
	// 		dp[i][j] = -1;
	// 	}
	// }

	// cout<<longestCommonSubsequenceMemo(s1,0,s2,0)<<endl;

	// cout<<longestCommonSubsequence_DP(s1,s2)<<endl;

	// char s1[] = "cassngt";
	// char s2[] = "";

	// // cout<<sizeof(s1)<<endl;
	// // cout<<sizeof(s2)<<endl;

	// for(int i=0;i<=sizeof(s1);i++){
	// 	for(int j=0;j<=sizeof(s2);j++){
	// 		dp[i][j] = -1;
	// 	}
	// }

	// cout<<editDistance(s1,0,s2,0)<<endl;

	// cout<<editDistance_DP(s1,s2)<<endl;

	int value[] = {50,40,70,40};
	int weight[] = {5,4,6,3};
	int capacity = 8;

	// for(int i=0;i<5;i++){
	// 	for(int j=0;j<9;j++){
	// 		knapDP[i][j] = -1; 
	// 	}
	// }

	// cout<<knapSack(value,weight,0,capacity,4)<<endl;

	cout<<knapSack_DP(value,weight,capacity,4)<<endl;

	return 0;
}