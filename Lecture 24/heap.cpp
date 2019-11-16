#include <iostream>
#include <vector>

using namespace std;

class Heap{

	bool minHeap;
	vector<int> v;

	void heapify(int i){

		int left = 2*i;
		int right = 2*i + 1;

		int minIndex = i;

		if(left<v.size() and compare(v[left],v[minIndex])){
			minIndex = left;
		}

		if(right<v.size() and compare(v[right],v[minIndex])){
			minIndex = right;
		}

		if(minIndex!=i){
			swap(v[minIndex],v[i]);
			heapify(minIndex);
		}
	}

	bool compare(int a,int b){
		if(minHeap){
			return a<b;
		}else{
			return a>b;
		}
	}

public:
	Heap(bool type = true){
		minHeap = type;
		v.push_back(-1);
	}

	void push(int data){

		v.push_back(data);
		int index = v.size() - 1;
		int parent = index/2;

		while(index>1 and compare(v[index],v[parent])){
			swap(v[index],v[parent]);
			index = parent;
			parent= index/2;
		}
	}

	int top(){
		return v[1];
	}

	bool empty(){
		return v.size()==1;
	}

	void pop(){
		int last = v.size() - 1;
		swap(v[1],v[last]);
		v.pop_back();

		heapify(1);
	}
};

int main(){

	Heap h(false);

	h.push(15);
	h.push(5);
	h.push(2);
	h.push(156);
	h.push(4);
	h.push(6);
	h.push(160);

	// cout<<h.top()<<endl;

	while(!h.empty()){
		cout<<h.top()<<endl;
		h.pop();
	}

	return 0;
}