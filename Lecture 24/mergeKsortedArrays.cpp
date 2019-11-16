#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

class Point{
public:
	int value;
	int idx;
	int arrayPosition;

	Point(int value,int idx,int arrayPosition){
		this->value = value;
		this->idx = idx;
		this->arrayPosition = arrayPosition;
	}
};

class PointCompare{
public:
	bool operator()(Point a,Point b){
		return a.value > b.value;
	}
};


int main(){

	priority_queue<Point,vector<Point>,PointCompare > pq;

	int arr[3][5] = {
		{1,5,7,10,0},
		{2,4,8,9,0},
		{3,6,9,11,0},
	};

	int k = 3;

	for(int i=0;i<k;i++){
		Point obj(arr[i][0],0,i);
		pq.push(obj);
	}

	vector<int> v;

	while(pq.top().value !=INT_MAX){

		Point temp = pq.top();
		pq.pop();

		v.push_back(temp.value);
		int kth = temp.arrayPosition;
		int pos = temp.idx + 1;

		int newValue = arr[kth][pos];

		if(newValue==0){
			newValue = INT_MAX;
		}

		Point obj(newValue,pos,kth);
		pq.push(obj);
	}

	for(auto var:v){
		cout<<var<<" ";
	}
	cout<<endl;
}