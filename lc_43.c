#include <stdio.h>
#include <string.h>
#include <malloc.h>

char * multiply(char * num1, char * num2){
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int size = len1 + len2;
    int i, j;

    int *value = (int *)malloc(sizeof(int) * size);
    memset(value, 0, sizeof(int) * size);

    char *result = (char *)malloc(size + 1);
    memset(result, 0, size+1);

    for (i = len1 - 1; i >= 0; i--) {
        for (j = len2 - 1; j >= 0; j--) {
            value[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }

    for (i = size - 1; i > 0; i--) {
        value[i-1] += value[i] / 10;
        value[i] %= 10;
    }

    i = 0; j = 0;
    while (value[i] == 0 && i < size - 1)
        i++;
    while (i < size)
        result[j++] = value[i++] + '0';
    result[j] = '\0';

    free(value);
    return result;
}

int main(int argc, char const *argv[])
{
    char *p = multiply("123", "456");
    printf("%s\n", p);
    free(p);
    return 0;
}