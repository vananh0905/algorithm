#include	<bits/stdc++.h>
#define		N	int(1e5)+7
#define		fo(i,a,b)	for(int i= a;i<=b;i++)
#define		ll	long long

using		namespace	std;

ll			poww[N],hasha[N],hashb[N];
ll			base= 1e9+7;
string		a,b;
int			n,m;

void		init()
{
			n= a.length();
			m = b.length();
			a = ' '+a;
			b = ' '+b;
			poww[0] = 1;
			fo(i,1,N-7) 
				poww[i] = (poww[i-1]*26)%base;
			hasha[0]= 0;
			hashb[0] = 0;
			fo(i,1,n) hasha[i] = ((hasha[i-1]*26) + int(a[i]) -'a' )%base;
			fo(i,1,m) hashb[i] = ((hashb[i-1]*26) + int(b[i]) - 'a')%base;
}

bool		check(int i,int l)
{
			ll x,y;
			x =( (hasha[n] - poww[l]*hasha[i-1]) + base*base)%base;
			y = (hashb[l] + base*base)%base;
		//	if (i== 3) cout <<x<<" "<<y;
			if (x!=y) return false;
			return true;
			
}

void		solve()
{
			init();
			int dd= n;
			fo(i,1,n)
			{
				int l= n-i+1;
				if (l>m) continue;
				if (check(i,l)) 
				{
					dd = i;
					break;
				}
			}
			fo(i,1,dd-1) cout<<a[i];
			fo(i,1,m)cout<<b[i];
} 

main()
{
		//	freopen("c11str2.inp","r",stdin);
		//	freopen("c11str2.out","w",stdout);
			cin >>a;
			cin>>b;
			solve();
}
