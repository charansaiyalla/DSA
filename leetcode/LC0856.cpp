// LC - 856
// Score of Parentheses

#include <bits/stdc++.h>using namespace std;

int scoreOfParentheses(string s) {
    stack<int> st;
    st.push(0);

    for (char c : s) {
        if (c == '(') {
            st.push(0);
        } 
        else {
            int inner = st.top();
            st.pop();

            int score;

            if (inner == 0) {
                score = 1;
            } 
            else {
                score = 2 * inner; 
            }

            st.top() += score;
        }
    }

    return st.top();
}

int main() {
    string s;

    cout << "Enter parentheses string: ";
    cin >> s;

    cout << "Score: " << scoreOfParentheses(s) << endl;

    return 0;
}