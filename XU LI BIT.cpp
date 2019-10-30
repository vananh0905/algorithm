#include	<bits/stdc++.h>
#define		fo(i,a,b)	for(int i =a;i<=b;i++)

using		namespace	std;

int			n,q,k;

void		batbit(int k)
{
			n = n | (1 <<k);
}

void		offbit(int k)
{
			n = n&(~(1 <<k) );
}

void		daobit(int k)
{
			n = n^(1<<k);
}

int			getbit(int k)
{
			return ((n >>k) & 1);
}



void		solve()
{
			cin>>n>>q;
		//	cout<<n<<endl;
			fo(i,1,q)
			{
				string st;
				cin>>st>>k;
			//	cout<<st<<endl;
				if (st == "ENABLE")
				{
					batbit(k);
					cout<<n<<endl;
				}
				else 
				if (st == "DISABLE")
				{
					offbit(k);
					cout<<n<<endl;
				}
				else
				if (st== "FLIP")
				{
					daobit(k);
					cout<<n<<endl;
				}
				else
				{
					if (getbit(k)) cout<<"ON"<<endl;
					else cout<<"OFF"<<endl;
					
				}
			}
}

main()
{
		//	freopen("bitoperators.inp","r",stdin);
		//	freopen("bitoperators.out","w",stdout);
			solve();
}
