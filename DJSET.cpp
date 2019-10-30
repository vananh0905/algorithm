#include	<bits/stdc++.h>
#define		N	int(1e5)+2
#define		fo(i,a,b)	for(int i = a;i <= b;i++)

using		namespace	std;

int			n,m,res,sd[N],fa[N];

void		init()
{
			cin >>n>>m;
			fo(i,1,n)
			{
				fa[i] = -1;
				sd[i] = 1;
			}
}

int			getroot(int u)
{
			while (fa[u] != -1)
			{
				u = fa[u];
			}
			return u;
}

void		hopnhat(int u,int v)
{
			int x= sd[u] + sd[v];
			
			if (sd[u] > sd[v])
			{
				fa[v] = u;
				sd[u] = x;
			}
			else
			{
				fa[u] = v;
				sd[v] = x;
			}
}

void		solve()
{
			res = 0;
			fo(i,1,m)
			{
				int u,v,x,y;
				cin >>u >>v;
				x = getroot(u);
				y = getroot(v);
				if (x!=y)
				{
					res += sd[x]*sd[y];
					hopnhat(x,y);
					
				}
			}
			
			cout <<res;
}

main()
{
			freopen("itf.inp","r",stdin);
			freopen("itf.out","w",stdout);
			init();
			solve();
}
