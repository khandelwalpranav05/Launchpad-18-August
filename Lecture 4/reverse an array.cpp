#include<bits/stdc++.h>

using namespace std;

int main()
{
	int i, n;
	cin >> n;
	int a[n];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i = 0; i < n / 2 ; i++) {
		a[i] = a[n - i - 1];
	}
	for (i = 0; i < n; i++) {
		for (i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
	}