#include<bits/stdc++.h>

using namespace std;

int main()
{
    //  code starts
    int i, n;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i = 0; i < n; i++) {
        int j = i - 1;
        while (j >= 0 && a[j + 1] < a[j]) {
            swap(a[j + 1], a[j]);
            j--;
        }
    }
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}