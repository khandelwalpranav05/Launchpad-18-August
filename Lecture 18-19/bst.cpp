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

int numberOfBST(int n){
	if(n==0){
		return 1;
	}

	int ans = 0;

	for(int i=1;i<=n;i++){
		ans += numberOfBST(i-1)*numberOfBST(n-i);
	}

	return ans;
}

void levelOrderNewLine(node*root){

	queue<node*> q;

	q.push(root);
	q.push(NULL);

	while(!q.empty()){

		node* temp = q.front();
		q.pop();

		if(temp==NULL){
			cout<<endl;

			if(!q.empty()){
				q.push(NULL);
			}

			continue;
		}

		cout<<temp->data<<" ";

		if(temp->left!=NULL){
			q.push(temp->left);
		}

		if(temp->right!=NULL){
			q.push(temp->right);
		}

	}

	cout<<endl;
}

int firstVisitLevel = 0;

void leftView(node* root,int level){
	if(root==NULL){
		return;
	}

	if(firstVisitLevel==level){
		cout<<root->data<<" ";
		firstVisitLevel++;
	}

	leftView(root->left,level+1);
	leftView(root->right,level+1);
}

void leftBoundary(node*root){
	if(root==NULL){
		return;
	}

	if(root->left==NULL and root->right==NULL){
		return;
	}

	cout<<root->data<<" ";

	if(root->left!=NULL){
		leftBoundary(root->left);
	}else{
		leftBoundary(root->right);
	}
}

void printLeaf(node*root){
	if(root==NULL){
		return;
	}

	if(root->left==NULL and root->right==NULL){
		cout<<root->data<<" ";
		return;
	}

	printLeaf(root->left);
	printLeaf(root->right);
}

int maxPath = INT_MIN;

int maxPathNodes(node*root){
	if(root==NULL){
		return 0;
	}

	int leftMax = max(0,maxPathNodes(root->left));
	int rightMax = max(0,maxPathNodes(root->right));

	maxPath = max(maxPath,leftMax + rightMax + root->data);

	return max(leftMax,rightMax) + root->data;
}

class LinkedListPair{
public:
	node*head;
	node*tail;
};

LinkedListPair treeToLinkedList(node*root){
	LinkedListPair val;

	if(root==NULL){
		val.head = NULL;
		val.tail = NULL;
		return val;
	}

	if(root->left==NULL and root->right==NULL){
		val.head = root;
		val.tail = root;
		return val;
	}

	if(root->left!=NULL and root->right==NULL){
		LinkedListPair leftPair = treeToLinkedList(root->left);

		leftPair.tail->right = root;
		val.tail = root;
		val.head = leftPair.head;
		return val;
	}

	if(root->left==NULL and root->right!=NULL){

		LinkedListPair rightPair = treeToLinkedList(root->right);

		root->right = rightPair.head;
		val.head = root;
		val.tail = rightPair.tail;
		return val;
	}	

	if(root->left!=NULL and root->right!=NULL){
		LinkedListPair leftPair = treeToLinkedList(root->left);
		LinkedListPair rightPair = treeToLinkedList(root->right);

		leftPair.tail->right = root;
		root->right = rightPair.head;

		val.head = leftPair.head;
		val.tail = rightPair.tail;
		return val;
	}
}

int main(){

	node* root = construct();
	// preorder(root);
	// cout<<endl;

	// cout<<search(root,3)<<endl;
	// cout<<search(root,0)<<endl;

	// int arr[] = {1,2,3,4,5,6,7,8,0};
	// node* root = buildTreeFromArray(arr,0,8);
	// inorder(root);
	// cout<<endl;

	// cout<<isBST(root)<<endl;

	// cout<<numberOfBST(4)<<endl;

	// levelOrderNewLine(root);

	// leftView(root,0);
	// cout<<endl;

	// leftBoundary(root);
	// cout<<endl;

	// printLeaf(root);
	// cout<<endl;

	LinkedListPair temp = treeToLinkedList(root);

	node* head = temp.head;

	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->right;
	}
	cout<<endl;

	return 0;
}