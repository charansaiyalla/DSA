// CodeForces - 1862B

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> b(n);

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<long long> a;

    a.push_back(b[0]);

    for (int i = 1; i < n; i++) {

        if (b[i - 1] <= b[i]) {
            a.push_back(b[i]);
        } 
        else {
            a.push_back(b[i]);
            a.push_back(b[i]);
        }
    }
    cout << a.size() << '\n';

    for (long long x : a) {
        cout << x << ' ';
    }

    cout << '\n';
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}