#include	<bits/stdc++.h>
#define		N	505
#define		fi	first
#define		se	second
#define		pa	pair<int,int>
#define		fo(i,a,b)	for(int i= a;i <= b;i++)
#define		oo	int(1e9)

using		namespace	std;

int			fre[N],d[N],n,t,m,di[N],sum,res;
vector < pa > a[N] ;
priority_queue <pa,vector<pa>,greater<pa> > q;

void		readf()
{
			cin >>n>>t>>m;
			fo(i,1,t) cin >>di[i];
			fo(i,1,m)
			{
				int u,v,c;
				cin >> u>>v>>c;
				a[u].push_back(pa(c,v));
				a[v].push_back(pa(c,u));
			}
}

void		dijkstra(int uu)
{
			fo(i,1,n) d[i] = oo;
			memset(fre,false,sizeof(fre));
			d[uu] = 0;
			
			q.push(pa(d[uu],uu));
			while (!q.empty())
			{
				int u,v,w;
				u = q.top().se; w = q.top().fi;
				fre[u] = true;
				 q.pop();
				fo(i,0,a[u].size()-1)
				
				{
					v = a[u][i].se;
					if (fre[v]) continue;
					if (d[v] > w+ a[u][i].fi)
					{
						d[v] = w+ a[u][i].fi;
						q.push(pa(d[v],v));
					}
				}
			}
}

void		solve()
{
			sum = oo;
			res =0;
			fo(i,1,n)
			{
				int k=0;
				dijkstra(i);
				fo(j,1,t) k +=d[di[j]];
				//cout<<i<<" "<<sum<<endl;
				if (k < sum)
				{
					sum = k;
					res = i;
				}
			}
			cout <<res;
}

main()
{
		//	freopen("bestspot.inp","r",stdin);
		//	freopen("bestspot.out","w",stdout);
			readf();
			solve();
			
}
