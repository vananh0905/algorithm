#include	<bits/stdc++.h>
#define		N	10005
#define		fo(i,a,b)	for(int i= a;i<=b;i++)
#define		fi(i,a,b)	for(int i = a;i<b;i++)

using		namespace	std;

int 		n,m,low[N],num[N],kk,fa[N],fre[N],cot,sn[N],tcut[N];
vector<int>	a[N];

void		readf()
{
			cin>>n>>m;
			fo(i,1,m)
			{
				int u,v;
				cin>>u>>v;
				a[u].push_back(v);
				a[v].push_back(u);
			}
}

void		dfs(int u)
{
			fre[u] = true;
			cot++;
			num[u] = cot;
			fi(i,0,a[u].size())
			{
				int v = a[u][i];
				if (!fre[v])
				{
					fa[v] = u;
					dfs(v);
					low[u] = min(low[u],low[v]);
				}
				else
				if ((num[v] < low[u]) && (fa[u] !=v) )  low[u] = num[v];
				
			}
}

void		solve()
{
			memset(fre,false,sizeof(fre));
			fo(i,1,n)
			{
				low[i] = n+1;
				fa[i] = -1;
			}
			cot = 0;
			fo(i,1,n)
			if (fa[i] == -1) dfs(i);
			kk = 0;
			memset(sn,0,sizeof(sn));
            fo(i,1,n)
            if (fa[i] !=-1) 
                {
                        int u = fa[i];
                        sn[u]++;
            	}
            int cc=0;
 			fo(i,1,n) if (fa[i]!= -1 && low[i]>=num[i]) cc++;
            memset(tcut,false,sizeof(tcut));
            fo(i,1,n)
            if (fa[i] !=-1) 
            {
                        int u = fa[i];
                        if (low[i] >= num[u])
                                tcut[u] = tcut[u] || (sn[u] > 1) || (fa[u] !=-1);
        	}
        	fo(i,1,n)
            if (tcut[i] )kk++;
            cout<<kk<<" "<<cc<<endl;
			
}
main()
{
			freopen("khopcau.inp","r",stdin);
			freopen("khopcau.out","w",stdout);
		
				readf();
				solve();
}

