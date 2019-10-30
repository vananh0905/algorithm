#include    <bits/stdc++.h>
#define     N   int(1e6)+7
#define     fo(i,a,b)   for(int i=a;i<=b;++i)
#define     fd(i,a,b)   for(int i=a;i>=b;--i)
#define     base 100003
#define     ll long long

using       namespace std;

ll          gt[N],m,n;
int         test;
vector<int> mm;
vector<int>nn;


ll          poww(ll a,ll n)
{
            if (n == 0) return 1;
            if(n==1) return a;
            ll tmp= poww(a,n/2);
            tmp = (tmp*tmp)%base;
            if (n%2==1) tmp = (tmp*a)%base;
            return tmp;
}

ll         binpow(ll a, int n) {
            long long res = 1;
            while (n > 0) {
            if (n % 2 != 0) {
                res = (res * a) % base;
                }
            a = ((long long)a * a) % base;
            n /= 2;
            }
            return res;
}

ll          tinh(int m, int n)
{
            ll tmp= 1;
            if (n>m) return 0;

            tmp = ((gt[m]*poww(gt[m-n],base-2)%base)*poww(gt[n],base-2))%base;
            return tmp;
}

void        init()
{
            mm.clear();
            nn.clear();
            while (m >0)
            {
                int x= m%base;
                mm.push_back(x);
                m/=base;
            }
            while(n>0)
            {
                int x= n%base;
                nn.push_back(x);
                n/=base;
            }

}

void        solve()
{
            gt[0] =1;
            gt[1]=1;
            fo(i,2,100005) gt[i] = (gt[i-1]*i)%base;
            cin>>test;
            fo(i,1,test)
            {
                cin>>m>>n;
                if (n>(m/2 +1))
                {
                    cout<<0<<"\n";
                    continue;
                }
                m= m-n+1;

                init();
                ll res=1;
                for(int i=0;i<nn.size();++i)
                {

                    res = (res*tinh(mm[i],nn[i]))%base;
                }
                cout<<res<<"\n";
            }
}

main()
{
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
           // freopen("c11tct.inp","r",stdin);
            //freopen("c11tct.out","w",stdout);

            solve();
}
