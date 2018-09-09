#include <stdio.h>

int main() {
    int n ;
    while(~scanf("%d", &n)){
        int sum = 0, t;
        while(n--) {
            scanf("%d", &t);
            sum += t;
        }
        if (sum % 4 == 0)
            printf("%d\n", sum / 4);
        else
            printf("%d\n", sum / 4 + 1);
    }

    return 0;
}
