#include <stdio.h>
#include <limits.h>

#define min(x, y) ((x > y) ? y : x)

int maxArea(int* height, int heightSize){
    int i, j;
    int max = INT_MIN;
    for (i = 0, j = heightSize - 1; i < j;) {
        int tmp = min(height[i], height[j]) * (j - i);
        if (tmp > max) {
            max = tmp;
        }
        if (height[i] > height[j])
            j--;
        else
            i++;
    }
    return max;
}

int main(int argc, char const *argv[])
{
    int a[9] = {1,8,6,2,5,4,8,3,7};
    printf("%d\n", maxArea(a, 9));
    return 0;
}