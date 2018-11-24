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
//���ڹ��������������һ��ֻ����1���ɣ�������������ȫ�ֱ���
//ÿ����һ��ifѭ��ȫ�ֱ����ͻ��1
//����������struct����ס�����˶��ٴ�
void bfs(int e)
{
    queue<node>q;//�����ﱣ��node����
    visit[e] = 1;
    t.num = e;
    t.step = 0;//t���������q��
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
                t.step = v.step + 1;//��ס�ۼ��˶��ٴ�
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
