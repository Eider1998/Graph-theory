#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int f[10001];
struct node
{
    int L, W, R;
} Map[10001], key, t;

void qs(struct node Map[],int l, int r)

{

    int i = l, j = r;

    key = Map[l];

    if(l >= r) return ;

    while(i < j)

    {

        while(i < j && Map[j].W >= key.W) j--;

        Map[i] = Map[j];

        while(i < j && Map[i].W <= key.W) i++;

        Map[j] = Map[i];

    }

    Map[i] = key;

    qs(Map, l, i-1);

    qs(Map, i+1, r);

}

int findx(int x)
{
    if(f[x] == x)
    {
        return x;
    }

    else{
    f[x] = findx(f[x]);
    return f[x];}

}

int unionx(int x, int y)
{
    int t1 = findx(x), t2 = findx(y);
    if(t1 != t2)
    {
        f[t2] = t1;
        return 1;
    }

    return 0;
}

int main(void)
{
    int n, m, a, b, c;
    int i, countx, sum, j;

    while(~scanf("%d %d", &n, &m))
    {
        memset(Map, 0, sizeof(Map));
        countx = 0;
        sum = 0;
        for(i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            Map[i].L = a;
            Map[i].R = b;
            Map[i].W = c;
        }

        for(i = 0; i < m - 1; i++)
        {
            for(j = 0; j < m - 1 - i; j++)
            {
                if(Map[j].W > Map[j + 1].W)
                {
                    t = Map[j];
                    Map[j] = Map[j + 1];
                    Map[j + 1] = t;
                }
            }
        }
       // qs(Map, 0, m - 1);

        for(i = 1; i <= n; i++)
        {
            f[i] = i;
        }


            for(i = 0; i < m; i++)
            {
                if(countx == n - 1)
                {
                    break;
                }
                if(unionx(Map[i].L, Map[i].R))
                {
                    sum += Map[i].W;
                    countx++;
                }
            }

            printf("%d\n", sum);
        }



    return 0;
}
