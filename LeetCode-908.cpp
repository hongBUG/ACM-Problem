#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int smallestRangeI(vector<int>& A, int K) {
    sort(A.begin(), A.end());
    int min_A = A[0];
    int max_A = A[A.size() - 1];
    if (max_A - min_A <= 2 * K) {
        return 0;
    } else {
        return max_A - min_A - 2 * K;
    }
}

int main() {
    vector<int> A;
    int a;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a);
        A.push_back(a);
    }
    cout << smallestRangeI(A, 10) << endl;

    return 0;
}
