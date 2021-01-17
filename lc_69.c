#include <stdio.h>

#define BITS_PER_LONG 32

static int __fls(int word)
{
    int num = BITS_PER_LONG - 1;

    if (!(word & (~0ul << (BITS_PER_LONG-16)))) {
        num -= 16;
        word <<= 16;
    }
    if (!(word & (~0ul << (BITS_PER_LONG-8)))) {
        num -= 8;
        word <<= 8;
    }
    if (!(word & (~0ul << (BITS_PER_LONG-4)))) {
        num -= 4;
        word <<= 4;
    }
    if (!(word & (~0ul << (BITS_PER_LONG-2)))) {
        num -= 2;
        word <<= 2;
    }
    if (!(word & (~0ul << (BITS_PER_LONG-1))))
        num -= 1;
    return num;
}

int mySqrt1(int x)
{
    int b, m, y = 0;

    if (x <= 1)
        return x;

    m = 1UL << (__fls(x) & ~1UL);
    while (m != 0) {
        b = y + m;
        y >>= 1;

        if (x >= b) {
            x -= b;
            y += m;
        }
        m >>= 2;
    }

    return y;
}

int mySqrt2(int x)
{
    int l = 0, h = x, ans;
    while (l <= h) {
        int m = l + (h - 1) / 2;
        if ((long long) m * m <= x) {
            ans = m;
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", mySqrt2(9));
    return 0;
}