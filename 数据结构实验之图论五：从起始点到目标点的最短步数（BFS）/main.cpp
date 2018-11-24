#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int n, visit[1001];
int a[1001][1001];

struct node
{
    int num;
    int step;
}t, v;
//由于广度优先搜索遍历一次只增加1即可，但是如果定义个全局变量
//每进入一次if循环全局变量就会加1
//所以现在用struct来记住，加了多少次
void bfs(int e)
{
    queue<node>q;//队列里保存node类型
    visit[e] = 1;
    t.num = e;
    t.step = 0;//t来进入队列q中
    v.step = 0;
    q.push(t);
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        if(v.num == 1)
        {
            printf("%d\n", v.step);
            return ;
        }

        for(int i = 1; i <= n; i++)
        {
            if(!visit[i] && a[v.num][i])
            {
                visit[i] = 1;
                t.step = v.step + 1;//记住累加了多少次
                t.num = i;
                q.push(t);
            }
        }
     }
     printf("NO\n");
}

int main(void)
{
    int u, v, m;
    while(~scanf("%d %d", &n, &m))
    {
        memset(visit, 0, sizeof(visit));
        memset(a, 0, sizeof(a));

        while(m--)
        {
            cin >> u >> v;
            a[u][v] = 1;
        }

        bfs(n);
    }

    return 0;
}
