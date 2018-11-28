/*
#include<stdio.h>
#include<iostream>
#define MAX 1005

struct node{

    int u;

    int v;

    int w;

};

int f[MAX];

int count = 0, sum = 0;

struct node e[3*MAX];

void quicksort(int left,int right){

    if(left>right)

    return;

    int i = left;

    int j = right;

    struct node temp;

    while(i != j){

        while(e[j].w >= e[left].w && i<j)

            j--;

        while(e[i].w <= e[left].w && i<j )

            i++;

        if(i < j){

            temp = e[i];

            e[i] = e[j];

            e[j] = temp;

        }

    }

    temp = e[i];

    e[i] = e[left];

    e[left] = temp;

    quicksort(left, i-1);

    quicksort(i+1, right);

    return;

}

int getf(int v){

    if(f[v]==v)

    return v;

    else

    f[v] = getf(f[v]);

    return f[v];

}

int merge(int v,int u){

    int t1 = getf(v);

    int t2 = getf(u);

    if(t1 != t2){

        f[t2] = t1;

        return 1;

    }

    return 0;

}

int main()

{

    int n,m;

    scanf("%d",&n);

    scanf("%d",&m);

    for(int i = 1; i <= m; ++i){

        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);

    }

    quicksort(1, m);

    for(int i = 1; i <= n; ++i){

        f[i]=i;

    }

    for(int i = 1; i <= m; ++i){

        if(merge(e[i].u,e[i].v)){

            count++;

            sum = sum + e[i].w;

        }

        if(count == n-1)

        break;

    }

    if(count != n-1)

        printf("-1\n");

    else

        printf("%d\n",sum);

    return 0;

 }
*/

/***************************
    Kruskal�㷨��Ӧ��
***************************/
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node
{
    int u;
    int v;
    int w;

}edge[3001];//�߼�����

int f[3001];

void sqort(struct node edge[], int l, int r)
{
    int i, j;
    struct node key;
    if(l >= r)
    {
        return ;
    }

    key = edge[l];
    i = l;
    j = r;

    while(i < j)
    {
        while(i < j && edge[j].w >= key.w)
        {
            j--;
        }
        edge[i] = edge[j];
        while(i < j && edge[i].w <= key.w)
        {
            i++;
        }

        edge[j] = edge[i];
    }

    edge[j] = key;

    //���η�
    sqort(edge, l, j - 1);
    sqort(edge, j + 1, r);

}

//findx������unionx�������Կ����ҵ�CSDN���鼯�Ĳ��ͣ������������
int findx(int x)
{
    if(f[x] == x)
    {
        return x;
    }

    else
    {
        f[x] = findx(f[x]);
    }

    return f[x];
}

int unionx(int x, int y)
{
    int t1 = findx(x), t2 = findx(y);

    if(t1 != t2)
    {
        f[t2] = t1; //��t2���յ���Ϊt1;
        return 1;
    }

    else //˵��t1,t2���յ�һ����˵������������������������ͻ���γɻ�·
    {
        return 0;
    }
}

int main(void)
{
    int n, m, i, sum;
    int countx;

    while(~scanf("%d %d", &n, &m))
    {
        memset(f, 0, sizeof(f));
        countx = 0;
        sum = 0;
        for(i = 1; i <= n; i++)
        {
            f[i] = i;//�����Ҳ���ͨ��n-1���ߵ�ʱ����õ�
        }
        for(i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
        }

        //��������,��ÿ���ߵ�Ȩֵ��С����������
        sqort(edge, 1, m);


        //����findx������unionx�����ҵ�n-1���ߣ����Ҳ�������ͨ��·
        for(i = 1; i <= m; i++)
        {
            if(unionx(edge[i].u, edge[i].v))//�����벢�鼯��˼��
            {
                countx++;
                sum += edge[i].w;
            }

            if(countx == n - 1)
            {
                printf("%d\n", sum);
                break;
            }
        }

        if(countx != n - 1)
        {
            printf("-1\n");
        }

    }

    return 0;
}
