#include <iostream>

using namespace std;

int uniqueNumberTriplet(int arr[],int n){

	int bitAdder[32] = {0}; 

	for(int i=0;i<n;i++){

		int no = arr[i];

		for(int j=31;j>=0;j--){

			int temp = (no&1);
			bitAdder[j]+=temp;
			no = no>>1;

			if(no==0){
				break;
			}
		}
	}

	int multiply = 1;
	int number = 0;

	for(int i=31;i>=0;i--){
		bitAdder[i] = bitAdder[i]%3;
		// number += (1<<(31-i))*bitAdder[i];
		number+= multiply*bitAdder[i];
		multiply = multiply<<1;
	}

	return number;
}

int uniqueNumberPairs(int arr[],int n){

	int Xor = arr[0]; 

	for(int i=1;i<n;i++){
		Xor=Xor^arr[i];
	}

	return Xor;
}

void twoUniqueNumbers(int arr[],int n){

	int Xor = arr[0]; 

	for(int i=1;i<n;i++){
		Xor=Xor^arr[i];
	}

	int no = Xor;
	int position = 0;

	while(true){
		if(no&1){
			break;
		}else{
			no = no>>1;
			position++;
		}
	}

	int first_unique = 0;

	for(int i=0;i<n;i++){

		int element = arr[i];

		int shift = element>>position;

		if(shift&1){
			first_unique = first_unique^arr[i];
		}
	}

	int second_unique = Xor^first_unique;

	cout<<"First Number "<<first_unique<<endl;
	cout<<"Second Number "<<second_unique<<endl;

}

int main(){

	// int arr[] = {1,3,4,3,7,7,4,1,1,7,3,4,5};
	// cout<<uniqueNumberTriplet(arr,13)<endl;

	int arr[] = {1,2,3,4,5,3,2,1};
	twoUniqueNumbers(arr,8);

	return 0;
}