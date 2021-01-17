#include <stdio.h>
#include <string.h>
#include <malloc.h>

#if 0
char * longestPalindrome(char * s)
{
    int i, j;
    int len = strlen(s);
    int maxstart = 0, maxend = 0, maxlen = 0;

    char **dp = NULL;
    dp = (char **)malloc(sizeof(char *) * len);
    for (i = 0; i < len; i++) {
        dp[i] = (char *)malloc(len);
        memset(dp[i], 0, len);
    }

    for (i = 0; i < len; i++) {
        for (j = 0; j < i; j++) {
            if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])) {
                dp[j][i] = 1;
                if (i - j + 1 > maxlen) {
                    maxstart = j;
                    maxend = i;
                    maxlen = i - j + 1;
                }
            }
        }
    }

    for (i = 0; i < len; i++)
        free(dp[i]);
    free(dp);

    char *sub = (char *)malloc(maxend-maxstart+2);
    memset(sub, 0, maxend-maxstart+2);
    memcpy(sub, s+maxstart, maxend-maxstart+1);
    return sub;
}

#else
#define MAXLEN 1000
char dp[MAXLEN][MAXLEN] = {{0}};

char * longestPalindrome(char * s)
{
    int i, j;
    int len = strlen(s);
    int maxstart = 0, maxend = 0, maxlen = 0;

    memset(dp, 0, MAXLEN * MAXLEN);

    for (i = 0; i < len; i++) {
        for (j = 0; j < i; j++) {
            if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])) {
                dp[j][i] = 1;
                if (i - j + 1 > maxlen) {
                    maxstart = j;
                    maxend = i;
                    maxlen = i - j + 1;
                }
            }
        }
    }

    char *sub = (char *)malloc(maxend-maxstart+2);
    memset(sub, 0, maxend-maxstart+2);
    memcpy(sub, s+maxstart, maxend-maxstart+1);
    return sub;
}
#endif

int main(void)
{
    char *p = longestPalindrome("babad");
    printf("%s\n", p); free(p);

    p = longestPalindrome("cbbd");
    printf("%s\n", p); free(p);
    return 0;
}
