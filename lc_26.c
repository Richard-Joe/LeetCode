#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    if (numsSize < 2)
        return numsSize;
    int i = 0, j;
    for (j = 1; j < numsSize; j++) {
        if (nums[j] != nums[i]) {
            nums[++i] = nums[j];
        }
    }
    return i+1;
}

int main(int argc, char const *argv[])
{
    int arr[10] = {0,0,1,1,1,2,2,3,3,4};
    printf("%d\n", removeDuplicates(arr, 10));
    return 0;
}