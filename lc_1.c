#include <stdio.h>
#include <malloc.h>


/**
 ** Note: The returned array must be malloced, assume caller calls free().
 **/
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    int *res = NULL;

    for (i = 0; i < numsSize - 1; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target)
                goto end;
        }
    }
end:
    if (i != numsSize - 1) {
        res = (int *)malloc(sizeof(int) * 2);
        res[0] = i;
        res[1] = j;
        *returnSize = 2;
    } else {
        *returnSize = 0;
    }

    return res;
}

void main()
{
    int nums[4] = {2, 7, 11, 15};
    int target = 9, returnSize = 0;

    int *res = twoSum(nums, 4, target, &returnSize);
    if (res != NULL) {
        printf("%d, %d\n", res[0], res[1]);
        free(res);
    }

}
