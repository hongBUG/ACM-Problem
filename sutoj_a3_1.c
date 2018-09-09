#include <stdio.h>
#include <string.h>

int BiSearch(int *b, int len, int w);
int main() {
// 二分查找算法，时间复杂度nlgn
    int n;
    int A[10001];
    int B[10001];
    while (~scanf("%d", &n)) {
        int i, j, len, pos;
        for (i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        B[0] = A[0];
        len = 1;
        for (i = 1; i < n; i++) {
            if (A[i] > B[len-1]) {
                B[len++] = A[i];
            }
            else {
                pos  = BiSearch(B, len, A[i]);
                B[pos] = A[i];
            }
            /*for (j = 0; j < len; j ++) {
                if (B[j] > A[i]) {
                    B[j] = A[i];
                    break;
                }
            }*/
        }
        printf("%d\n", len);
    }

    return 0;
}

int BiSearch(int *b, int len, int w) {
    int left = 0, right = len - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (b[mid] < w) {
             left = mid + 1;
        } else if (b[mid] > w) {
            right = mid - 1;
        }
        else {
            return mid;
        }
    }
    return left;
}
