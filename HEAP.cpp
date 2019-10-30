#include	<bits/stdc++.h>
#define		N	int(1e5)+7
#define		fo(i,a,b)	for(int i =a; i<=b; i++)


using		namespace	std;

int			n,k;
priority_queue <int> heap;
string		st;

void		solve()
{		

			cin >>n;
			fo(i,1,n)
			{
					cin >> st;
					if (st == "A") {
						cin >>k;
						heap.push(k);
					}
					else
					{
						if (heap.empty()) {
							cout <<-1 <<endl;
							continue;
						}
						int t = 1;
						int gt = heap.top(); heap.pop();
						while (! heap.empty())
						{
							if (heap.top() == gt) {
								heap.pop();
								t++;
							}
							else break;
						}
						cout << gt <<" " <<t <<endl;
					}
			}
			int dd =0;
			while (!heap.empty())
			{
				dd =1;
				cout <<heap.top()<<" ";
				heap.pop();
			}
			if(dd == 0) cout <<-1<<endl;
}

main()
{
		//	freopen("cards.inp","r",stdin);
		//	freopen("cards.out","w",stdout);
			ios::sync_with_stdio(0);
			cin.tie(0);
			cout.tie(0);
			solve();
}

