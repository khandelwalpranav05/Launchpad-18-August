#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <climits>
#include <set>

using namespace std;

template <typename T>
class Graph{

	unordered_map<T,list<pair<T,int> > > adjList;

public:
	Graph(){}

	void addEdge(T u,T v,int weight,bool bidir = true){
		adjList[u].push_back(make_pair(v,weight));

		if(bidir){
			adjList[v].push_back(make_pair(u,weight));
		}
	}

	void display(){
		for(auto node:adjList){
			cout<<node.first<<" -> ";

			for(auto vertex:node.second){
				cout<<"( "<<vertex.first<<", "<<vertex.second<<" )";
			}
			cout<<endl;
		}
	}

	void dijkstra(T src){

		set<pair<int,T> > s;

		unordered_map<T,int> dist;

		for(auto node:adjList){
			dist[node.first] = INT_MAX;
		}

		dist[src] = 0;

		s.insert(make_pair(0,src));

		while(!s.empty()){

			auto val = *(s.begin());

			T node = val.second;
			int nodeDist = val.first;

			s.erase(s.begin());

			for(auto neighbor:adjList[node]){

				if(nodeDist + neighbor.second < dist[neighbor.first]){

					T destination = neighbor.first;

					auto removal = s.find(make_pair(dist[destination],destination));

					if(removal!=s.end()){
						s.erase(removal);
					}

					dist[destination] = nodeDist + neighbor.second;
					s.insert(make_pair(dist[destination],destination));
				}

			}
		}

		for(auto node:dist){
			cout<<"Node "<<node.first<<" is at a distance of "<<node.second<<endl;
		}
	}
};

int main(){

	Graph<int> g;

	g.addEdge(1,2,1);
	g.addEdge(1,3,4);
	g.addEdge(1,4,7);
	g.addEdge(4,3,2);
	g.addEdge(2,3,2);

	g.display();

	g.dijkstra(1);

	return 0;
}