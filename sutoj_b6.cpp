
#include <iostream>
#include <cstdio>

using namespace std;

void Merge(int SR[], int TR[], int l, int m, int r) {
    int i = l, j = m + 1, k;
    for (k = l; i <= m && j <= r; k++) {
        if (SR[i] <= SR[j]) {
            TR[k] = SR[i++];
        } else {
            TR[k] = SR[j++];
        }
    }
    while(i <= m) {
        TR[k++] = SR[i++];
    }
    while(j <= r) {
        TR[k++] = SR[j++];
    }
    for (i = l; i <= r; i++) {
        SR[i] = TR[i];
    }
}
void Msort(int SR[], int TR[], int l, int r) {
    int m;
    if (l == r) {
        TR[l] = SR[r];
    } else {
        m = (l + r) / 2;
        Msort(SR, TR, l, m);
        Msort(SR, TR, m+1, r);
        Merge(SR, TR, l, m, r);
    }
}
int main() {
    int A[100001], B[100001], n;
    while(~scanf("%d", &n)){
        for (int i = 0; i < n; i++){
            scanf("%d", A + i);
        }
        Msort(A, B, 0, n - 1);
        for (int i = 0; i < n; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
    return 0;
}
