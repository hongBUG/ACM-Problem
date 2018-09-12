
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char A[1001], B[1001];
int dp[1001][1001], a_len, b_len;
int main() {
    while(~scanf("%s %s", A, B)) {
        memset(dp, 0, sizeof(dp));
        a_len = strlen(A);
        b_len = strlen(B);
        for (int i = 1; i <=  a_len; i++) {
            for (int j = 1; j <= b_len; j++) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        printf("%d\n", dp[a_len][b_len]);
    }
    return 0;
}
