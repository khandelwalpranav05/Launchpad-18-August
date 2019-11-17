#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long minCost(){
	int arr[] = {3, 7, 9, 4};

	priority_queue<int,vector<int>,greater<int> > pq;
	// priority_queue<int> pq;

	for(int i=0;i<4;i++){
		pq.push(arr[i]);
	}

	long sum = 0; 
  
    while (pq.size() > 1) { 
        int first = pq.top(); 
        pq.pop(); 
        int second = pq.top(); 
        pq.pop(); 
  
        sum += first + second; 
        pq.push(first + second); 
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

void downHeapify(int arr[],int i,int n){

		int left = 2*i + 1;
		int right = 2*i + 2;

		int largestIndex = i;

		if(left<n and arr[largestIndex]<arr[left]){
			largestIndex = left;
		}

		if(right<n and arr[largestIndex]<arr[right]){
			largestIndex = right;
		}

		if(largestIndex!=i){
			swap(arr[largestIndex],arr[i]);
			downHeapify(arr,largestIndex,n);
		}
	}

void heapSort(int arr[],int n){

	for(int i=n-1;i>=0;i--){
		downHeapify(arr,i,n);
	}

	for(int i=n-1;i>=0;i--){
		swap(arr[i],arr[0]);
		downHeapify(arr,0,i);
	}

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	// int arr[] = {4,2,3,6};

	// cout<<minCost(arr,4)<<endl;

	// int arr[] = {3,2,1,5,6,7,0};
	// int k = 2;

	// cout<<KthLargestElement(arr,7,k)<<endl;

	int arr[] = {5,3,1,2,4};
	heapSort(arr,5);

	return 0;
}