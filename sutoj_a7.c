#include <stdio.h>
#include <string.h>

int main() {
    int n, m, i, a, res, temp = 0;
    int G[100001], V[100001], B[100001];
    int state[100001];
    while(~scanf("%d %d", &n, &m)) {
        memset(state, 0, 100001);
        for(i = 1; i <= n; i++){
            scanf("%d", G + i);
        }
        for(i = 1; i <= m; i++){
            scanf("%d", V + i);
        }

        for(i = 1; i <= m; i++){
            scanf("%d", B + i);
        }
        for (i = 1; i <= m; i++) {
            res = 0;
            a = ((V[i] + temp - 1) % n) + 1;
            while(B[i]--) {
                if (!state[a]) {
                    res++;
                    state[a] = 1;
                }
                a = G[a];
            }
            printf("%d\n", res);
            temp = res;
        }
    }
}
