#include <iostream>
#include <cstdio>

using namespace std;

void Merge(int SR[], int TR[], int l, int m, int r) {
    int i = l, j = m + 1, k;
    for (k = l; i <= m && j <= n; k++) {
        if (SR[l] <= SR[j]) {
            TR[k] = SR[l++];
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


}
