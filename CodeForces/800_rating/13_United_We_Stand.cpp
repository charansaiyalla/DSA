// CodeForces - 1859A

#include <bits/stdc++.h>
using namespace std;

int main() {

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mini = min(mini, arr[i]);
        }

        vector<int> a, b;

        for (int x : arr) {
            if (x == mini) {
                a.push_back(x);
            } else {
                b.push_back(x);
            }
        }

        if (b.empty()) {
            cout << -1 << '\n';
            continue;
        }

        cout << a.size() << " " << b.size() << '\n';

        for (int x : a) {
            cout << x << " ";
        }
        cout << '\n';

        for (int x : b) {
            cout << x << " ";
        }
        cout << '\n';
    }

    return 0;
}