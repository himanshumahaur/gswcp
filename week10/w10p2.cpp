#include<bits/stdc++.h>
using namespace std;

// dice with combinations

int main() {
    int n;
    cin >> n;

    vector<int> vec(n+1);
    vec[0] = 1;

    for(int i=1; i<n+1; i++) {
        int sum = 0;
        for(int j=i-1; j>=i-6 && j>=0; j--) {
            sum += vec[j];
        }
        vec[i] = sum;
        cout << vec[i] <<" ";
    }

    return 0;
}