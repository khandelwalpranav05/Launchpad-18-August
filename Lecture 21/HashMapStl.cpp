#include <iostream>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
	unordered_map<int, int> mp;
	mp[10] = 11;
	mp[12] = 12;
	if(mp.find(1) != mp.end()) {
		// this exist]c
		cout<<"found";
	}
	if(mp.find(10) == mp.end()) {
		cout<<"not found";
	}
	
	return 0;
}