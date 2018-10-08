#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        vector<int> nums_b(nums);
        sort(nums.begin(), nums.end());
        int i, j, temp;
        j = 0;
        i = nums.size() - 1;
        while(j != i){
            temp = nums[i] + nums[j];
            if (temp == target) {
                for (int n = 0, m = nums.size(); n < m; n++) {
                    if (nums[i] == nums_b[n] || nums[j] == nums_b[n]) {
                        res.push_back(n);
                        if (res.size() == 2){
                            break;
                        }
                    }
                }
                return res;
            } else if (temp < target) {
                j++;
            } else {
                i--;
            }
        }
    }
int main(){
    vector<int> A, B;
    int a;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a);
        A.push_back(a);
    }

    B = twoSum(A, 10);
    cout << B[0] << " " << B[1] << endl;
    return 0;
}
