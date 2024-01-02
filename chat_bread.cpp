#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, n;
    cin >> l >> n;
    int c[n];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int dp[n+1][n+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i+1; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k][j] + (c[j]-c[i]));
            }
        }
    }

    cout << "The minimum cost of cutting the bread is " << dp[0][n-1] << "." << endl;
    return 0;
}
