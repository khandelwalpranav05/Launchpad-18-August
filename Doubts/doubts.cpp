#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int countBinaryString(int n){
	if(n==0 or n==1){
		return n;
	}

	int withZero = countBinaryString(n-1);
	int withOne = countBinaryString(n-2);

	int total = withOne + withZero;
	return total;
}

int maxBiotonicSubarray(int arr[],int n){

	int inc[n];
	int dec[n];

	inc[0]=1;
	dec[n-1]=1;

	for(int i=1;i<n;i++){
		if(arr[i]>=arr[i-1]){
			inc[i] = inc[i-1]+1;
		}else{
			inc[i] = 1;
		}
	}

	for(int i=n-2;i>=0;i--){
		if(arr[i]>=arr[i+1]){
			dec[i] = dec[i+1]+1;
		}else{
			dec[i] = 1;
		}
	}

	int max = 0;

	for(int i=0;i<n;i++){
		int curr = inc[i] + dec[i] -1;

		if(curr>max){
			max = curr;
		}
	}

	return max;
}

int rainWaterHarvesting(int arr[],int n){

	int left[n];
	int right[n];

	left[0] = arr[0];
	right[n-1] = arr[n-1];

	for(int i=1;i<n;i++){
		if(arr[i]>left[i-1]){
			left[i] = arr[i];
		}else{
			left[i] = left[i-1];
		}
	}

	for(int i=n-2;i>=0;i--){
		if(arr[i]>right[i+1]){
			right[i] = arr[i];
		}else{
			right[i] = right[i+1];
		}
	}

	int sum = 0;

	for(int i=0;i<n;i++){
		sum+=min(left[i],right[i]) - arr[i];
	}

	return sum;
}

int maxCircularSum(int arr[],int n){

	int currMax = arr[0];
	int totalMax = arr[0];
	int currMin = arr[0];
	int totalMin = arr[0];
	int sum = arr[0];

	for(int i=1;i<n;i++){

		if(currMax+arr[i] > arr[i]){
			currMax+=arr[i];
		}else{
			currMax = arr[i];
		}

		totalMax = max(totalMax,currMax);

		if(currMin + arr[i] < arr[i]){
			currMin+=arr[i];
		}else{
			currMin = arr[i];
		}

		totalMin = min(currMin,totalMin);

		sum += arr[i];
	}

	if(sum==totalMin){
		return totalMax;
	}

	return max(sum-totalMin,totalMax);

}

int myCompare(int a,int b){

	// if(a+b < 73645){
	// 	return 1;
	// }else{return 0;}

	if(a<b){
		return 1;
	}else{
		return 0;
	}
}

int stringCompare(string a,string b){

	string ab = a.append(b);
	string ba = b.append(a);

	if(ab>ba){
		return 1;
	}else{
		return 0;
	}

}

void biggestNumber(string arr[],int n){

	// int brr[] = {5,4,3,2,1};
	// sort(brr,brr+4,myCompare);

	// for(int i=0;i<5;i++){
	// 	cout<<brr[i]<<" ";
	// }
	// cout<<endl;

	sort(arr,arr+n,stringCompare);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

}

int main(){

	// cout<<countBinaryString(4)<<endl;

	// int arr[] = {12,4,78,90,45,3};
	// int n = 6;

	// cout<<maxBiotonicSubarray(arr,n)<<endl;


	// int arr[] = {8,-8,9,-9,10,-11,12};
	// int n = 7;
	// cout<<maxCircularSum(arr,n)<<endl;



	string arr[] = {"54","546","548","60"};
	int n = 4;

	biggestNumber(arr,n);




	return 0;
}