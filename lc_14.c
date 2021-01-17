#include <stdio.h>
#include <string.h>

char * longestCommonPrefix(char strs[][10], int strsSize) {
    if (strsSize == 0)
        return "";

    int i, j;
    int len = strlen(strs[0]);

    for (i = 0; i < len; i++) {
        for (j = 0; j < strsSize; j++) {
            //printf("%c\n", strs[j][i]);
            if (strs[0][i] != strs[j][i]) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }

    return strs[0];
}

char strs[3][10] = {
    "flower","flow","flight"
};

int main(int argc, char const *argv[])
{
    printf("%s\n", longestCommonPrefix(strs, 3));
    return 0;
}