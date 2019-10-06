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

int main(){

	node* head = NULL;
	insertAtHead(head,4);
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);

	display(head);
	return 0;
}