#include    <bits/stdc++.h>
#define     N   int(1e6)+7
#define     fo(i,a,b)   for(int i=a;i<=b;++i)
#define     fd(i,a,b)   for(int i=a;i>=b;--i)
#define     task ""
#define     pb  push_back
#define     reset(ok,a) memset(ok,a,sizeof(ok))
#define     ii pair<int,int>
#define     x first
#define     y   second
#define     ll long long


using       namespace std;



template <typename T> inline void read(T &x){
        char c;
        bool nega=0;
        while((!isdigit(c=getchar()))&&(c!='-'));
        if(c=='-'){
            nega=1;
            c=getchar();
        }
        x=c-48;
        while(isdigit(c=getchar())) x=x*10+c-48;
        if(nega) x=-x;
}
template <typename T> inline void writep(T x){
        if(x>9) writep(x/10);
        putchar(x%10+48);
}
template <typename T> inline void write(T x){
        if(x<0){
            putchar('-');
            x=-x;
        }
        writep(x);
}
template <typename T> inline void writeln(T x){
        write(x);
        putchar('\n');
}

void        readf()
{

}

void        solve()
{

}

main()
{
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            freopen(task".inp","r",stdin);
            freopen(task".out","w",stdout);
            readf();
            solve();
}
