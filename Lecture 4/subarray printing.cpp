#include<bits/stdc++.h>

using namespace std;

int main()
{
	//  code starts
	int i, n, j;
	cin >> n;
	int a[n];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int sz = 1; sz <= n; sz++) {
		for (int st = 0; st + sz <= n; st++) {
			int en = st + sz - 1;
			for (i = st; i <= en; i++) {
				cout << a[i] << " ";
			}
			cout << '\n';
		}
	}
}