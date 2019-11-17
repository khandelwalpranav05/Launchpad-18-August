#include <iostream>
#include <unordered_map>

using namespace std;

class node{
public:
	char data;
	bool isTerminal;
	unordered_map<char,node*> h;

	node(char data){
		this->data = data;
	}
};

class Trie{
	node* root;

public:
	Trie(){
		root = new node('\0');
	}

	void addWord(string word){

		node* temp = root;

		for(int i=0;i<word.length();i++){
			char ch = word[i];

			if(temp->h.count(ch)){
				temp = temp->h[ch];
			}else{
				node* child = new node(ch);
				temp->h[ch] = child;
				temp = temp->h[ch];
			}
		}

		temp->isTerminal = true;
	}

	bool search(string word){
		node* temp = root;

		for(int i=0;i<word.length();i++){
			char ch = word[i];

			if(temp->h.count(ch)){
				temp = temp->h[ch];
			}else{
				return false;
			}
		}

		return temp->isTerminal;
	}
};
int main(){
	Trie t;
	string arr[] = {"apple","ape","application","note","news"};
	for(int i=0;i<5;i++){
		t.addWord(arr[i]);
	}
	cout<<t.search("application")<<endl;
	cout<<t.search("app")<<endl;

	return 0;
}