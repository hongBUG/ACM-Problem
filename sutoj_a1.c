#include<stdio.h>

int main() {
    int m, n;
    while(~scanf("%d %d", &m, &n)) {
        int s = m * n;
        printf("%d\n", s/2);
    }
    return 0;
}
