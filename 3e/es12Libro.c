#include <stdio.h>
#include <string.h>
char mistero(char s[])
{
    char *p, *q, t;
    int n = 0;
    p = s;
    while (*p != 0)
    {
        n++;
        p++;
    }
    p = &s[0];
    q = &s[n - 1];
    while (p <= q)
    {
        t = *q;
        *q = *p;
        q--;
        *p = t;
        p++;
    }
    return (char)s;
}
int main(int argc, char *argv[])
{
    char s[100], z[100];
    int l = 0;
    printf("Inserisci una stringa\n");
    scanf("%s", s);
    l = strlen(s);
    for (int i = 0; i < l; i++)
    {
        z[i] = mistero(s);
    }
    printf("%s\n", z);
    return 0;
}