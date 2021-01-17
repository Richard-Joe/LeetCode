#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>

int myAtoi(char * str) {
    if (!str || *str == 0)
        return 0;

    long res = 0, old_res = 0;
    int i = 0, minus = 1;
    int len = strlen(str);

    while (str[i] == ' ') i++;
    if (str[i] == '-') minus = -1;
    if (str[i] == '-' || str[i] == '+') i++;

    for (; i < len && isdigit(str[i]); i++) {
        old_res = res;
        res = res * 10 + str[i] - '0';
        if (res >= INT_MAX && minus == 1) return  INT_MAX;
        else if (res > INT_MAX && minus == -1) return  INT_MIN;
    }
    return res * minus;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", myAtoi("2147483646"));
    return 0;
}