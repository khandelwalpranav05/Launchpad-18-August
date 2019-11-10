#include <iostream>
#include <climits>

using namespace std;

int fib(int n){
	if(n==1 or n==0){
		return n;
	}

	return fib(n-1) + fib(n-2);
}

int dp[100] = {0,1};

int fibMemo(int n){
	if(n==1 or n==0){
		return n;
	}

	if(dp[n]!=0){
		return dp[n];
	}

	int fibn1 = fibMemo(n-1);
	int fibn2 = fibMemo(n-2);

	int fibn = fibn1 + fibn2;

	dp[n] = fibn;

	// for(int i=0;i<n;i++){
	// 	cout<<dp[i]<<" ";
	// }
	// cout<<endl;

	return fibn;
}

int fib_DP(int n){

	int storage[n+1] = {0,1};

	for(int i=2;i<=n;i++){
		storage[i] = storage[i-1] + storage[i-2];
	}

	return storage[n];
}

int fib_DPBetter(int n){

	int storage[3] = {0,1,0};

	for(int i=2;i<=n;i++){
		storage[i] = storage[i-1] + storage[i-2];
		//TODO
	}

	return storage[n];
}

int countBoardPath(int start,int end){
	if(start==end){
		return 1;
	}

	if(start>end){
		return 0;
	}

	int count = 0;

	for(int dice=1;dice<=6;dice++){
		count+=countBoardPath(start+dice,end);
	}

	return count;
}


int countBoardPathMemo(int start,int end,int BoardDP[]){
	if(start==end){
		return 1;
	}

	if(start>end){
		return 0;
	}

	if(BoardDP[start]!=0){
		return BoardDP[start];
	}

	int count = 0;

	for(int dice=1;dice<=6;dice++){
		count+=countBoardPathMemo(start+dice,end,BoardDP);
	}

	BoardDP[start] = count;

	for(int i=0;i<10;i++){
		cout<<BoardDP[i]<<"	 ";
	}
	cout<<endl;

	return count;
}

int countBoardPath_DP(int start,int end){

	int countBoardDP[end+1]={0};
	countBoardDP[end] = 1;

	for(int i=end-1;i>=start;i--){
		for(int dice = 1;dice<=6;dice++){

			if(i+dice>end){
				break;
			}

			countBoardDP[i]+=countBoardDP[i+dice];
		}
	}

	return countBoardDP[start];
}

int reduceToOne(int n){
	if(n==1){
		return 0;
	}

	int count1 = INT_MAX;
	int count2 = INT_MAX;
	int count3 = INT_MAX;

	if(n%3==0){
		count1 = 1 + reduceToOne(n/3);
	}

	if(n%2==0){
		count2 = 1 + reduceToOne(n/2);
	}

	count3 = 1 + reduceToOne(n-1);

	return min(count1,min(count2,count3));
}

int reduceToOneMemo(int n,int reduceDP[]){
	if(n==1){
		return 0;
	}

	if(reduceDP[n]!=0){
		return reduceDP[n];
	}

	int count1 = INT_MAX;
	int count2 = INT_MAX;
	int count3 = INT_MAX;

	if(n%3==0){
		count1 = 1 + reduceToOneMemo(n/3,reduceDP);
	}

	if(n%2==0){
		count2 = 1 + reduceToOneMemo(n/2,reduceDP);
	}

	count3 = 1 + reduceToOneMemo(n-1,reduceDP);

	reduceDP[n] =  min(count1,min(count2,count3));

	// for(int i=0;i<n;i++){
	// 	cout<<reduceDP[i]<<" "; 
	// }
	// cout<<endl;

	return reduceDP[n];
}

int reduceToOne_DP(int n){

	int reduceDP[n+1];
	reduceDP[0] = 0;
	reduceDP[1] = 0;
	
	for(int i=2;i<=n;i++){

		int count1 = INT_MAX;
		int count2 = INT_MAX;
		int count3 = INT_MAX;


		if(i%3==0){
			count1 = reduceDP[i/3] + 1;
		}

		if(i%2==0){
			count2 = reduceDP[i/2] + 1;
		}

		count3 = reduceDP[i-1] + 1;

		reduceDP[i] = min(count1,min(count2,count3));
	}

	return reduceDP[n];
}

int treeDP[10] = {1,1};

int numberOfBST(int n){
	if(n==0){
		return 1;
	}

	if(treeDP[n]!=0){
		return treeDP[n];
	}

	int ans = 0;

	for(int i=1;i<=n;i++){
		ans += numberOfBST(i-1)*numberOfBST(n-i);
	}

	treeDP[n] = ans;

	for(int x=0;x<n;x++){
		cout<<treeDP[x]<<" ";
	}
	cout<<endl;

	return ans;
}

int catalanNumber(int n){

	int treeDP[n+1];
	treeDP[0] = 1;
	treeDP[1] = 1;

	for(int i=2;i<=n;i++){
		treeDP[i] = 0;
		for(int j=1;j<=i;j++){
			treeDP[i] += treeDP[j-1]*treeDP[i-j]; 
		}
	}

	return  treeDP[n];
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

	cout<<catalanNumber(5)<<endl;

	return 0;
}