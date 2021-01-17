#include <string.h>
#include <stdio.h>

int romanChar(char c)
{
    switch (c) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    }
    return 0;
}

int checkNext(char c, char next)
{
    int ok = 0;
    if (c == 'I' && (next == 'V' || next == 'X'))
        ok = 1;
    else if (c == 'X' && (next == 'L' || next == 'C'))
        ok = 1;
    else if (c == 'C' && (next == 'D' || next == 'M'))
        ok = 1;
    return ok;
    if (ok)
        return romanChar(next) - romanChar(c);
    else
        return romanChar(c) + romanChar(next);
}

int romanToInt(char * s) {
    int len = strlen(s);
    int i, sum = 0;

    for (i = 0; i < len; ) {
        if (i + 1 < len){
            if (checkNext(s[i], s[i + 1])) {
                sum += (romanChar(s[i + 1]) - romanChar(s[i]));
                i += 2;
            } else {
                sum += romanChar(s[i]);
                i++;
            }
        } else{
            sum += romanChar(s[i]);
            i++;
        }
    }
    return sum;
}


int main(int argc, char const *argv[])
{
    printf("%d\n", romanToInt("LVIII"));
    return 0;
}