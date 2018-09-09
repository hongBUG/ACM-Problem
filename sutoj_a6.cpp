#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

const int max_n = 102;

// 利用优先队列的特性
struct Node {
    int x, y;
    int step;
    bool operator<(const Node& a) const{
        return step > a.step;
    }
};

int n, m, res, sec;
bool vis[max_n][max_n];
char mmap[max_n][max_n];
struct Node ans[max_n][max_n];  // 用于记录前一个点的坐标
int Next[4][2] = {{0, 1}, {1, 0}, {0, 1}, {-1, 0}};
priority_queue<struct Node> que;

void bfs() {
    while (que.size()) {
        que.pop();
    }
    struct Node s;
    s.x = 0;
    s.y = 0;
    s.step = 0;
    que.push(s);
    vis[0][0] = true;
    while (que.size()) {
        struct Node cur_node, next_node;
        cur_node = que.top();
        que.pop();
        if (cur_node.x == n - 1 && cur_node.y == m - 1) {
            res = cur_node.step;
            return;
        }
         for (int i = 0; i < 4; i++) {
            int dx = cur_node.x + Next[i][0];
            int dy = cur_node.y + Next[i][1];
            next_node.x = dx;
            next_node.y = dy;
            if (dx < 0 || dx >= n || dy < 0 || dy >= m || vis[dx][dy] || mmap[dx][dy] == 'X') {
                continue;
            }
            ans[dx][dy].x = cur_node.x;
            ans[dx][dy].y = cur_node.y;
            vis[dx][dy] = true;
            next_node.step = cur_node.step + 1;
            if (mmap[dx][dy] >= '1' && mmap[dx][dy] <= '9') {
                next_node.step += mmap[dx][dy] - '0';
            }
            que.push(next_node);
         }
    }
}

void show(int a, int b) {
    if(ans[a][b].x != 0 || ans[a][b].y != 0) {
        show(ans[a][b].x, ans[a][b].y);
    }
    printf("%ds:(%d,%d)->(%d,%d)\n", ++sec, ans[a][b].x, ans[a][b].y, a, b);
    if (mmap[a][b] >= '1' && mmap[a][b] <= '9') {
        int cnt = mmap[a][b] - '0';
        for (int i = 0; i < cnt; i++ ) {
            printf("%ds:FIGHT AT (%d,%d)\n", ++sec, a, b);
        }
    }
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < n; i++) {
            scanf("%s", mmap[i]);
        }
        memset(vis, false, sizeof(vis));
        memset(ans, 0, sizeof(ans));
        res = 0;
        sec = 0;
        bfs();
        if (res == 0) {
            printf("God please help our poor hero.\n");
        } else {
            printf("It takes %d seconds to reach the target position, let me show you the way.\n", res);
            show(n - 1, m - 1);
        }
        printf("FINISH\n");
    }

    return 0;
}
