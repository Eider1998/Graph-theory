#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int visit[1001], a[1001][1001];
int s, j, path[1001];
//j������¼�����˶���·������path���鱣���߹��ĵ�
void bfs(int t, int n)
{
    visit[t] = 1;//�߹��ĵ�Ͳ���������
    for(int i = 1; i <= n; i++)
    {
        if(!visit[i] && a[t][i])
        {
            j++;
            path[j] = i;
            bfs(i, n);//�ݹ����
            j++;
            path[j] = t;//�����ⲽ��˵���Ѿ�������һ���ˣ���Ҫ����ȥ���¿�ʼ

        }
    }
}

int main(void)
{
    int t, m, n, i, flag;
    int u, v;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &n, &m, &s);
        flag = 1;
        memset(visit, 0, sizeof(visit));
        memset(a, 0, sizeof(a));
        for(i = 0; i < m; i++)
        {
            cin >> u >> v;
            a[u][v] = a[v][u] = 1;
        }
        j = 0;
        path[j] = s;
      //  j++;
        bfs(s, n);
        for(i = 1; i <= n; i++)//����ǲ��Ƕ�����
        {
            if(!visit[i])
            {
                flag = 0;
                break;
            }
        }

        if(!flag)//���û�ж����������Ҫ��0
        {
            for(i = 0; i <= j; i++)
            {
                if(i == 0)
                {
                    printf("%d", path[i]);
                }

                else
                {
                    printf(" %d", path[i]);
                }
            }

            printf(" 0\n");
        }

        else
        {
            for(i = 0; i <= j; i++)
            {
                if(i == 0)
                {
                    printf("%d", path[i]);
                }

                else
                {
                    printf(" %d", path[i]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
