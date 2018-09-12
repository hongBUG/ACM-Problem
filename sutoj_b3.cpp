#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, T_s[101], T_e[101], T_s2[101], T_e2[101], min_end, sum;

void Merge( int l, int m, int r) {
    int i = l, j = m + 1, k;
    for (k = l; i <= m && j <= r; k++) {
        if (T_s[i] <= T_s[j]) {
            T_s2[k] = T_s[i];
            T_e2[k] = T_e[i++];
        } else {
            T_s2[k] = T_s[j];
            T_e2[k] = T_e[j++];
        }
    }
    while(i <= m) {
        T_s2[k] = T_s[i];
        T_e2[k++] = T_e[i++];
    }
    while(j <= r) {
        T_s2[k] = T_s[j];
        T_e2[k++] = T_e[j++];
    }
    for (i = l; i <= r; i++) {
        T_s[i] = T_s2[i];
        T_e[i] = T_e2[i];
    }
}
void Msort(int l, int r) {
    int m;
    if (l != r) {
        m = (l + r) / 2;
        Msort(l, m);
        Msort(m+1, r);
        Merge(l, m, r);
    }
}
int main() {
    while(~scanf("%d", &n)) {
        sum = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d %d", T_s + i, T_e + i);
        }
        Msort(0, n - 1);
        min_end = 0;
        int temp_location;
        for (int i = 0; i < n; i++) {
            if (T_s[i] >= min_end) {
                min_end = T_e[i];
                temp_location = i;
                for (int j = i + 1; j < n; j++) {
                    if (T_e[j] < min_end) {
                        temp_location = j;
                        min_end = T_e[j];
                    }
                }
                i = temp_location;
                sum++;
            }
        }
        printf("%d\n", sum);


    }
    return 0;
}
