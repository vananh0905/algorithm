#include    <bits/stdc++.h>
#define     N   int(1e5)+7
#define     fo(i,a,b)   for(int i=a;i<=b;++i)
#define     foo(i,a,b)   for(int i=a;i<b;++i)
#define     fd(i,a,b)   for(int i=a;i>=b;--i)
#define     oo     1000000007
#define     ll long long

using       namespace   std;

int         n,m,c[N],kq1,ok[N],low[N],num[N],tt,tp,fa[N];
int         mitp[N];
ll          kq2,sl[N];
stack<int> st;
vector<int> a[N];

void        readf()
{
            cin>>n;
            fo(i,1,n) cin>>c[i];
            cin>>m;
            fo(i,1,m)
            {
                int u,v;
                cin>>u>>v;
                a[u].push_back(v);
            }
}

void        dfs(int u)
{
            tt++;
            num[u] = tt;
            low[u] = tt;
            st.push(u);
            foo(i,0,a[u].size())
            {
                int v =a[u][i];
                if (!ok[v])
                {
                    if (num[v] == 0)
                    {
			fa[v]= u;
                        dfs(v);
                        low[u] = min(low[u],low[v]);
                    }
                    else if (fa[u]!=v) low[u] =min(low[u],num[v]);
                }
            }
            if (low[u]==num[u])
            {
                tp++;
                sl[tp]= 0;
                while(true)
                {
                    int v= st.top();
                    st.pop();
                    sl[tp] ++;
		    num[v] = low[v] = N*N;
                    if (v==u) break;
                }
            }

}

void        solve()
{
            memset(ok,false,sizeof(ok));
            memset(num,0,sizeof(num));
            tt= 0;tp=0;
            fo(i,1,n)
            if (num[i]==0)
            {
                dfs(i);
            }
            kq1=0;
            fo(i,1,tp) kq1+= mitp[i];
            kq2=1;
            fo(i,1,tp) kq2= (kq2*sl[i])%oo;
            cout<<kq1<<" "<<kq2;
}

main()
{
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            freopen("police.inp","r",stdin);
            freopen("police.out","w",stdout);
            readf();
            solve();
}

