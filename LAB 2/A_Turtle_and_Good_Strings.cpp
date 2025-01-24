#include <bits/stdc++.h>
using namespace std;

bool breakit(vector<string>& ans, int i, string& s) {
    if (i >= s.size()) {
        for (int j = 0; j < ans.size(); j++) {
            for (int k = j + 1; k < ans.size(); k++) {
                if (ans[j][0] == ans[k][ans[k].size() - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    string temp = "";
    for (int j = i; j < s.size(); j++) {
        temp.push_back(s[j]);
        ans.push_back(temp);
        
        // Debugging: Print current substring and state of ans
        
        
        
        if (breakit(ans, j + 1, s)) {
            return true;
        }
        ans.pop_back();
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        map<char, bool> check;
        bool repeat = false;
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            s.push_back(c);
            if (check[c] == true) repeat = true;
            check[c] = true;
        }
        
        if (!repeat) {
            cout << "YES" << endl;
        } else {
            vector<string> ans;
            if (breakit(ans, 0, s)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
