#include <iostream>

using namespace std;

template <typename T>	
class node{
public:
	string key;
	T value;
	node<T>* next;

	node(string key,T value){
		this->key = key;
		this->value = value;
		next = NULL;
	}
};

template <typename T>
class HashTable{

	int maxSize;
	int currSize;
	node<T>** bucket;
public:
	HashTable(int default_size = 7){
		maxSize = default_size;
		currSize = 0;
		bucket = new node<T>*[maxSize];
	}

	int hashFunction(string key){
		int len = key.length();
		int mulFactor = 1;

		int idx = 0;

		for(int i=0;i<len;i++){
			idx += key[i]*mulFactor;
			mulFactor = mulFactor*37;
		}

		idx = idx%maxSize;
		return idx;
	}

	void insert(string key,T val){
		int idx = hashFunction(key);

		node<T>* n = new node<T>(key,val);

		n->next = bucket[idx];
		bucket[idx] = n;
		currSize++;
	}

	void display(){
		for(int i=0;i<maxSize;i++){

			node<T>* head = bucket[i];

			while(head!=NULL){
				cout<<head->key<<" "<<head->value<<", ";
				head=head->next;
			}

			cout<<endl;
		}
	}

	T* search(string key){

		int idx = hashFunction(key);

		node<T>* temp = bucket[idx];

		while(temp!=NULL){
			if(key==temp->key){
				return &(temp->value);
			}
			temp = temp->next;
		}

	return NULL;

	}

	void erase(string k){

		int idx = hashFunction(k);

		node<T>* temp = bucket[idx];

		cout<<(*temp)<<endl;

		if(temp==NULL){
			return;
		}

		cout<<"Check1"<<endl;

		if(temp->key == k){
			cout<<"If Check1"<<endl;
			bucket[idx] = temp->next;
			temp->next = NULL;
			delete temp;
			return;
		}

		cout<<"Check2"<<endl;

		if(temp->next==NULL){
			return;
		}

		cout<<"Check3"<<endl;

		while(temp->next->key!=k){
			temp=temp->next;

			if(temp->next==NULL){
				return;
			}
		}

		cout<<"Check4"<<endl;

		node<T>* toBeDeleted = temp->next;
		temp->next = temp->next->next;

		toBeDeleted->next = NULL;
		delete toBeDeleted;
		return;
	}	
};

int main(){

	HashTable<int> h;

	h.insert("India",140);
	h.insert("US",23);
	h.insert("Norwaskfhew",2);
	h.insert("Pakistan",112);
	h.insert("New Country",0);

	h.display();

	int* temp = h.search("India");
	cout<<(*temp)<<endl;

	// h.erase("Norwaskfhew");
	h.erase("dkjbfv");

	h.display();


	// int arr[] = {1,2,3,4,5};

	// cout<<arr[-1]<<endl;

	return 0;
}