#include      <bits/stdc++.h>
#define         N   100
#define       fo(i,a,b) for(int i=a;i<=b;++i)
#define       fd(i,a,b) for(int i=a;i>=b;--i)

using           namespace   std;

int         a[N],n;

void        readf()
{
            cin>>n;
            fo(i,1,n) cin>>a[i];
}

void        solve()
{
            int u = upper_bound(a+1,a+1+n,40)-a;// vi tri nho nhat lon hon khoa
            int v= lower_bound(a+1,a+1+n,0)-a;// vi tri nho nhat >= khoa
            int x= upper_bound(a+1,a+1+n,20)-a-1;// vi tri lon nhat khong lon hon khoa
            int y= lower_bound(a+1,a+1 +n,0)-a-1;//vi tri lon nhat be hon khoa
            cout<<u<<" "<<v<<" "<<x<<" "<<y;
}

main()
{
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            readf();
            solve();
}
