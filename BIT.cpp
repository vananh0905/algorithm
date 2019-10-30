#include    <bits/stdc++.h>
#define     N   6*int(1e4)+7
#define     fo(i,a,b)   for(int i=a;i<=b;++i)
#define     fd(i,a,b)   for(int i=a;i>=b;--i)

using       namespace std;

int         a[N],t[N],n,res;

void        readf()
{
            cin>>n;
            fo(i,1,n) cin>>a[i];
}

void        findd(int x)
{
            if (x > N) return;
            res +=t[x];
            x += x&(-x);
            findd(x);
}

void        update(int x)
{
            if (x<=0) return ;
            t[x] ++;
            x-= x&(-x);
            update(x);
}

void        solve()
{
            res= 0;
            memset(t,0,sizeof(t));
            fo(i,1,n)
            {
                findd(a[i] + 1);
                update(a[i]);
            }
            cout<<res;
}

main()
{
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
         //   freopen("nkinv.inp","r",stdin);
         //   freopen("nkinv.out","w",stdout);
            readf();
            solve();
}
