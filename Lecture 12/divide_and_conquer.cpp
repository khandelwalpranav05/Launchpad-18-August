#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void merge(int arr[],int s,int e){

	int mid=(s+e)/2;

	int i = s;
	int j = mid+1;

	int temp[e-s+1];

	int k = 0;

	while(i<=mid and j<=e){

		if(arr[i]>arr[j]){
			temp[k] = arr[j];
			k++;
			j++;
		}else{
			temp[k] = arr[i];
			k++;
			i++;
		}
	}

	while(i<=mid){
		temp[k] = arr[i];
		k++;
		i++;
	}

	while(j<=e){
		temp[k] = arr[j];
		k++;
		j++;
	}

	int  p = 0;
	for(int x = s; x <= e;x++){
		arr[x] = temp[p];
		p++;
	}

}

void mergeSort(int arr[],int s,int e){
	if(s>=e){
		return; 
	}

	int mid = (s+e)/2;

	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e);

	merge(arr,s,e);
}

int binarySearch(int arr[],int n,int data){

	int s = 0;
	int e = n-1;

	while(s<=e){

		int mid = (s+e)/2;

		if(arr[mid]==data){
			return mid;

		}else if(arr[mid]<data){
			s = mid+1;
		}else{
			e = mid-1;
		}
	}

	return -1;
}

int lowerBound(int arr[],int n){

	int s = 0;
	int e = n-1;

	int ans = -1;

	while(s<=e){
		int mid = (s+e)/2;

		if(arr[mid]==data){
			ans = mid;
			e = mid-1;

		}else if(arr[mid]<data){
			s = mid+1;
		}else{
			e = mid-1;
		}

	}

	return ans;
}

int upperBound(int arr[],int n){

	int s = 0;
	int e = n-1;

	int ans = -1;

	while(s<=e){
		int mid = (s+e)/2;

		if(arr[mid]==data){
			ans = mid;
			s = mid+1;

		}else if(arr[mid]<data){
			s = mid+1;
		}else{
			e = mid-1;
		}

	}

	return ans;
}

int rotatedSearch(int arr,int s,int e,int data){


	int mid = (s+e)/2;

	if(arr[mid]==data){

	}

	//Left side mid
	if(){
		if(){

		}else{

		}
	}

	//Right side mid
	if(){
		if(){

		}else{
			
		}
	}

}

int main(){

	// int arr[] = {5,4,3,2,1,6};
	// mergeSort(arr,0,5);

	// for(int i=0;i<6;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	// int arr[] = {1,2,3,4,5,7,8,9};
	// cout<<binarySearch(arr,8,6)<<endl;
	// cout<<binarySearch(arr,8,7)<<endl;

	// int arr[] = {8,7,6,5,4,3,2,1};
	// sort(arr,arr+5);

	// for(int i=0;i<8;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;


	return 0;
}