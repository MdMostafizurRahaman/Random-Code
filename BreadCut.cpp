#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int bread_length, num_cuts;
int cut_positions[MAX];
int dp[MAX][MAX];

int cuttingCost(int start, int finish) {

    if(dp[start][finish] != -1) return dp[start][finish];
    if(start + 1 == finish) return 0;

    int minCost = INT_MAX;

    for(int i = 1; i <= num_cuts; i++) {
        if(cut_positions[i] <= start || cut_positions[i] >= finish) continue;

        int cost = finish - start + cuttingCost(start, cut_positions[i]) + cuttingCost(cut_positions[i], finish);
        minCost = min(minCost, cost);
    }

    if(minCost == INT_MAX) minCost = 0;

    dp[start][finish] = minCost;
    return dp[start][finish];
}

int main() {
    cin >> bread_length >> num_cuts;

    for(int i = 1; i <= num_cuts; i++) cin >> cut_positions[i];

    memset(dp, -1, sizeof(dp));

    cout << "Minimum cutting cost is: " << cuttingCost(0, bread_length) << endl;
    
    return 0;
}
