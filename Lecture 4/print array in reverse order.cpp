#include<bits/stdc++.h>

using namespace std;

int main()
{
    //  code starts
    int n;
    cin >> n;
    // initialise the array
    // be careful to initialise after n has a constant value
    int array[n];
    for (int i = 0; i < n; i++) {
        // input every element of the array
        cin >> array[i];
    }
    // iterate backwards
    for (int i = n - 1; i >= 0; i--) {
        cout << array[i] << '\n';
    }
}