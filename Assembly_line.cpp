//2019044711_김찬웅_11802
#include <stdio.h>

int n;

int e[3];
int x[3];
int a[3][101];
int t[3][101];
int l_index;
int s[3][101];
int l[3][101];

void init()
{
    scanf("%d", &n);
    scanf("%d %d", &e[1], &e[2]);
    scanf("%d %d", &x[1], &x[2]);
    for (int j = 1; j <= 2; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[j][i]);
        }
    }
    for (int j = 1; j <= 2; j++)
    {
        for (int i = 1; i < n; i++)
        {
            scanf("%d", &t[j][i]);
        }
    }
}

void assembly_line()
{
    s[1][1] = e[1] + a[1][1];
    s[2][1] = e[2] + a[2][1];
    for (int j = 2; j <= n; j++)
    {
        if (s[1][j - 1] <= s[2][j - 1] + t[2][j - 1])
        {
            s[1][j] = s[1][j - 1] + a[1][j];
            l[1][j] = 1;
        }
        else
        {
            s[1][j] = s[2][j - 1] + t[2][j - 1] + a[1][j];
            l[1][j] = 2;
        }
        if (s[2][j - 1] <= s[1][j - 1] + t[1][j - 1])
        {
            s[2][j] = s[2][j - 1] + a[2][j];
            l[2][j] = 2;
        }
        else
        {
            s[2][j] = s[1][j - 1] + t[1][j - 1] + a[2][j];
            l[2][j] = 1;
        }
    }
    if (s[1][n] + x[1] <= s[2][n] + x[2])
    {
        printf("%d\n", s[1][n] + x[1]);
        l_index = 1;
    }
    else
    {
        printf("%d\n", s[2][n] + x[2]);
        l_index = 2;
    }
}

void print_stations(int index, int n)
{
    if (n == 0)
        return;
    print_stations(l[index][n], n - 1);
    printf("%d %d\n", index, n);
}

int main()
{
    init();
    assembly_line();
    print_stations(l_index, n);
    return 0;
}