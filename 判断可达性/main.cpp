#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int k;
int visit[1001];
int a[1001][1001];

void dfs(int n)
{
    visit[n] = 1;

    for(int i = 0; i < k; i++)
    {
        if(!visit[i] && a[n][i])
        {
            a[n][i] = 0;
            dfs(i);
        }
    }

}

int main(void)
{
    int m, u, v;

    while(~scanf("%d %d", &k, &m))
    {
        memset(visit, 0, sizeof(visit));
        memset(a, 0, sizeof(a));

        for(int i = 0; i < m; i++)
        {
            cin >> u >> v;
            a[u][v] = 1;
        }

        dfs(k);

        if(visit[1])
        {
            printf("YES\n");
        }

        else
        {
            printf("NO\n");
        }
    }

    return 0;
}
