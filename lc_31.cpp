#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int numsSize = nums.size();
        int i = numsSize - 2, j;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            --i;
        }

        if (i >= 0) {
            j = numsSize - 1;
            while (j >= 0 && nums[j] <= nums[i])
                --j;

            swap(&nums[i], &nums[j]);
        }

        for (i = i + 1, j = numsSize - 1; i < j; ++i, --j) {
            swap(&nums[i], &nums[j]);
        }
    }
};

void print_nums(vector<int>& nums) {
    int i;
    int numsSize = nums.size();
    for (i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main(void)
{
    vector<int> vec {6,1,2,4,3,0};
    Solution s;
    s.nextPermutation(vec);
    print_nums(vec);
    return 0;
}