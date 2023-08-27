#include <bits/stdc++.h>
using namespace std;

bool canConnect(const string &a, const string &b) {
    return a.back() == b.front();
}

string buildConnectionString(const vector<string> &words) {
    int n = words.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (len == 1) {
                dp[i][j] = true;
            } else if (len == 2) {
                dp[i][j] = canConnect(words[i], words[j]);
            } else {
                dp[i][j] = canConnect(words[i], words[j]) && dp[i + 1][j - 1];
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    string result;
    for (int k = 0; k < n; ++k) {
        result += dp[0][k] ? "1" : "0";
    }

    return result;
}

int main() {
    vector<string> words = {"he", "ll", "lo", "el"};
    string ans = buildConnectionString(words);
    cout << ans << endl;  // Output: "1001"

    return 0;
}
