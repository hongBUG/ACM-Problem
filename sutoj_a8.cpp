#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int res[12];
int vis[3][12];

void queen(int cur, int sum) {
    if (cur == sum) {
        res[sum-1]++;
    }
    else {
        for (int i = 0; i < sum; i++) {
            if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + sum]) {
                vis[0][i] = 1;
                vis[1][cur + i] = 1;
                vis[2][cur - i + sum] = 1;
                queen(cur + 1, sum);
                vis[0][i] = 0;
                vis[1][cur + i] = 0;
                vis[2][cur - i + sum] = 0;
            }
        }
    }
}
int main() {
    int n;
    for (int i = 1; i < 13; i++) {
        res[i-1] = 0;
        memset(vis, 0, sizeof(vis));
        queen(0, i);
    }

    while(~scanf("%d", &n)) {
        printf("%d\n", res[n-1]);
    }
    return 0;
}
