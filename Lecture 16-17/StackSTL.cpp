#include <iostream>
#include <stack>

using namespace std;

int main(){

	stack<int> s;

	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	s.push(0);

	s.pop();
	s.pop();
	cout<<s.top()<<endl;

	s.pop();
	cout<<s.top()<<endl;

	// cout<<s.empty()<<endl;

	return 0;
}