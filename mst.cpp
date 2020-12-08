//2019044711_김찬웅_11802
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int cnt;
priority_queue< pair<int, pair<int, int> > > pq;
queue< pair<int, pair<int, int> > > answer;
int parent[1005];
int ran[1005];

int find(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}


void uni(int x, int y)
{
    x = find(x), y = find(y);

    if (ran[x] < ran[y])
    {
        parent[x] = y;
    }
    else
    {
        parent[y] = x;
        if (ran[x] == ran[y])
        {
            ran[x]++;
        }
    }
}


void init()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        pq.push({-w, {-x, -y}});
    }
    for(int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }
}

void kruskal()
{
    while(!pq.empty())
    {
        if(cnt == n - 1){
            break;
        }
        int w = -pq.top().first, x = -pq.top().second.first, y = -pq.top().second.second;
        pq.pop();
        if(find(x) == find(y)){
            continue;
        }
        else{
            cnt++;    
            printf("%d %d %d\n", x, y, w);
            // q.push({x, {y, w}});
            uni(x, y);
        }
    }
}

int main(void){

    init();
    printf("%d\n", n - 1);
    kruskal();

    return 0;
}