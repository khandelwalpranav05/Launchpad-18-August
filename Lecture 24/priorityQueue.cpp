#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Coordinates{
public:
	int x;
	int y;
	int point;

	Coordinates(int point,int x,int y){
		this->point = point;
		this->x = x;
		this->y = y;
	}

	int distance(){
		return x*x + y*y;
	}

	void display(){
		cout<<"Point Number "<<point<<" and coordinates "<<x<<" ,"<<y<<endl;
	}
};

class CoordinatesCompare{
public:
	bool operator()(Coordinates a,Coordinates b){
		return a.distance() > b.distance();
	}
};

int main(){

	int arr[3][10] = {
		{1,5,7,10},
		{2,4,8},
		{3,6,9,11},
	};

	// priority_queue<int> pq;

	// priority_queue<int,vector<int>,greater<int> > pq;

	// pq.push(15);
	// pq.push(5);
	// pq.push(2);
	// pq.push(156);
	// pq.push(4);
	// pq.push(6);
	// pq.push(160);

	// while(!pq.empty()){
	// 	cout<<pq.top()<<endl;
	// 	pq.pop();
	// }

	// priority_queue<Coordinates,vector<Coordinates>,CoordinatesCompare> crPQ;

	// int x[] = {1,2,1,5,6,4};
	// int y[] = {1,1,0,2,1,2};

	// for(int i=0;i<6;i++){
	// 	Coordinates a(i,x[i],y[i]);
	// 	crPQ.push(a);
	// }

	// while(!crPQ.empty()){
	// 	Coordinates a = crPQ.top();
	// 	a.display();
	// 	crPQ.pop();
	// }

	// CoordinatesCompare cc;
	// cc();

	return 0;
}