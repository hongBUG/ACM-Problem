#include <iostream>
#include <cstdio>

using namespace std;

int n, A[100002], maxSum, maxStart, maxEnd, hereStart, hereEnd, hereSum;

int main() {
    scanf("%d", &n);
    int caseNumber = 0;
    while(n--) {
        caseNumber++;
        int k;
        scanf("%d", &k);
        for (int i = 0; i < k; i++){
            scanf("%d", A + i);
        }
        maxSum = -2147483647-1;
        hereStart = 0;
        hereSum = 0;
        hereEnd = 0;
        maxStart = 0;
        maxEnd = 0;
        for (int i = 0; i < k; i++){
            if(hereSum < 0) {
                hereSum = A[i];
                hereStart = i;
                hereEnd = i;
            } else {
                hereSum += A[i];
                hereEnd = i;
            }
            if (hereSum > maxSum) {
                maxSum = hereSum;
                maxStart = hereStart;
                maxEnd = hereEnd;
            }
        }
        printf("Case %d:\n", caseNumber);
        printf("%d %d %d\n", maxSum, maxStart + 1, maxEnd + 1);
        if (n) {
            printf("\n");
        }
    }

    return 0;
}
