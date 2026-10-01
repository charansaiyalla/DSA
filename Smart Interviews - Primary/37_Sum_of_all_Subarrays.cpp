#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++ ){
        int n;
        cin >> n;
        int x;
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> x;
            sum += 1LL * (i + 1) * (n - i) * x;
        }
        cout << sum << "\n";
    }
    return 0;
}