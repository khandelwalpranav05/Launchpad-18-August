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

void postorder(node*root){
	if(root==NULL){
		return;
	}

	postorder(root->left);
	postorder(root->right);

	cout<<root->data<<" ";
}

void inorder(node*root){
	if(root==NULL){
		return;
	}

	inorder(root->left);

	cout<<root->data<<" ";

	inorder(root->right);
}

int countNumberOfNodes(node*root){
	if(root==NULL){
		return 0;
	}

	int leftCount = countNumberOfNodes(root->left);
	int rightCount = countNumberOfNodes(root->right);

	int totalCount = leftCount + rightCount + 1;
	return totalCount;

	// return countNumberOfNodes(root->left) + countNumberOfNodes(root->right) + 1;
}

int sumOfNodes(node*root){
	if(root==NULL){
		return 0;
	}

	int leftSum = sumOfNodes(root->left);
	int rightSum = sumOfNodes(root->right);

	int totalSum = leftSum + rightSum + root->data;
	return totalSum;
}

int height(node*root){
	//Base Case
	if(root==NULL){
		return -1;
	}

	//Recursive Case
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int totalHeight = max(leftHeight,rightHeight) + 1;
	return totalHeight;
}

bool searchNode(node*root,int item){
	//Base Case
	if(root==NULL){
		return false;
	}

	// Recursive Case
	if(item==root->data){
		return true;
	}

	bool leftSearch = searchNode(root->left,item);
	bool rightSearch = searchNode(root->right,item);

	if(leftSearch or rightSearch){
		return true;
	}

	return false;
}

void printAllRootToLeaves(node*root,string path){
	if(root==NULL){
		return;
	}

	char data = root->data + '0';

	if(root->left==NULL and root->right==NULL){
		path = path + data;
		cout<<path<<endl;
		return;
	}

	printAllRootToLeaves(root->left,path+data);
	printAllRootToLeaves(root->right,path+data);
}

int diameter(node*root){
	if(root==NULL){
		return 0;
	}

	int leftDiameter = diameter(root->left);  
	int rightDiameter = diameter(root->right);

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int totalDia = leftHeight + rightHeight + 2;

	return max(totalDia,max(leftDiameter,rightDiameter));
}

class DiaHeightPair{
public:
	int diameter;
	int height;
};

DiaHeightPair diameterBetter(node*root){
	DiaHeightPair val;

	if(root==NULL){
		val.height = -1;
		val.diameter = 0;
		return val;
	}

	DiaHeightPair leftPair = diameterBetter(root->left);
	DiaHeightPair rightPair = diameterBetter(root->right);

	val.height = max(leftPair.height,rightPair.height) + 1;

	val.diameter = max(leftPair.height + rightPair.height + 2,max(leftPair.diameter,rightPair.diameter));

	return val;
}

bool isBalanced(node*root){
	if(root==NULL){
		return true;
	}

	bool leftBalanced = isBalanced(root->left);
	bool rightBalanced = isBalanced(root->right);

	if(!leftBalanced or !rightBalanced){
		return false;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int diff = abs(leftHeight - rightHeight);

	if(diff>1){
		return false;
	}else{
		return true;
	}
}

int replaceWithChildrenSum(node*root){
	//Base Case
	if(root==NULL){
		return 0;
	}

	if(root->left==NULL and root->right==NULL){
		return root->data;
	}

	//Recursive Case
	int leftSum = replaceWithChildrenSum(root->left);
	int rightSum = replaceWithChildrenSum(root->right);

	int temp = root->data;
	root->data = leftSum + rightSum;
	return temp + root->data;
}

void levelOrder(node*root){

	queue<node*> q;

	q.push(root);

	while(!q.empty()){

		node* temp = q.front();
		q.pop();

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

class HeightBalancedPair{
public:
	int height;
	bool balance;
};

HeightBalancedPair isBalancedOptimized(node*root){
	HeightBalancedPair val;

	if(root==NULL){
		val.balance = true;
		val.height = -1;
		return val;
	}

	HeightBalancedPair leftPair = isBalancedOptimized(root->left);
	HeightBalancedPair rightPair = isBalancedOptimized(root->right);

	if(!leftPair.balance or !rightPair.balance){
		val.balance = false;
	}

	int diff = abs(leftPair.height - rightPair.height);

	val.height = max(leftPair.height,rightPair.height) + 1;

	if(diff>1){
		val.balance = false;
	}else{
		val.balance = true;
	}

	return val;
}

void serialize(node* root){
	if(root==NULL){
		cout<<(-1)<<" ";
		return;
	}

	cout<<root->data<<" ";
	serialize(root->left);
	serialize(root->right);
}

node* lca(node*root,int data1,int data2){
	if(root==NULL){
		return NULL;
	}

	if(root->data==data1 or root->data==data2){
		return root;
	}

	node* leftLCA = lca(root->left,data1,data2);
	node* rightLCA = lca(root->right,data1,data2);

	if(leftLCA==NULL and rightLCA==NULL){
		return NULL;
	}

	if(leftLCA!=NULL and rightLCA!=NULL){
		return root;
	}

	return leftLCA!=NULL ? leftLCA:rightLCA;

}

int main(){

	node* root = NULL;

	root = buildTree(root);
	// preorder(root);
	// cout<<endl;
	// postorder(root);
	// cout<<endl;
	// inorder(root);
	// cout<<endl;

	// cout<<countNumberOfNodes(root)<<endl;
	// cout<<sumOfNodes(root)<<endl;

	// cout<<height(root)<<endl;
	// cout<<searchNode(root,7)<<endl;

	// printAllRootToLeaves(root,"");

	// cout<<diameter(root)<<endl;

	// cout<<isBalanced(root)<<endl;

	// levelOrder(root);

	// HeightBalancedPair x = isBalancedOptimized(root);
	// cout<<x.balance<<endl;

	// serialize(root);
	// cout<<endl;

	// node* common = lca(root,2,3);
	// cout<<common->data<<endl;

	return 0;
}

// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1