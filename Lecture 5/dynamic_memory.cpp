#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a = 5;
	int* ad = new int(10);

	cout<<a<<endl;
	cout<<ad<<"->"<<*(ad)<<endl;


	int i;
	int* j = new int;

	cout<<i<<endl;
	cout<<j<<endl;

	int arr[5];
	int n;
	cin>>n;
	int* arr1 = new int[n];
	for (int l = 0; l < n; ++l)
	{
		arr1[l] = l;
	}
	for (int k = 0; k < n; k++)
	{
		cout<<arr1[k]<<" ";
	}

	delete ad;

	delete[] arr1; 




	return 0;
}