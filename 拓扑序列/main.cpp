#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int Map[1001][1001]; //����ͼ�ı�
int a[1001];//�洢����������

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
            a[v]++;//��ȼ�һ
        }
        for(i = 1; i <= n; i++)
        {
            flag = 0;//���
            for(j = 1; j <= n; j++)
            {
                if(!a[j])
                {
                    flag = 1;
                    a[j]--;//ȥ��j��
                    for(k = 1; k <= n; k++)
                    {
                        if(Map[j][k])
                        {
                            a[k]--;//��j���б����ڵľ�-1
                        }
                    }
                    break;//һ��ѭ����ȥ��һ����
                }


            }

            if(!flag)//������forѭ����û���ҵ������Ϊ0�ĵ㣬����Ժ�Ҳ�������ҵ�
            {
                break;
            }

        }



        if(flag)//��ÿ�ζ������Ϊ0����flag������1
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
