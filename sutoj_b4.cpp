#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1001], v, n, V[101], M[101];
int main() {
    while(~scanf("%d %d", &v, &n)) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", V + i, M + i);
        }
        for (int i = 1; i <= n; i++){
            for (int j = v; j >= V[i]; j--) {
                dp[j] = max(dp[j], dp[j-V[i]] + M[i]);
            }
        }
        printf("%d\n", dp[v]);
    }

    return 0;
}
