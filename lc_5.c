#include <stdio.h>
#include <string.h>
#include <malloc.h>

int aroundLen(char *s, int len, int left, int right)
{
    int L = left, R = right;
    while (L >= 0 && R < len && s[L] == s[R]) {
        L--; R++;
    }
    return R - L - 1;
}

char * longestPalindrome(char * s)
{
    int len = strlen(s), len1, len2, len3;
    int start = 0, end = 0;
    for (int i = 0; i < len; i++) {
        len1 = aroundLen(s, len, i, i);
        len2 = aroundLen(s, len, i, i+1);
        len3 = (len1 > len2) ? len1 : len2;
        if (len3 > end - start) {
            start = i - (len3 - 1) / 2;
            end = i + len3 / 2;
        }
    }

    char *sub = (char *)malloc(end-start+2);
    memset(sub, 0, end-start+2);
    memcpy(sub, s+start, end-start+1);
    return sub;
}

int main(void)
{
    return 0;
}
