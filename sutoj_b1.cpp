
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    int n, i, sum;
    int A[501];
    // FILE *fRead = fopen("test.in", "r");
    // FILE *fWrite = fopen("test.out", "w");
    while(~scanf("%d", &n)) {
        for(i = 0; i < n; i++) {
            scanf("%d", A + i);
        }
        sort(A, A+n);
        sum = n * A[n-1];
        for (i = 0; i < n -1; i++) {
            sum += (i + 2) * A[i];
        }
        printf("%d\n", sum);
    }
}

