#include	<bits/stdc++.h>
#define		N	int(1e5)+7
#define		fo(i,a,b)	for(int i= a;i <= b;i++)

using		namespace	std;

int			fa[N][20],deg[N],n,m,fre[N];
vector< int > a[N];

void		readf()
{
			
			fo(i,1,n) a[i].clear();
			fo(i,1,n-1)
			{
				int t;	int u,v;
			
				
					cin>>u>>v;
					a[u].push_back(v);
					a[v].push_back(u);
				
			}
		
}

void		dfs(int u)
{
			fre[u] = true;
			fo(i,1,3)
			{
				int v = fa[u][i-1];
				if (v==0) fa[u][i]=0;
				else fa[u][i] = fa[v][i-1];
			}
			fo(i,0,a[u].size()-1)
			{
				int v = a[u][i];
				if (!fre[v])
				{
					deg[v] = deg[u] + 1;
					fa[v][0]=u;
					dfs(v);
				}
			}
}

int 		lca(int u,int v)
{
			if (deg[u] <deg[v]) 
			{
				int x =lca(v,u);
				return x;
			}
			int d=0,c=18,mid,u1;
			if (deg[u] > deg[v])
			while (d<=c)
			{
				mid=(d+c)/2;
				int x = fa[u][mid];
				if (x==0) 
				{
					c = mid-1;
					continue;
				}
				if (deg[x] == deg[v])
				{
					u = x;
					break;
				}
				if (deg[x] < deg[v]) c = mid-1;
				else u =x;
			}
			
			if (u==v) return (u);
			
			
            		int x,y;
            		int i =0;
          		 while (true)
          		 {
                		x = fa[u][i];
               			 y = fa[v][i];
                		if (x==0) continue;

                		if (x==y)
                			return x;
        
                		
                		else
                		{

                   
                    			u= x;
                    			v= y;
                		}
           		 }
}

void		solve()
{
			memset(fa,0,sizeof(fa));
			memset(fre,false,sizeof(fre));
			deg[1] = 0;
			dfs(1);
			fo(i,1,m)
			{
			
					int u,v;
					cin >>u>>v;
					int x =lca(u,v);
					cout<<x<<endl;
			}
}

main()
{
			freopen("lca.inp","r",stdin);
			freopen("lca.out","w",stdout);
			
				cin>>n>>m;
				
				readf();
				solve();
			
}
