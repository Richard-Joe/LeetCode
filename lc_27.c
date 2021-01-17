#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
    int i = 0, j;
    for (j = 0; j < numsSize; j++) {
        if (nums[j] == val)
            continue;
        else
            nums[i++] = nums[j];
    }
    return i;
}

int main(int argc, char const *argv[])
{
    int arr[8] = {0,1,2,2,3,0,4,2};
    printf("%d\n", removeElement(arr, 8, 2));
    return 0;
}