#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int vis[3][30], n, res;

void queen(int cur) {
    if (cur == n) {
        res++;
    } else {
        for (int i = 0; i < n; i++){
            if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n]) {
                vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
                queen(cur + 1);
                vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
            }
        }
    }
}

int main() {
    while(~scanf("%d", &n)) {
        memset(vis, 0, sizeof(vis));
        res = 0;
        queen(0);
        printf("%d\n", res);
    }
}
