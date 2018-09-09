#include <stdio.h>

void exchange(char str[], int len) {
    char temp;
    int i, n;
    for (i = 0, n = (len-1) /2 ; i <= n; i++) {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int to_number(char str[], int num[], int len){
    int i, state = 0;
    for (i = len - 1; i >= 0; i--) {
        if (str[i] == 'A' && state == 0) {
            len --;
        } else {
            state = 1;
            num[i] = str[i] - 'A';
        }
    }
    return len;
}

void set(char str[]) {
    int i;
    for (i = 0; i < 201; i++ ) {
        str[i] = '\0';
    }
}
void set_0(int num[]) {
    int i;
    for (i = 0; i < 201; i++) {
        num[i] = 0;
    }
}
int main() {

    char A[201] = {'\0'}, B[201] = {'\0'};
    int a[201] = {0}, b[201] = {0};
    int a_len, b_len;
    while (~scanf("%s %s", A, B)) {
        int sum[201], i, state, len;
        a_len = strlen(A);
        b_len = strlen(B);
        // 逆转
        exchange(A, a_len);
        exchange(B, b_len);
        a_len = to_number(A, a, a_len);
        b_len = to_number(B, b, b_len);
        len = a_len >= b_len ? a_len : b_len;
        if (len == 0) {
            printf("A\n");
            continue;
        }
        state = 0;
        // 做加法
        for (i = 0; i < len; i++) {
            sum[i] = state + a[i] + b[i];
            if (sum[i] >= 26) {
                sum[i] -= 26;
                state = 1;
            }
            else {
                state = 0;
            }
        }
        if (state != 0){
            sum[len++] = 1;
        }

        // 转为字符串
        for (i = len - 1; i >= 0; i--) {
            A[i] = sum[i] + 'A';
            printf("%c", A[i]);
        }
        printf("\n");

        set(A);
        set(B);
        set_0(a);
        set_0(b);
    }
    return 0;
}
