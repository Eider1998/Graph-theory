#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int visit[1001];
int a[1001][1001];
int f;

void dfs(int t, int k)
{
    visit[t] = 1;
    if(!f)//为了输出最小的顶点
    {
        cout << t;
        f = 1;
    }

    else
    {
        cout << ' ' << t;
    }
    int i;
    for(i = 0; i < k; i++)
    {
        if(!visit[i] && a[t][i])
        {
            dfs(i, k);
        }
    }
}

int main(void)
{
    int n, m, k, u, v;

    cin >> n;
    while(n--)
    {
        cin >> m >> k;
        memset(a, 0, sizeof(a));
        memset(visit, 0, sizeof(visit));
        for(int i = 0; i < m; i++)
        {
            cin >> u >> v;
            a[u][v] = a[v][u] = 1;
        }

        f = 0;
        dfs(0, k);
        cout << endl;
    }

    return 0;
}
