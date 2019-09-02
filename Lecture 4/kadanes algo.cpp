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
    int max_end_here = 0, ans = -1e9;
    // handles cases when all numbers are negative
    for (i = 0; i < n; i++) {
        if (max_end_here < 0) {
            max_end_here = 0;
        }
        max_end_here = max_end_here + a[i];
        ans = max(ans, max_end_here);
    }
    cout << ans;
}