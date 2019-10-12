#include <iostream>

using namespace std;

class Queue{

	int front;
	int rear;
	int maxSize;
	int currSize;
	int *arr;

public:	
	Queue(int capacity = 10){
		maxSize = capacity;
		arr = new int[capacity];
		front = 0;
		rear = maxSize-1;
		currSize = 0;
	}

	int size(){
		return currSize;
	}

	bool isFull(){
		return currSize==maxSize;
	}

	bool empty(){
		return currSize==0;
	}

	int getFront(){
		if(empty()){
			cout<<"Queue is empty"<<endl;
			return -1;
		}else{
			return arr[front];
		}
	}

	void push(int data){
		if(isFull()){
			cout<<"Queue is full"<<endl;
			return;
		}

		rear = (rear+1)%maxSize;
		arr[rear]= data;
		currSize++;
	}

	void pop(){
		if(empty()){
			cout<<"Queue is empty"<<endl;
			return;
		}

		front = (front+1)%maxSize;
		currSize--;
	}

};

int main(){

	Queue q(5);

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);

	cout<<"**************"<<endl;

	cout<<q.getFront()<<endl;
	q.pop();

	cout<<"**************"<<endl;

	q.push(789);

	q.pop();
	q.pop();
	q.pop();
	q.pop();

	cout<<q.getFront()<<endl;
	q.pop();
	cout<<q.getFront()<<endl;

	return 0;
}