#include <iostream>
#include <algorithm>

using namespace std;

class ActivityTime{
public:
	int start,end;
};

int compare(ActivityTime a,ActivityTime b){
	return a.end<b.end;
}

int maxActivity(int startTime[],int endTime[],int n){

	ActivityTime arr[n];

	for(int i=0;i<n;i++){
		arr[i].start = startTime[i];
		arr[i].end = endTime[i];
	}

	sort(arr,arr+n,compare);

	// for(int i=0;i<n;i++){
	// 	cout<<"startTime "<<arr[i].start<<" and endTime "<<arr[i].end<<endl;
	// }

	int numActivity = 1;
	int check = arr[0].end;

	for(int i=1;i<n;i++){
		if(check<=arr[i].start){
			numActivity++;
			check = arr[i].end;
		}
	}

	return numActivity;
}


int deepakAndJourney(int cost[],int dist[],int n){

	int minCost = cost[0];

	int ans = cost[0]*dist[0];

	for(int i=1;i<n;i++){

		if(cost[i]<minCost){
			minCost = cost[i];
		}

		ans += minCost*dist[i];
	}

	return ans;
}


int main(){

	int startTime[] = {7,0,4,3,4,6};
	int endTime[] = {9,10,5,9,10,7};

	int n = 6;

	cout<<maxActivity(startTime,endTime,n)<<endl;

	return 0;
}