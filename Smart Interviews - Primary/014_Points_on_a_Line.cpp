#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++ ){
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if((y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1) )
            cout << "Yes\n";
        else 
            cout << "No\n";
    }
    return 0;
}