#include <stdio.h>
#include <string.h>

int main() {
// 动态规划解法
    int n;
    int A[10000];
    int state[10000];
    while (~scanf("%d", &n)) {
        int i, j;
        for (i = 0; i < n; i++) {
            state[i] = 1;
            scanf("%d", &A[i]);
            for (j = 0; j < i; j++) {
                if (A[j] <= A[i] && state[i] <= state[j]) {
                    state[i] = state[j] + 1;
                } else if (state[i] < state[j] ) {
                    state[i] = state[j];
                }
            }
        }
        printf("%d\n", state[n-1]);
    }

    return 0;
}
