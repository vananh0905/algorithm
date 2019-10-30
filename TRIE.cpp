#include    <bits/stdc++.h>
#define     N   int(1e6)+7
#define     fo(i,a,b)   for(int i=a;i<=b;++i)
#define     fd(i,a,b)   for(int i=a;i>=b;--i)
#define     ll  long long

using       namespace std;

int         n;
string      a[N];
int          res;

struct      trie
{
            int kt;
            trie *node[60];
            trie()
            {
                kt =0;
                fo(j,0,57) node[j] =NULL;
            }
};

trie        *root,*p;

void        readf()
{
            root = new(trie);
            cin>>n;
            fo(i,1,n)
            {
                cin>>a[i];
                p = root;
                fo(j,0,a[i].size()-1)
                {
                    int x= a[i][j] - 'A';
                    if (p->node[x] == NULL)
                        p->node[x] = new(trie);
                    p = p->node[x];
                }
                p->kt ++;

            }
}

void        solve()
{
            res = 0;
            fo(i,1,n)
            {

                int tmp = 0;
                p = root;

                fo(j,0,a[i].size()-1)
                {
                    int x=a[i][j]-'A';
                    if (p->node[x] != NULL)
                    {
                        p = p->node[x];
                    } ;

                }
               // cout<<i<<
                if (p->kt==1)
                {
                    cout<<a[i]<<endl;
                    return;
                }
            }


}

main()
{
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
        //    freopen("chain2.inp","r",stdin);
          //  freopen("chain2.out","w",stdout);
            readf();
            solve();
}
