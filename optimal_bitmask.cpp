#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> cost(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> cost[i][j];

    int totalStates = 1 << N;
    vector<int> dp(totalStates, INT_MAX);
    dp[0] = 0;

    for (int mask = 0; mask < totalStates; mask++) {

        int worker = __builtin_popcount(mask);

        for (int task = 0; task < N; task++) {
            if (!(mask & (1 << task))) {
                int newMask = mask | (1 << task);
                dp[newMask] = min(dp[newMask],
                                  dp[mask] + cost[worker][task]);
            }
        }
    }

    cout << dp[totalStates - 1] << endl;
    return 0;
}
