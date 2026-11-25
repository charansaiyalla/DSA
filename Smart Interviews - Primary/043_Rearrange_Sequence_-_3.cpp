#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& a){
    int n = a.size();
    int ans = 1;
    for(int i = 0; i < n; i++) {
        int mini = a[i];
        int maxi = a[i];
        unordered_set<int> st;
        for(int j = i; j < n; j++){
            st.insert(a[j]);
            mini = min(mini, a[j]);
            maxi = max(maxi, a[j]);
            if(st.size() - 1 == maxi - mini)
                ans = max(ans, j - i + 1);
        }
    }
    cout << ans << "\n";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++ ){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int& x : arr) {
            cin >> x;
        }
        solve(arr);
    }
    return 0;
}