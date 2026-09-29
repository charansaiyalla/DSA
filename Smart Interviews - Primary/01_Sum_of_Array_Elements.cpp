#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++ ){
        long long n, x, sum = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x;
            sum += x;
        }
        cout << sum << endl;
    }
    return 0;
}