#include <iostream>

using namespace std;

void swap(int arr[],int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void insertionSort(int arr[],int n){

	int divider = 1;

	while(divider<n){
		for(int i=divider;i>0;i--){
			if(arr[i-1]>arr[i]){
				swap(arr,i,i-1);
			}else{
				break;
			}
		}

		divider++;
	}
}

int main(){

	int arr[] = {5,4,3,2,1};

	insertionSort(arr,5);

	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}