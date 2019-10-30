#include      <bits/stdc++.h>
#define         N   int(1e6)+7
#define       fo(i,a,b) for(int i=a;i<=b;++i)
#define       fd(i,a,b) for(int i=a;i>=b;--i)

using           namespace   std;

int         mi[N][22],ma[N][22],n,res,a[N],t;

void        readf()
{
            cin>>n>>t;
            fo(i,1,n) cin>>a[i];
}

void        init()
{
            fo(i,1,n)
            {
                ma[i][0] =a[i];
                mi[i][0] =a[i];
            }
            for(int j=1;j<=20;j++)
            for(int i=1;i+(1<<j)-1<=n;i++)
            {
                mi[i][j] = min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
                ma[i][j] =max(ma[i][j-1],ma[i+(1<<(j-1))][j-1]);
            }
}

int         getmi(int ii,int l)
{
            int k = __lg(l);
            int x= min(mi[ii][k],mi[ii+l-(1<<k)][k]);
            return x;
}

int         getma(int ii,int l)
{
            int k = __lg(l);
            int x= max(ma[ii][k],ma[ii+l-(1<<k)][k]);
            return x;
}

int        check(int l)
{
            fo(i,1,n-l+1)
            {
                int x= getmi(i,l);
                int y = getma(i,l);

                if (y-x<=t)
                    return true;
            }
            return false;
}

void        solve()
{
            res= 0;
            init();
            int d,c,mid;
            d=1;
            c=n;
            while(d<=c)
            {
                mid = (d+c)/2;
                if (check(mid))
                {
                    res= mid;
                    d= mid+1;
                }
                else c=mid-1;
            };
            cout<<res;
}

main()
{
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            freopen("game.inp","r",stdin);
            freopen("game.out","w",stdout);
            readf();
            solve();
}
