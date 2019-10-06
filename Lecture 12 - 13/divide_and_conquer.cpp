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

		// int mid = (s+e)/2;
		int mid = s + (e-s)/2;

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

int lowerBound(int arr[],int n,int data){

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

int upperBound(int arr[],int n,int data){

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

int rotatedSearch(int arr[],int s,int e,int data){
	if(s>e){
		return -1;
	}

	int mid = (s+e)/2;

	if(arr[mid]==data){
		return mid;
	}

	if(arr[mid]>=arr[s]){
		if(data>=arr[s] and data<=arr[mid]){
			return rotatedSearch(arr,s,mid-1,data);
		}else{
			return rotatedSearch(arr,mid+1,e,data);
		}
	}else{

		if(data>=arr[mid] and data<=arr[e]){
			return rotatedSearch(arr,mid+1,e,data);
		}else{
			return rotatedSearch(arr,s,mid-1,data);
		}
	}
}

int uniqueNumber(int arr[],int s,int e){
	if(s>e){
		return -1;
	}

	int mid = s + (e-s)/2;

	if(arr[mid]!=arr[mid-1] and arr[mid]!=arr[mid+1]){
		return mid;
	}

	if(arr[mid]==arr[mid+1]){

		int dist = mid - s;

		if(dist&1){
			return uniqueNumber(arr,s,mid-1);
		}else{
			return uniqueNumber(arr,mid+2,e);
		}
	}

	if(arr[mid]==arr[mid-1]){
		int dist = e - mid;

		if(dist&1){
			return uniqueNumber(arr,mid+1,e);
		}else{
			return uniqueNumber(arr,s,mid-2);
		}
	}
}

bool isValid(int arr[],int n,int k,int mid){

	int painters = 1;
	int paintingTime = 0;

	for(int i=0;i<n;i++){

		paintingTime+=arr[i];

		if(paintingTime>mid){
			painters++;
			if(painters>k){
				return false;
			}
			paintingTime = arr[i];
		}
	}

	return true;
}

int painterProblem(int arr[],int n,int k,int time=1){

	// int minTime = max(arr)
	int minTime = 40;

	// int maxTime = sum(arr)
	int maxTime = 100;

	int ans = maxTime;

	while(minTime<maxTime){

		int mid = minTime + (maxTime - minTime)/2;

		if(isValid(arr,n,k,mid)){
			ans = mid;
			maxTime = mid - 1;
		}else{
			minTime = mid+1;
		}

	}

	return ans;

}

int isPossible(int arr[],int n,int k,int mid){

	int cow = 1;
	int alloted = arr[0];

	for(int i=1;i<n;i++){

		if((arr[i] - alloted) > mid){
			cow++;
			alloted = arr[i];

			if(cow==k){
				return true;
			}
		}
	}

	return false;
}

int aggressiveCows(int arr[],int n,int k){

	int minDist = arr[0];
	int maxDist = arr[n-1] - arr[0];

	int ans = maxDist;

	while(minDist <= maxDist){

		int mid = minDist + (maxDist-minDist)/2;

		if(isPossible(arr,n,k,mid)){

		}else{

		}

	}

	return ans;
}

void quickSort(int arr[],int low,int high){
	if(low>=high){
		return;
	}

	int left = low;
	int right = high;

	int mid = (low+high)/2;
	int pivot = arr[mid];

	while(left<=right){

		while(arr[left]< pivot){
			left++;
		}

		while(arr[right] > pivot){
			right--;
		}

		if(left<=right){
			swap(arr[left],arr[right]);
			left++;
			right--;
		}
	}

	quickSort(arr,low,right);
	quickSort(arr,left,high);

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

	// int arr[] = {5,6,7,1,2,3,4};
	// cout<<rotatedSearch(arr,0,6,2)<<endl;

	// int arr[] = {1,3,3,5,5,7,7};
	// cout<<uniqueNumber(arr,0,6)<<endl;

	// int arr[] = {10,20,30,40};
	// int k = 2;
	// cout<<painterProblem(arr,4,2)<<endl;

	int arr[] = {7,6,5,4,3,2,1};
	quickSort(arr,0,6);

	for(int i=0;i<7;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	// int x = 2147483647;
	// cout<<x<<endl;

	// x++;

	// cout<<x<<endl;

	// x = x+2;

	// cout<<x<<endl;


	return 0;
}