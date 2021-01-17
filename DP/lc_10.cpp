#include <stdio.h>
#include <string.h>

bool isMatch(char * s, char * p){
    if (!*p) return !*s;
    bool first_match = *s && (*s == *p || *p == '.');
    if (*(p+1) == '*') {
        return isMatch(s, p+2) || (first_match && isMatch(++s, p));
    }
    else {
        return first_match && isMatch(++s, ++p);
    }
}


int main(void)
{
    printf("%d\n", isMatch("aa", "a"));
    printf("%d\n", isMatch("aa", "a*"));
    printf("%d\n", isMatch("ab", ".*"));
    printf("%d\n", isMatch("aab", "c*a*b"));
    printf("%d\n", isMatch("mississippi", "mis*is*p*."));
    printf("%d\n", isMatch("mississippi", "mis*is*ip*."));
    printf("%d\n", isMatch("ippi", "ip*."));
    printf("%d\n", isMatch("ab", ".*c"));
    printf("%d\n", isMatch("aaa", "a*a"));

    return 0;
}