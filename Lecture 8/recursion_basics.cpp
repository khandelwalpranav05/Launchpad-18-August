#include <iostream>
using namespace std;

int factorial(int n){
	if(n==0){
		return 1;
	}

	int fact_n1 = factorial(n-1);
	int fact_n = fact_n1*n;
	return fact_n;
}

int power(int n,int p){
	if(p==0){
		return 1;
	}

	int power_n1 = power(n,p-1);
	int power_n = power_n1*n;
	return power_n;
}

void printIncreasing(int n){
	if(n==0){
		return;
	}

	printIncreasing(n-1);
	cout<<n<<endl;
	return;
}

void printDecreasing(int n){
	if(n==0){
		return;
	}

	cout<<n<<endl;
	printDecreasing(n-1);
	return;
}

void printDI(int n){
	if(n==0){
		return;
	}

	cout<<n<<endl;
	printID(n-1);
	cout<<n<<endl;
	return;
}

bool isSorted(int arr[],int size,int idx){
	if(idx==size-1){
		return true;
	}

	bool rest_of_the_array = isSorted(arr,size,idx+1);

	if(rest_of_the_array and arr[idx]<arr[idx+1]){
		return true;
	}else{
		return false;
	}
}

int linearSearch(int arr[],int size,int idx,int data){
	if(idx==size){
		return -1;
	}

	if(arr[idx]==data){
		return idx;
	}

	int indexFound = linearSearch(arr,size,idx+1,data);
	return indexFound;
}

int lastIndex(int arr[],int size,int idx,int data){
	if(idx==size){
		return -1;
	}

	int indexFound = lastIndex(arr,size,idx+1,data);

	if(indexFound!=-1){
		return indexFound;
	}else{
		if(arr[idx]==data){
			return idx;
		}else{
			return -1;
		}
	}

}

int main(){

	// cout<<factorial(5)<<endl;
	// cout<<power(2,-4)<<endl;
	// printIncreasing(5);
	// printDecreasing(5);
	// printDI(5);

	// int arr[] = {1,2,3,4,5,6};
	// cout<<isSorted(arr,6,0)<<endl;

	int arr[] = {1,2,3,4,5,4};
	cout<<lastIndex(arr,6,0,4)<<endl;

	return 0;
}


// Spiral
// Help Ramu
// Sum till n (recursion)
// 100!