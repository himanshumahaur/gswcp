#include<bits/stdc++.h>
using namespace std;

vector<int> mycount(10001, 10001);

int coin(int x) {
    mycount[0] = 0;
    for(int i=1; i<x+1; i++) {
        if(mycount[i]==10001) {
            mycount[i] = mycount[i-1] + 1;
            for(int j=1; j<i; j++) {
                if((i-j)%j==0) mycount[i] = min(mycount[i], mycount[j] + 4 + ((i-j)/j)*2);
            }
        }
    }
    return mycount[x];
}
 
int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;

        if(i!=n-1)
        cout << coin(x) << endl;
        else 
        cout << coin(x);
    }
}