#include    <bits/stdc++.h>
#define     N   int(1e6)+7
#define     fo(i,a,b)   for(int i=a;i<=b;++i)
#define     foo(i,a,b)   for(int i=a;i<b;++i)
#define     fd(i,a,b)   for(int i=a;i>=b;--i)
#define     task "oke"
#define     pb  push_back
#define     reset(ok,a) memset(ok,a,sizeof(ok))

using       namespace std;

int         n,m,match[N],ri[N],le[N],res,ok;
vector<int> a[N];

void        readf()
{
            cin>>n>>m;
            int u,v;
            while (cin>>u>>v)
            {
                a[u].pb(v);
            }
}

void        doighep(int v)
{
            while(v !=0)
            {
                int u = match[v];
                int v2=le[u];
                le[u] = v; ri[v] = u;
                v= v2;
            }
}

void        ghep(int u)
{
            if (ok) return;
            foo(i,0,a[u].size())
            {
                int v= a[u][i];
                if (match[v]==0)
                {
                    match[v] = u;
                    if (ri[v]==0)
                    {
                        doighep(v);
                        ok = true;
                        return;
                    }
                    ghep(ri[v]);
                    if (ok) return;

                }
            }
}

void        solve()
{
            reset(match,0);
            reset(le,0);
            reset(ri,0);
            res=0;
            fo(i,1,n)
            {
                ok =false;
                reset(match,0);
                ghep(i);
                if (le[i]!=0) res++;
            }
            cout<<res;
}

main()
{
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            freopen(task".inp","r",stdin);
            freopen(task".out","w",stdout);
            readf();
            solve();
}
