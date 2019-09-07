#include <iostream>

using namespace std;

int kadanesAlgo(int arr[],int n){

	int max_subarray,global_max;
	max_subarray = global_max = arr[0];

	for(int i=1;i<n;i++){
		max_subarray = max(max_subarray + arr[i],arr[i]);

		if(max_subarray > global_max){
			global_max = max_subarray;
		}
	}

	return global_max;
}

int main(){

	int arr[] = {2,-3,2,3,-1};
	int brr[] = {-2,-3,-1,-5};

	cout<<kadanesAlgo(arr,5)<<endl;
	cout<<kadanesAlgo(brr,4)<<endl;

	return 0;
}