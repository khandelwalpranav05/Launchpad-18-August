#include <iostream>
#include <math.h>

using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int data){
		this->data = data;
		this->left =  NULL;
		this->right = NULL;
	}

	node(){
		this->left =  NULL;
		this->right = NULL;
	}
};

void insert(node* root,int data){

	for(int i=31;i>=0;i--){

		int bit = (data>>i)&1;

		if(bit){

			if(!root->right){
				node* child = new node();
				root->right = child;
			}
			root = root->right;
		}else{

			if(!root->left){
				node* child = new node();
				root->left = child;
			}
			root = root->left;

		}
	}
}

int maxXor(int arr[],int n,node* head){

	int maxVal = 0;

	for(int i=0;i<n;i++){
		int val = arr[i];

		int currXor = 0;

		node* root = head;

		for(int j=31;j>=0;j--){

			int bit = (val>>j)&1;
			
			if(bit){

				if(root->left){
					currXor += pow(2,j);
					root = root->left;
				}else{
					root = root->right;
				}

			}else{

				if(root->right){
					currXor+=pow(2,j);
					root = root->right;
				}else{
					root = root->left;
				}

			}
		}

		maxVal = max(maxVal,currXor);
	}

	return maxVal;
}

int main(){

	int arr[] = {1,2,3,4};

	node* root = new node();

	for(int i=0;i<4;i++){
		insert(root,arr[i]);
	}

	cout<<maxXor(arr,4,root)<<endl;

	return 0;
}