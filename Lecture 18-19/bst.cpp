#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int data){
		this->data = data;
		this->left = NULL;
		this->right= NULL;
	}
};

node* insertInBST(node*root,int data){
	if(root==NULL){
		node* n = new node(data);
		root = n;
		return root;
		// return new node(data);
	}

	if(data>root->data){
		root->right = insertInBST(root->right,data);
	}else{
		root->left = insertInBST(root->left,data);
	}

	return root;
}

node* construct(){
	node* root = NULL;

	int data;
	cin>>data;

	while(data!=-1){
		root = insertInBST(root,data);
		cin>>data;
	}

	return root;
}

void preorder(node*root){
	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";

	preorder(root->left);
	preorder(root->right);
}

void inorder(node*root){
	if(root==NULL){
		return;
	}

	inorder(root->left);

	cout<<root->data<<" ";

	inorder(root->right);
}

bool search(node*root,int item){
	if(root==NULL){
		return false;
	}

	if(root->data==item){
		return true;
	}

	if(root->data > item){
		return search(root->left,item);
	}else{
		return search(root->right,item);
	}
}

node* buildTreeFromArray(int arr[],int s,int e){
	if(s>e){
		return NULL;
	}

	int mid = (s+e)/2;
	node* root = new node(arr[mid]);

	root->left = buildTreeFromArray(arr,s,mid-1);
	root->right = buildTreeFromArray(arr,mid+1,e);

	return root;
}

bool isBST(node*root,int leftRange = INT_MIN,int rightRange = INT_MAX){
	if(root==NULL){
		return true;
	}

	bool leftCheck = isBST(root->left,leftRange,root->data);
	bool rightCheck = isBST(root->right,root->data,rightRange);

	if(leftCheck and rightCheck and root->data < rightRange and root->data > leftRange){
		return true;
	}else{
		return false;
	}

}

int main(){

	// node* root = construct();
	// preorder(root);
	// cout<<endl;

	// cout<<search(root,3)<<endl;
	// cout<<search(root,0)<<endl;

	int arr[] = {1,2,3,4,5,6,7,8,0};
	node* root = buildTreeFromArray(arr,0,8);
	// inorder(root);
	// cout<<endl;

	// cout<<isBST(root)<<endl;

	return 0;
}