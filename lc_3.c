#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
    int max_len = 0, count = 0;
    char hash[256] = {0};
    char *start = s;

    while (*s) {
        if (hash[*s]) {
            max_len = count > max_len ? count : max_len;
            count = 0;
            memset(hash, 0, sizeof(char) * 256);
            s = start + 1;
            start = s;
        }
        else {
            count++;
            hash[*s]++;
            s++;
        }
    }

    return count > max_len ? count : max_len;
}


int lengthOfLongestSubstring2(char * s){
    int max_len = 0, count = 0;
    int hash[256];
    char *begin = s;
    char *start = s;
    memset(hash, -1, sizeof(int) * 256);

    while (*s) {
        if (hash[*s] != -1 && (begin + hash[*s] + 1) >= start) {
            max_len = count > max_len ? count : max_len;
            start = begin + hash[*s] + 1;
            count = s - start;
            hash[*s] = -1;
        }
        else {
            count++;
            hash[*s] = s - begin;
            s++;
        }
    }

    return count > max_len ? count : max_len;
}

void main()
{
    char *a = "abcabcbb";
    char *b = "bbbbb";
    char *c = "pwwkew";
    char *d = "dvdf";
    char *e = "eabeefc";
    char *f = "eabcade";
    printf("%d\n", lengthOfLongestSubstring2(a));
    printf("%d\n", lengthOfLongestSubstring2(b));
    printf("%d\n", lengthOfLongestSubstring2(c));
    printf("%d\n", lengthOfLongestSubstring2(d));
    printf("%d\n", lengthOfLongestSubstring2(e));
    printf("%d\n", lengthOfLongestSubstring2(f));
}
