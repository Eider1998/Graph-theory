#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

struct node
{
    int u, v, w;
}edge[50001];

int ans, path[50001], in[50001], dis[50001];//数组开小，也会造成TLE
//dis数组记录走的最大路径，path数组记录路径，in数组入度大小

void bellman(int n, int m)
{
    int i, j, flag;

    for(j = 1; j < n; j++)//进行n-1次求值即可
    {
        flag = 0;
        for(i = 1; i <= m; i++)
        {
            if((dis[edge[i].u] < dis[edge[i].v] + edge[i].w) || (dis[edge[i].u] == dis[edge[i].v] + edge[i].w && edge[i].v < path[edge[i].u]))
            {
                dis[edge[i].u] = dis[edge[i].v] + edge[i].w;
                path[edge[i].u] = edge[i].v;
                flag = 1;
            }
        }

        if(!flag)
        {
            break;
        }
    }

    int k = ans;
    cout << dis[ans] << endl;
    while(path[k] != 0)
    {
        cout << k << " " << path[k] << endl;
        k = path[k];
    }
}

int main(void)
{
    int i;
    int sv, ev, x;
    int m, n;

    while(~scanf("%d %d", &n, &m))
    {
        //初始化
        memset(path, 0, sizeof(path));
        memset(in, 0, sizeof(in));
        memset(dis, 0, sizeof(dis));
        memset(edge, 0, sizeof(edge));

        for(i = 1; i <= m; i++)
        {
            cin >> sv >> ev >> x;
            edge[i].u = sv;
            edge[i].v = ev;
            edge[i].w = x;
            in[ev]++;
        }

        for(i = 1; i <= n; i++)
        {
            if(!in[i])
            {
                ans = i;//找到入度为0的
            }
        }

        bellman(n, m);
    }

    return 0;
}
