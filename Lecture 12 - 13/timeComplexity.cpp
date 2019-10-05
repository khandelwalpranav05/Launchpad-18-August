#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void bubble(int arr[1000000], int n){
	int counter = 1;

	while(counter<n){
		for(int i=0;i<n - counter;i++){
			if(arr[i]>arr[i+1]){
				swap(arr,i,i+1);
			}
		}
		counter++;
	}
}
int main(int argc, char const *argv[])
{	
	int arr[1000000];
	for (int i = 0; i < 1000000 ; ++i)
	{
		arr[i] = 1000000-i;
	}
	clock_t start = clock();
	bubble(arr,10000);
	clock_t end_1 = clock();
	sort(arr,arr+10000);
	clock_t end_2 = clock();
	
	cout<<(end_1 - start)<<endl;
	cout<<(end_2 - end_1)<<endl;

// int n;
// cin>>n;
// //O(n)
// for(int i =0; i<n; i++){
// 	cout<<i;
// }

// O(logn)
// for(int i =1; i<n; i=i*2){
// 	cout<<i;
// }

// for(int i =0; i<n; i=i+2){

// 	int a = i+6;
// 	int b = i+9;
// 	cout<<i;
// }

// //O(n^2)

// for(int i =0; i<n; i++){

// 	for (int j = 0; j < n; j++)
// 	{
// 		/* code */
// 	}
// }
// //O(n^3)
// for(int i =0; i<n; i++){

// 	for (int j = 0; j < n; j++)
// 	{
// 		for (int k = 0; k < n; k++)
// 			{
// 				/* code */
// 			}
// 	}
// }

// //O(n logn)

// for(int i =0; i<n; i++){

// 	for (int j = 1; j < n; j=j*2)
// 	{
// 		/* code */
// 	}
// }

	return 0;
}



// for(int i =0; i<n; i++){
// 	cout<<i;
// }








// for(int i =0; i<n; i=i+2){

// 	int a = i+6;
// 	int b = i+9;
// 	cout<<i;
// }








// for(int i =0; i<n; i++){

// 	for (int j = 0; j < n; j++)
// 	{
// 		/* code */
// 	}
// }


// for(int i =0; i<n; i++){

// 	for (int j = 0; j < n; j++)
// 	{
// 		for (int k = 0; k < n; k++)
// 			{
// 				/* code */
// 			}
// 	}
// }

// n and k are large values

// for(int i=0;i<k;i++){

// 	for(int j=0;j<n;j+=k){
// 		//Code
// 	}

// }