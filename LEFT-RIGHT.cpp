#include    <bits/stdc++.h>
#define     N   int(1e3)+7
#define     fo(i,a,b)   for(int i=a;i<=b;i++)
#define     ll  long long

using       namespace   std;

ll      a[N][N],h[N],d[N],res,l[N];
int       n,m,r[N];

void        readf()
{
            cin>>n>>m;
            fo(i,1,n)
            {
                string st;
                cin>>st;
                fo(j,0,m-1)
                if (st[j]=='0')a[i][j+1]= 0;
                else a[i][j+1] = 1;
            }
}

void        solve()
{
            memset(h,0,sizeof(h));
            memset(d,0,sizeof(d));
            res =0;
          
            fo(i,1,n)
            {
                fo(j,1,m)
                if (a[i][j]==1)
                {
                    l[j] = j-1;
                    h[j] ++;
                    while(l[j]>0 && h[l[j]] >h[j] ) l[j] =l[l[j]];
                    d[j] = (j-l[j])*h[j] + d[l[j]];
                    res +=d[j];
                 //   cout<<i<<" "<<j<<" "<<d[j]<<endl;
                   // if (i == 2 && j ==3) cout<<l[j]<<endl;
                }
                else
                {
                    d[j] = 0;
                    h[j] =0;
                    l[j] = 0; r[j] = 0;
                }
            }
            cout<<res;
}

main()
{
     //   freopen("crec01.inp","r",stdin);
       // freopen("crec01.out","w",stdout);
        readf();
        solve();
}

//------------

	fo(i,1,n)
	{
		l[i] = i-1;
		while (l[i]>=1 && a[l[i]]<a[i]) l[i]= l[l[i]];

	}
	fd(i,n,1)
	{
		r[i] = n+1;
		while(r[i]<=n && a[r[i]]<a[i]) r[i]=r[r[i]];
	}
	l,r cua a[i] la l[i]+1,r[i]-1;


















