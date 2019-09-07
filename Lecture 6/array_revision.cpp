#include <iostream>

using namespace std;

void swap(int arr[],int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int main(){

	int arr[] = {1,2,3,4,5,6,7};

	for(int i=0;i<7;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	cout<<"*************************"<<endl;
	cout<<arr<<endl;
	cout<<(arr+1)<<endl;
	cout<<"**************************"<<endl;
	
	swap(arr,0,6);

	for(int i=0;i<7;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;


	return 0;
}