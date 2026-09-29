#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++ ){
        string a, b;
        cin >> a >> b;
        vector<int> freq(26);
        for(char c : a){
            freq[c - 'a']++;
        }
        string ans = "";
        for(char c : b){
            if(!(freq[c - 'a'] > 0)){
                ans += c;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}