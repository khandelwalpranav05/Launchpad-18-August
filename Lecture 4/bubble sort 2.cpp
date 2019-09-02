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
	for (j = 0; j < n; j++) {
		for (i = 0; i < n - 1 - j; i++) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
			}
		}
	}
	for (i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}