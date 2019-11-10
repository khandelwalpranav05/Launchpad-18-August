#include <iostream>
#include <unordered_map>
using namespace std;

int longestZeroSumSub(int *arr, int n) {
	unordered_map<int, int> mp; // cumulativesum, first_index
	int sum = 0;
	int maxLen = INT_MIN;
	for(int i=0;i<n;i++) {
		sum+=arr[i];
		if(mp.find(sum) != mp.end()) {
			int firstOccurence = mp[sum];
			int newLen = i - firstOccurence;
			if(newLen > maxLen) {
				maxLen = newLen;
			}
		} else {
			mp[sum] = i;
		}
	}
	return maxLen;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr = new int[n]();
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	cout<<longestZeroSumSub(arr, n);
	return 0;
}