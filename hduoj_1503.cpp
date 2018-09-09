#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char A[101], B[101], S[101];
int X[101], Y[101], dp[101][101], a_len, b_len;
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

        if (dp[a_len][b_len] == 0) {
            printf("%s%s\n", A, B);
        }else  {
            int p = a_len, q = b_len, k = 0;
            while (p > 0 || q > 0) {
                if (dp[p][q] == dp[p - 1][q - 1] + 1 && A[p - 1] == B[q - 1]) {
                    S[k] = A[p - 1];
                    X[k] = --p;
                    Y[k++] = --q;
                } else if (dp[p - 1][q] >= dp[p][q - 1] ) {
                    p--;
                } else {
                    q--;
                }
            }
            int x = 0, y = 0;
            for (int i = k - 1; i >= 0; i--){
                while (x != X[i]) {
                    printf("%c", A[x++]);
                }
                while (y != Y[i]) {
                    printf("%c", B[y++]);
                }
                printf("%c", S[i]);
                x++;
                y++;
            }
            for (int i = X[0] + 1; i < a_len; i++) {
                printf("%c", A[i]);
            }
            for (int i = Y[0] + 1; i < b_len; i++) {
                printf("%c", B[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
