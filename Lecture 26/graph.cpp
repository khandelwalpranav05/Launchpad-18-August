#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

template <typename T>
class Graph{

	unordered_map<T,list<T> > AdjList;
public:
	Graph(){}

	void addEdge(T u,T v,bool birdir = true){

		AdjList[u].push_back(v);

		if(birdir){
			AdjList[v].push_back(u);
		}
	}

	void display(){
		for(auto node:AdjList){
			cout<<node.first<<" -> ";

			for(T vertex:node.second){
				cout<<vertex<<", ";
			}
			cout<<endl;
		}
	}

};

int main(){

	// Graph g;

	// g.addEdge(1,2);
	// g.addEdge(1,3);
	// g.addEdge(3,2);
	// g.addEdge(3,2);

	// g.display();

	// Graph<string> g;

	// g.addEdge("Coding Blocks","C++");
	// g.addEdge("C++","Java");
	// g.addEdge("Java","Python");
	// g.addEdge("Python","Coding Blocks");

	// g.display();

	return 0;
}