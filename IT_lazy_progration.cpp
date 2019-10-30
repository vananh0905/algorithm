#include    <bits/stdc++.h>
#define     N   int(1e6)+7
#define     fo(i,a,b)   for(int i=a;i<=b;++i)
#define     fd(i,a,b)   for(int i=a;i>=b;--i)

using       namespace std;

struct      point
{
            int x,lazy;
};

int         n,m,k,d,c;
point       it[N];

void        readf()
{
            cin>>n>>k>>m;
}

void        down(int k)
{
            it[2*k].x += it[k].lazy;
            it[2*k].lazy += it[k].lazy;
            it[2*k+1].x += it[k].lazy;
            it[2*k+1].lazy += it[k].lazy;
            it[k].lazy=0;
}

void        update(int k,int l,int r)
{
            if (l>c || r<d) return;
            if (d<=l && r<=c)
            {
                it[k].x++;
                it[k].lazy++;
                return;
            }
            down(k);
            int mid= (l+r)/2;
            update(2*k,l,mid);
            update(2*k+1,mid+1,r);
            it[k].x= max(it[2*k].x,it[2*k+1].x);
}

int         get(int k,int l,int r)
{
            if (l>c || r<d) return -100;
            if (d<=l && r<=c)
            {
                return it[k].x;
            }
            down(k);
            int mid= (l+r)/2;
            return (max(get(2*k,l,mid),get(2*k+1,mid+1,r)));
}

void        solve()
{
            memset(it,0,sizeof(it));
            fo(i,1,m)
            {
                cin>>d>>c;
                d++;
                if (get(1,1,n)< k)
                {
                    cout<<"1\n";
                    update(1,1,n);
                }
                else cout<<"0\n";
            }
}

main()
{
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
           // freopen("tpticket.inp","r",stdin);
         //   freopen("tpticket.out","w",stdout);
            readf();
            solve();
}
