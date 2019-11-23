#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <climits>

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

		int component = 0;

		for(auto node:AdjList){
			if(!visited[node.first]){
				dfs_Helper(node.first,visited);
				cout<<endl;
				component++;
			}
		}
		
		cout<<"Number of component "<<component<<endl;
	}

	void dfsTopologicalSortHelper(T node,unordered_map<T,bool> &visited,list<T> &order){

		visited[node] = true;

		for(T neighbor:AdjList[node]){
			if(!visited[neighbor]){
				dfsTopologicalSortHelper(neighbor,visited,order);
			}
		}

		order.push_front(node);
	}

	void dfsTopologicalSort(T src){
		unordered_map<T,bool> visited;
		list<T> order;

		dfsTopologicalSortHelper(src,visited,order);

		for(auto node:AdjList){
			if(!visited[node.first]){
				dfsTopologicalSortHelper(node.first,visited,order);
			}
		}

		for(T node:order){
			cout<<node<<" ";
		}
		cout<<endl;
	}

	void journeyToMoonHelper(T node,unordered_map<T,bool> &visited,int &countrySize){
		countrySize++;
		visited[node] = true;

		for(T neighbor:AdjList[node]){
			if(!visited[neighbor]){
				journeyToMoonHelper(neighbor,visited,countrySize);
			}
		}
	}

	int journeyToMoon(){

		unordered_map<T,bool> visited;

		int n = AdjList.size();

		int total = n*(n-1)/2;

		for(auto node:AdjList){
			if(!visited[node.first]){
				int countrySize = 0;
				journeyToMoonHelper(node.first,visited,countrySize);
				total -= countrySize*(countrySize-1)/2;
			}
		}

		return total;
	}

	void bfsTopologicalSort(){

		queue<T> q;
		unordered_map<T,int> indegree;

		for(auto node:AdjList){
			indegree[node.first] = 0;
		}

		for(auto node:AdjList){
			for(T vertex:node.second){
				indegree[vertex]++;
			}
		}

		for(auto node:AdjList){
			if(indegree[node.first]==0){
				q.push(node.first);
			}
		}

		while(!q.empty()){

			T node = q.front();
			q.pop();

			cout<<node<<" ";

			for(T neighbor:AdjList[node]){
				indegree[neighbor]--;

				if(indegree[neighbor]==0){
					q.push(neighbor);
				}
			}
		}

		cout<<endl;
	}

	bool isCyclic(T src){

		queue<T> q;
		unordered_map<T,bool> visited;
		unordered_map<T,T> parent;


		parent[src] = src;
		q.push(src);
		visited[src] = true;

		while(!q.empty()){

			T node = q.front();
			q.pop();

			for(T neighbor:AdjList[node]){

				if(visited[neighbor] and parent[node]!=neighbor){
					return true;

				}else if(!visited[neighbor]){
					q.push(neighbor);
					visited[neighbor] = true;
					parent[neighbor] = node;
				}

			}
		}

		return false;
	}

	void bfsShortestPath(T src){

		queue<T> q;
		unordered_map<T,int> dist;

		for(auto node:AdjList){
			dist[node.first] = INT_MAX;
		}

		dist[src] = 0;
		q.push(src);

		while(!q.empty()){

			T node = q.front();
			q.pop();

			for(T neighbor:AdjList[node]){

				if(dist[neighbor]==INT_MAX){
					dist[neighbor] = dist[node] + 1;
					q.push(neighbor);
				}

			}
		}

		for(auto node:dist){
			cout<<"Node "<<node.first<<" is at a distance of "<<node.second<<endl;
		}
	}

	int snakesAndLadder(T src,T dest){

		queue<T> q;
		unordered_map<T,int> dist;

		for(auto node:AdjList){
			dist[node.first] = INT_MAX;
		}

		dist[src] = 0;
		q.push(src);

		while(!q.empty()){

			T node = q.front();
			q.pop();

			for(T neighbor:AdjList[node]){

				if(dist[neighbor]==INT_MAX){
					dist[neighbor] = dist[node] + 1;
					q.push(neighbor);
				}

			}
		}

		return dist[dest];
	}

};

int main(){

	// Graph<int> g;

	// g.addEdge(1,2);
	// g.addEdge(1,3);
	// g.addEdge(3,2);
	// // g.addEdge(3,2);

	// g.addEdge(4,5);
	// g.addEdge(6,5);
	// g.addEdge(7,5);


	// g.display();

	// // g.bfs(1);
	// g.dfs(1);

	// Graph<string> g;

	// g.addEdge("Coding Blocks","C++");
	// g.addEdge("C++","Java");
	// g.addEdge("Java","Python");
	// g.addEdge("Python","Coding Blocks");

	// g.display();

	// Graph<string> g;

	// g.addEdge("Maths","Programming",false);
	// g.addEdge("English","Programming",false);
	// g.addEdge("Programming","Python",false);
	// g.addEdge("Programming","Java",false);
	// g.addEdge("Java","Web",false);
	// g.addEdge("Python","Web",false);

	// // g.dfsTopologicalSort("Maths");
	// g.bfsTopologicalSort();

	// Graph<int> g;

	// g.addEdge(1,2);
	// g.addEdge(1,3);
	// g.addEdge(1,4);
	// g.addEdge(5,6);
	// g.addEdge(6,7);

	// cout<<g.journeyToMoon()<<endl;

	// Graph<int> g;

	// g.addEdge(1,2);
	// g.addEdge(1,3);
	// // g.addEdge(2,3);
	// g.addEdge(3,4);
	// g.addEdge(4,5);

	// cout<<g.isCyclic(1)<<endl;

	// Graph<int> g;

	// g.addEdge(1,2);
	// g.addEdge(1,3);
	// g.addEdge(2,4);
	// g.addEdge(3,5);
	// g.addEdge(3,4);
	// g.addEdge(5,6);
	// g.addEdge(4,5);

	// g.bfsShortestPath(1);

	Graph<int> g;

	int board[50] = {0};

	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;

	for(int i=0;i<=36;i++){
		for(int dice = 1;dice<=6;dice++){

			int u = i;
			int v = u + dice + board[u+dice];
			g.addEdge(u,v,false);
		}
	}

	cout<<g.snakesAndLadder(0,36)<<endl;

	return 0;
}