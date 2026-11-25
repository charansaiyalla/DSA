// LC - 678 
// Valid Parenthesis String

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else {
                low--;
                high++;
            }

            if (low < 0)
                low = 0;

            if (high < 0)
                return false;
        }

        return low == 0;
    }
};

int main() {
    string s;
    cin >> s;

    Solution obj;

    if (obj.checkValidString(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}