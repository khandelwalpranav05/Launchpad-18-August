#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int minCost(int arr[],int n){
	priority_queue<int,vector<int>,greater<int> > pq;

	for(int i=0;i<n;i++){
		pq.push(arr[i]);
	}

	int sum = 0;

	int first = pq.top();
	pq.pop();

	while(!pq.empty()){
		first+=pq.top();
		sum+=first;

		pq.pop();
	}

	return sum;
}

int KthLargestElement(int arr[],int n,int k){

	priority_queue<int,vector<int>,greater<int> > pq;

	for(int i =0;i<n;i++){
		int var = arr[i];
		if(k!=0){
			pq.push(var);
			k--;
			continue;
		}

		if(var > pq.top()){
			pq.pop();
			pq.push(var);
		}
	}

	return pq.top();
}

int main(){
	// int arr[] = {4,2,3,6};

	// cout<<minCost(arr,4)<<endl;

	int arr[] = {3,2,1,5,6,7,0};
	int k = 2;

	cout<<KthLargestElement(arr,7,k)<<endl;

	return 0;
}