// CodeForces - 1873C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int score = 0;

        for (int i = 0; i < 10; i++) {
            string s;
            cin >> s;

            for (int j = 0; j < 10; j++) {
                if (s[j] == 'X') {
                    int points = min({ i, j, 9 - i, 9 - j }) + 1;
                    score += points;
                }
            }
        }
        cout << score << '\n';
    }

    return 0;
}