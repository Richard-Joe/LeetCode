#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int idx1 = 0, idx2 = 0;
    int *p1 = nums1, *p2 = nums2;
    int k = (nums1Size + nums2Size) / 2;
    while (k > 0) {
        int m = k / 2;
        if (m == 0) {
            m = 1;
        }

        if (m - 1 < nums1Size && m - 1 < nums2Size) {
            if (p1[m - 1] < p2[m - 1]) {
                p1 += m;
                idx1 += m;
            }
            else {
                p2 += m;
                idx2 += m;
            }
            k -= m;
        } else if (m - 1 >= nums1Size) {
            p2 += (k - m);
            idx2 += m;
            break;
        } else {
            p1 += (k - m);
            idx1 += m;
            break;
        }
    }

    if ((nums1Size + nums2Size) & 0x01) {
        if (idx1 == nums1Size)
            return nums2[idx2];
        else if (idx2 == nums2Size)
            return nums1[idx1];
        else 
            return (nums1[idx1] > nums2[idx2]) ? nums2[idx2] : nums1[idx1];
    } else {
        return (me1 + me2) / 2.0;
    }
}

int main(void)
{
    int a[4] = {1, 3, 4, 9};
    int b[6] = {1,2,3,4,5,6};
    printf("%f\n", findMedianSortedArrays(a, 4, b, 6));
    return 0;
}