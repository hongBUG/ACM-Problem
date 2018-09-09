#include <stdio.h>

int main() {

    int n;
    while(~scanf("%d", &n)) {
        printf("%d\n", 2 * n * n - n + 1);
    }
    return 0;
}
