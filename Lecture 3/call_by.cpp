// #include <iostream>

// using namespace std;

// void increment(int* aptr){
// 	*aptr = *aptr + 2;
// 	cout<<"Inside Function "<<*aptr<<endl;
// }

// int main(){

// 	int a = 10;
// 	increment(&a);

// 	cout<<"Inside Main "<<a<<endl;

// 	return 0;
// }

#include <iostream>

using namespace std;

// void increment(int* aptr){
// 	*aptr = *aptr + 2;
// 	cout<<"Inside Function "<<*aptr<<endl;
// }

void display(int *arr){
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void change(int arr[]){
	arr[2] = 789;
}

int main(){

	int a = 10;
	int arr[] = {1,2,3,4,5};

	int* check = &a;

	display(&arr[0]);
	change(arr);
	display(&arr[0]);

	// cout<<arr<<endl;
	// cout<<check<<endl;
	// cout<<(&arr[0])<<endl;

	// increment(&a);

	// cout<<"Inside Main "<<a<<endl;

	return 0;
}