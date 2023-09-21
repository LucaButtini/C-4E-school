#include <stdio.h>
int main(int argc, char *argv[])
{
    return 0;
}
int mistero(int n, const float v[])
{
    float *p;
    int q = 0;

    for (p = v; (p - v) < n; p++)
    {
        if (*p < 0)
        {
            q++;
        }
        return q;
    }
}