#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int Map[1001][1001]; //有向图的边
int a[1001];//存储各顶点的入度

int main(void)
{
    int n, m, u, v;
    int i, j, k;

    while(~scanf("%d %d", &n, &m))
    {
        memset(Map, 0, sizeof(Map));
        memset(a, 0, sizeof(a));
        int flag = 0;

        for(i = 0; i < m; i++)
        {
            cin >> u >> v;
            Map[u][v] = 1;
            a[v]++;//入度加一
        }
        for(i = 1; i <= n; i++)
        {
            flag = 0;//标记
            for(j = 1; j <= n; j++)
            {
                if(!a[j])
                {
                    flag = 1;
                    a[j]--;//去掉j点
                    for(k = 1; k <= n; k++)
                    {
                        if(Map[j][k])
                        {
                            a[k]--;//和j点有边相邻的就-1
                        }
                    }
                    break;//一次循环就去掉一个点
                }


            }

            if(!flag)//在整个for循环都没有找到，入度为0的点，因此以后也不可能找到
            {
                break;
            }

        }



        if(flag)//若每次都有入度为0，则flag最后就是1
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
