#include <iostream>

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

node* buildTree(node* root){
	int data;
	cin>>data;

	if(data ==-1){
		return NULL;
	}

	if(root==NULL){
		node* n = new node(data);
		root=n;
	}

	root->left = buildTree(root->left);
	root->right = buildTree(root->right);

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

	node* root = NULL;

	root = buildTree(root);
	preorder(root);
	cout<<endl;

	return 0;
}