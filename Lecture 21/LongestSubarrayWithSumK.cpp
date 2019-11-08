#include <iostream>
#include <unordered_map>
using namespace std;
int longestKSumSub(int *arr, int n, int k) {
	unordered_map<int, int> mp; // cumulativesum, first_index
	int sum = 0;
	int maxLen = INT_MIN;
	for(int i=0;i<n;i++) {
		sum+=arr[i];
		if(mp.find(sum - k) != mp.end()) {
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
 	int n, k;
	cin>>n>>k;
	int *arr = new int[n]();
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	cout<<longestKSumSub(arr, n, k);
 	return 0;
 }