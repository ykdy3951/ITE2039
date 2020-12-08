//2019044711_김찬웅_11802
#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

int n, m;
bool graph[1005][1005];
bool vst[1005];
bool fin[1005];
bool dag;
stack<int> s;

void init()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x][y] = true;
    }
}

void dfs(int x)
{
    if (fin[x])
    {
        dag = true;
        return;
    }
    fin[x] = true;
    for (int i = 1; i <= n; i++)
    {
        if (graph[x][i] && !vst[i])
        {
            dfs(i);
        }
    }
    vst[x] = true;
    s.push(x);
}

int main(void)
{
    init();

    for (int i = 1; i <= n; i++)
    {
        if (!vst[i])
        {
            dfs(i);
        }
    }

    if (dag || s.size() != n)
    {
        printf("0\n");
        return 0;
    }

    printf("1\n");
    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
    return 0;
}