#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr1[2][3];

	int row,col;
	cin>>row>>col;
	int** arr = new int*[row];

	for (int i = 0; i < row; ++i)
	{
		arr[i] = new int[col];
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			arr[i][j] = i+j;
		}
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"-------------------------"<<endl;

// wave print
	for (int i = 0; i < row; ++i)
	{	
		if(i%2==0){
			for (int j = 0; j < col; ++j)
			{
				cout<<arr[i][j]<<" ";
			}
		}
		else{
			for (int j = col-1; j >= 0; j--)
			{
				cout<<arr[i][j]<<" ";
			}
		}
		cout<<endl;
	}



	for (int i = 0; i < row; ++i)
	{
		delete[] arr[i];
	}

	delete[] arr;

	return 0;
}