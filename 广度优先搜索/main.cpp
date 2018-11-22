#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int a[101][101], visit[120];

void bfs(int t, int k)
{
     queue<int>q;
	 visit[t] = 1;
	 q.push(t);
	 cout << t;
     int i;
	 while(!q.empty())
	 {
         int x = q.front();
		 q.pop();
         for(i = 0; i < k; i++)
		 {
//			 int x = q.front();
//			 q.pop();
			 if(a[x][i] == 1 && visit[i] == 0)
			 {
				 q.push(a[x][i]);
				 visit[i] = 1;
				 cout << " " << i;
			 }
		 }
	 }

	 printf("\n");
}

int main(void)
{
    int n, k, m, t;
    int i, v, u;
    scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d %d", &k, &m, &t);
		memset(a, 0, sizeof(0));
		memset(visit, 0, sizeof(0));
        for(i = 0; i < m; i++)
		{
			scanf("%d %d", &u, &v);
			a[u][v] = 1;
			a[v][u] = 1;
		}

   //		visit[t] = 1;
		bfs(t, k);
	}

	return 0;
}

