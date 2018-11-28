#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f //�����

struct node
{
    int L;
    int W;
}Map[3001][3001];//�ڽӾ���

int path[3001][3001]; //��¼�����ǰ��������ʲô
int D[3001][3001];    //��¼����֮�����·������
int weight[3001][3001]; //��¼����֮�������շ�

void floyed(int n, int s, int d)
{
    int i, j, k;
    for(i = 0; i < n; i++)//��ʼ��D���飬path���飬weight����
    {
        for(j = 0; j < n; j++)
        {
            D[i][j] = Map[i][j].L;
            path[i][j] = i;
            weight[i][j] = Map[i][j].W;
        }
    }

    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(D[i][j] > D[i][k] + D[k][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    weight[i][j] = Map[i][k].W + Map[k][j].W;
                    path[i][j] = k;
                }

                else if(D[i][j] == D[i][k] + D[k][j])
                {
                    if(weight[i][j] > weight[i][k] + weight[k][j])//�����·����ͬ����ôȡ�����ٵ�
                    {
                        weight[i][j] = weight[i][k] + weight[k][j];
                        path[i][j] = k;
                    }
                }
            }
        }
    }

    cout << D[s][d] << ' ' << weight[s][d] << endl;
}

int main(void)
{
    int t, n, m, s, d;
    int u, v, l, w;
    int i, j;

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> s >> d;
        for(i = 0; i < 3001; i++)//��ʼ��
        {
            for(j = 0; j < 3001; j++)
            {
                Map[i][j].L = Map[i][j].W = INF;
            }
        }
        while(m--)
        {
            cin >> u >> v >> l >> w;
            Map[u][v].L = Map[v][u].L = l;
            Map[u][v].W = Map[v][u].W = w;
        }
        floyed(n, s, d);
    }

    return 0;
}
