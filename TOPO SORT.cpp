#include      <bits/stdc++.h>
#define         N       int(1e6)+7
#define       fo(i,a,b) for(int i=a;i<=b;++i)
#define       foo(i,a,b) for(int i=a;i<b;++i)
#define       fd(i,a,b) for(int i=a;i>=b;--i)
#define         ii pair<int,int>

using           namespace   std;

priority_queue<int > q;
int         n,m,deg[N],fre[N],ok[N],maxa;
vector<int> a[N];
int          res[N];

void        readf()
{
            memset(deg,0,sizeof(deg));
            memset(ok,false,sizeof(ok));
            cin>>m;
            maxa=0;
            fo(i,1,m)
            {
                int k;
                cin>>k;
                int dau;
                cin>>dau;
                ok[dau] = true;
                maxa=max(maxa,dau);
                fo(j,2,k)
                {
                    int u;
                    cin>>u;
                    a[dau].push_back(u);
                    deg[u]++;
                    dau= u;
                    ok[u]= true;
                    maxa=max(maxa,dau);

                }
            }
}

void        solve()
{
            fo(i,1,maxa)
            if (deg[i] ==0) q.push(-i);
            int dem= 0;

            while (!q.empty())
            {
                int u =-q.top();

                q.pop();

                res[++dem]= u;
                foo(i,0,a[u].size())
                {
                    int v= a[u][i];
                    deg[v]--;
                    if (deg[v] ==0) q.push(-v);
                }

            }

            fo(i,1,maxa)
            {
                cout<<res[i]<<" ";
            }
}

main()
{
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
          //  freopen("vosseq.inp","r",stdin);
          //  freopen("vosseq.out","w",stdout);
            readf();
            solve();
}
