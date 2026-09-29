#include <bits/stdc++.h>
using namespace std;

long long orientation(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

bool on(long long x1, long long y1, long long x2, long long y2, long long x, long long y) {
    return ( x >= min(x1, x2) && x <= max(x1, x2) ) && ( y >= min(y1, y2) && y <= max(y1, y2) );
}
int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++ ){
       long long x1, y1, x2, y2, x3, y3, x4, y4;
       cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
       
       long long a = orientation(x1, y1, x2, y2, x3, y3);
       long long b = orientation(x1, y1, x2, y2, x4, y4);
       long long c = orientation(x3, y3, x4, y4, x1, y1);
       long long d = orientation(x3, y3, x4, y4, x2, y2);
       
       bool ans = false;

       if(((a > 0 && b < 0) || (a < 0 && b > 0)) && ((c > 0 && d < 0) || (c < 0 && d > 0))){
        ans = true;
       }
       
       if(a == 0 && on(x1, y1, x2, y2, x3, y3)) ans = true;
       if(b == 0 && on(x1, y1, x2, y2, x4, y4)) ans = true;
       if(c == 0 && on(x3, y3, x4, y4, x1, y1)) ans = true;
       if(d == 0 && on(x3, y3, x4, y4, x2, y2)) ans = true; 

       cout << (ans ? "Yes" : "No") << "\n";
    }
    return 0;
}