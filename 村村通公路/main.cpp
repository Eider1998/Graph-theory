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
    Kruskal算法的应用
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

}edge[3001];//边集数组

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

    //分治法
    sqort(edge, l, j - 1);
    sqort(edge, j + 1, r);

}

//findx函数与unionx函数可以看看我的CSDN并查集的博客，更有利于理解
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
        f[t2] = t1; //将t2的终点设为t1;
        return 1;
    }

    else //说明t1,t2的终点一样就说明如果将这两个点连接起来就会才形成回路
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
            f[i] = i;//将来找不连通的n-1条边的时候会用到
        }
        for(i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
        }

        //快速排序,将每条边的权值由小到大排起来
        sqort(edge, 1, m);


        //利用findx函数和unionx函数找到n-1条边，并且不构成连通回路
        for(i = 1; i <= m; i++)
        {
            if(unionx(edge[i].u, edge[i].v))//类似与并查集的思想
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
