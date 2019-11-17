#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

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

	void bfs(T src){
		queue<T> q;
		unordered_map<T,bool> visited;

		q.push(src);
		visited[src] = true;

		while(!q.empty()){

			T node = q.front();
			q.pop();

			cout<<node<<" ";

			for(T neighbor:AdjList[node]){
				if(!visited[neighbor]){
					q.push(neighbor);
					visited[neighbor] = true;
				}
			}

		}

		cout<<endl;
	}

	void dfs_Helper(T node,unordered_map<T,bool> &visited){

		cout<<node<<" ";
		visited[node] = true;

		for(T neighbor:AdjList[node]){
			if(!visited[neighbor]){
				dfs_Helper(neighbor,visited);
			}
		}

	}

	void dfs(T src){

		unordered_map<T,bool> visited;
		// visited[src] = true;

		dfs_Helper(src,visited);
		cout<<endl;
	}

};

int main(){

	Graph<int> g;

	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(3,2);
	// g.addEdge(3,2);

	g.display();

	g.bfs(1);
	g.dfs(1);

	// Graph<string> g;

	// g.addEdge("Coding Blocks","C++");
	// g.addEdge("C++","Java");
	// g.addEdge("Java","Python");
	// g.addEdge("Python","Coding Blocks");

	// g.display();

	return 0;
}