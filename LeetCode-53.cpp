#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int max_sum = -INT_MAX - 1;
    int max_cur = 0;
    for (int i = 0; i < n; i++) {
        if (max_cur < 0) {
            max_cur = nums[i];
        } else {
            max_cur += nums[i];
        }
        if (max_cur > max_sum) {
            max_sum = max_cur;
        }
    }
    return max_sum;
}

int main(){

}
