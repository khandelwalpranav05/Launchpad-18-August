#include <iostream>
#include <unordered_map>
using namespace std;

bool isZeroSumSub(int *arr, int n) {
	unordered_map<int, int> mp;
	int sum = 0;
	for(int i=0;i<n;i++) {
		sum+=arr[i];
		if(mp.find(sum) != mp.end()) {
			return true;
		}
		mp[sum] = sum;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}