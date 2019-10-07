#include <iostream>

using namespace std;

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

void insertAtHead(node*&head,int data){

	node* n = new node(data);
	n->next = head;
	head = n;
}

void display(node*&head){

	node* temp = head;

	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<endl;
}

void insertAtTail(node*&head,int data){
	if(head==NULL){
		insertAtHead(head,data);
		return;
	}

	node* tail = head;

	while(tail->next!=NULL){
		tail = tail->next;
	}

	node* n = new node(data);

	tail->next = n;
}

int length(node*head){

	int len = 0;
	node* temp = head;

	while(temp!=NULL){
		temp = temp->next;
		len++;
	}

	return len;
}

bool searchIterative(node*head,int item){
	node* temp = head;

	while(temp!=NULL){
		if(temp->data == item){
			return true;
		}

		temp = temp->next;
	}

	return false;
}

void insertAtIndex(node*&head,int data,int idx){
	if(idx==0 || head==NULL){
		insertAtHead(head,data);
		return;
	}

	if(idx>length(head)){
		insertAtTail(head,data);
	}

	node* temp = head;

	int counter = 0;

	while(counter<idx-1){
		temp = temp->next;
		counter++;
	}

	node* n = new node(data);

	n->next = temp->next;
	temp->next = n;
}

// void deleteAtTail(node*head){
// 	node* temp = head;

// 	int counter = 1;
// 	int len = length(head);
// 	cout<<len<<endl;
// 	while(counter<len-1){
// 		temp = temp->next;
// 		counter++;
// 	}

// 	node* p = temp->next;
// 	temp->next = NULL;
// 	delete p;
// }

void deleteAtHead(node*&head){
	if(head==NULL){
		return;
	}

	node* temp = head;
	head = head->next;
	temp->next = NULL;

	delete temp;
}

void deleteAtTail(node*&head){
	if(head==NULL){
		return;
	}

	if(length(head)==1){
		deleteAtHead(head);
	}

	node* temp = head;

	while(temp->next->next!=NULL){
		temp = temp->next;
	}

	node* p = temp->next;
	temp->next = NULL;
	delete p;
}

void deleteAtIndex(node*&head,int idx){
	if(idx==0){
		deleteAtHead(head);
		return;
	}

	if(idx>=length(head)){
		deleteAtTail(head);
		return;
	}

	int counter = 0;

	node*temp = head;

	while(counter<idx-1){
		temp = temp->next;
		counter++;
	}

	node* p = temp->next;
	temp->next = temp->next->next;

	p->next = NULL;
	delete p;
}

bool searchRecursive(node* head,int item){
	if(head==NULL){
		return false;
	}

	if(item==head->data){
		return true;
	}

	return searchRecursive(head->next,item);
}

node* midPoint(node* head){

	node* fast = head;
	node* slow = head;

	while(fast->next!=NULL and fast->next->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

node* reverseRecursive(node*&head){
	if(head->next==NULL or head==NULL){
		return head;
	}

	node* newHead = reverseRecursive(head->next);
	node* currentHead = head;
	currentHead->next->next = currentHead;
	currentHead->next = NULL;
	return newHead;
}

void reverseIterative(node*&head){

	node* prev = NULL;
	node* curr = head;

	while(curr!=NULL){

		node* n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
	}

	head = prev;
}

node* merge(node* a,node* b){
	if(a==NULL){
		return b;
	}

	if(b==NULL){
		return a;
	}

	node* c;

	if(a->data < b->data){
		c = a;
		c->next = merge(a->next,b);
	}else{
		c = b;
		c->next = merge(a,b->next);
	}

	return c;
}

int main(){

	// node* head = NULL;
	// insertAtTail(head,0);
	// insertAtHead(head,4);
	// insertAtHead(head,3);
	// insertAtHead(head,2);
	// insertAtHead(head,1);

	// insertAtIndex(head,789,3);

	// display(head);
	// head = reverseRecursive(head);
	// display(head);
	// reverseIterative(head);
	// display(head);
	// deleteAtTail(head);

	// display(head);

	// deleteAtIndex(head,0);

	// display(head);

	// cout<<searchRecursive(head,4)<<endl;
	// cout<<searchIterative(head,4)<<endl;

	// node* mid = midPoint(head);
	// cout<<mid->data<<endl;

	node* head1 = NULL;
	insertAtTail(head1,1);
	insertAtTail(head1,3);
	insertAtTail(head1,5);

	node* head2 = NULL;
	insertAtTail(head2,2);
	insertAtTail(head2,4);
	insertAtTail(head2,6);
	insertAtTail(head2,8);
	insertAtTail(head2,9);

	node* merged = merge(head1,head2);

	display(merged);

	return 0;
}