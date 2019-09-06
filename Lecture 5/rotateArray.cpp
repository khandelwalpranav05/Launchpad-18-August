 //rotate arr[] of size n by k elements.
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{	
	int n,k;
	cin>>n>>k;
	char arr[100];
	cin>>arr;
	for (int i = 0; i < k; ++i)
	{
		int temp = arr[n-1];
		for (int i = n-2; i >= 0 ; i--)
		{
			arr[i+1]=arr[i];
		}

		arr[0]=temp;
	}

	cout<<arr<<endl;



	return 0;
}














