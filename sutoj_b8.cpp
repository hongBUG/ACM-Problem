#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n, S[101], E[101], dp[101][101], temp, r;
    while (~scanf("%d", &n)) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            scanf("%d %d", S + i, E + i);
        }
        for (int i = 1; i < n; i++) {
            dp[i - 1 ][i] = S[i - 1] * E[i - 1] * E[i];
        }

        for (int i = 2; i < n; i++) {
            for (int j = 0, m = n - i; j < m; j++){
                r = j + i;
                dp[j][r] = 99999999;
                for (int k = 0; k < i; k++) {
                     dp[j][r] = min(dp[j][r], dp[j][j + k] + dp[j + k + 1][r] + S[j] * E[j + k] * E[r]);
                }
            }
        }
        printf("%d\n", dp[0][n-1]);
    }

    return 0;
}
