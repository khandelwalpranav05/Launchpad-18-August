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


int main(){

	node* root = construct();
	preorder(root);
	cout<<endl;

	return 0;
}