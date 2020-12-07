//2019044711_김찬웅_11802
#include <stdio.h>
#include <vector>

using namespace std;

int n, m;
int arr[1005];
int A[1005];
bool chk[1005];
vector<int> v;

int find(int x)
{
    if (arr[x] == x)
        return x;
    else
    {
        return arr[x] = find(arr[x]);
    }
}

void uni(int x, int y)
{
    int fx = find(x), fy = find(y);

    if (fx == fy)
        return;

    if (A[fx] < A[fy])
    {
        arr[fx] = fy;
    }
    else
    {
        arr[fy] = fx;
        if (A[fx] == A[fy])
        {
            A[fx]++;
        }
    }
}

void init()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        A[i] = 0;
        arr[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        uni(x, y);
    }
}

int main(void)
{
    int ans = 0;
    init();
    for (int i = 1; i <= n; i++)
    {
        int f = find(i);
        if (!chk[f])
        {
            ans++;
            chk[f] = true;
        }
    }
    printf("%d\n", ans);
    return 0;
}