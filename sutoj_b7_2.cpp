/**
*   动态规划解题（优化过）
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int n, coins[] = {1, 5, 10, 25, 50}, sum[100000];
    while(~scanf("%d", &n)) {
        memset(sum, 0, sizeof(sum));
        sum[0] = 1;
        for (int i = 0; i < 5; i++){
            for (int j = coins[i]; j <= n; j++ ) {
                sum[j] += sum[j - coins[i]];
            }
        }
        printf("%d\n", sum[n]);
    }
    return 0;
}
