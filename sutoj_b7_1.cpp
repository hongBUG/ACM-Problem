/**
* 分支限界法求解(回溯法？)
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int coins[] = {1, 5, 10, 25, 50}, sum[5], sums;

void dfs(int n, int counts, int nowlocation) {
    if ( counts == n) {
        sums++;
    } else if (counts < n) {
        for (int i = nowlocation; i < 5; i++) {
            sum[i]++;
            dfs(n, counts + coins[i], i);
            sum[i]--;
        }
    }
}

int main() {
    int a, counts;
    while (~scanf("%d", &a)) {
        sums = 0;
        memset(sum, 0, sizeof(sum));
        dfs(a, 0, 0);
        printf("%d\n", sums);
    }

    return 0;
}
