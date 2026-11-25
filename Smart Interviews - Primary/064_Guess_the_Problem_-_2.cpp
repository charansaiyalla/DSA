#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++ ){
        string a;
        int x;
        cin >> a >> x;
        for(int i = 0; i < a.size(); i++){
            a[i] = (((a[i] - 'a') + x ) % 26) + 'a';
        }
        cout << a << "\n";
    }
    return 0;
}