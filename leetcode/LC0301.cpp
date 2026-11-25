// LC - 301
// Remove Invalid Parentheses

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxlen = 0;
    unordered_set<string> st;

    void solve(string& s, string& curr, int index, int cnt) {

        if (cnt < 0)
            return;

        if (index == s.length()) {

            if (cnt == 0) {

                if (curr.length() > maxlen) {
                    maxlen = curr.length();
                    st.clear();
                }

                if (curr.length() == maxlen) {
                    st.insert(curr);
                }
            }

            return;
        }

        if (s[index] == '(' || s[index] == ')') {

            // Choice 1: Keep the parenthesis
            curr.push_back(s[index]);

            solve(
                s,
                curr,
                index + 1,
                cnt + (s[index] == '(' ? 1 : -1)
            );

            curr.pop_back();

            // Choice 2: Remove the parenthesis
            solve(
                s,
                curr,
                index + 1,
                cnt
            );

        } else {

            // Normal character: always keep it
            curr.push_back(s[index]);

            solve(
                s,
                curr,
                index + 1,
                cnt
            );

            curr.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        maxlen = 0;
        st.clear();

        string curr = "";

        solve(s, curr, 0, 0);

        return vector<string>(st.begin(), st.end());
    }
};


int main() {

    Solution sol;

    string s;
    cin >> s;

    vector<string> ans = sol.removeInvalidParentheses(s);

    for (string x : ans) {
        cout << x << '\n';
    }

    return 0;
}