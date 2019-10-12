#include <iostream>

using namespace std;

class Stack{

	int top;
	int *arr;
	int capacity;

public:
	Stack(int capacity = 10){
		this->capacity = capacity;
		arr = new int[capacity];
		top = -1;
	}

	int size(){
		return top+1;
	}

	bool empty(){
		return size()==0;
	}

	int last(){
		return arr[top]; 
	}

	void push(int data){
		if(capacity==size()){
			cout<<"Stack is full"<<endl;
			return;
		}

		top++;
		arr[top] = data;
	}

	void pop(){
		if(size()==0){
			cout<<"Stack is empty"<<endl;
			return;
		}

		top--;
	}

};

int main(){

	Stack s;
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);

	cout<<s.last()<<endl;
	s.pop();

	cout<<s.last()<<endl;

	return 0;
}