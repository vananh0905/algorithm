#include	<bits/stdc++.h>
#define		fo(i,a,b)	for(int i= a;i <= b; i++)
#define		base 1000007
#define		ll	long long

using		namespace	std;
struct		matrix
{
			ll mt[3][3];
};

ll   		n;
matrix		a,b,c,f;

matrix		nhan(matrix a,matrix b)
{
			ll s;
			int i,j,ii;
			fo(i,1,2)
			fo(j,1,2)
			{
				s= 0 ;
				fo(ii,1,2) 
				{
					s = (s+ (a.mt[i][ii] % base)*(b.mt[ii][j] %base)) %base;
				//	cout <<i<< " "<<j<<" "<< ii <<" "<<a.mt[i][ii] <<" "<<b.mt[ii][j] << " "<<s<<endl;
				c.mt[i][j] = s;
			}
			}
			return c;
}

matrix		poww(matrix a,ll n)
{
			matrix tmp;
			if (n== 1) return a;
			tmp = poww(a,n/2);
			tmp = nhan(tmp,tmp);
			if (n%2 == 1) tmp = nhan(tmp,a);
			
			return tmp;
}

main()
{
		//	freopen("fibo3.inp","r",stdin);
		//	freopen("fibo3.out","w",stdout);
			cin >>n;
			if (n <=2) cout <<1<<endl;
			else{
				a.mt[1][1] = 1; a.mt[1][2] = 1;
				a.mt[2][1] = 1; a.mt[2][2] = 0;
				f.mt[1][1] = 1; f.mt[1][2] = 1;
				a = poww(a,n-2);
				f = nhan(f,a);
				cout <<f.mt[1][1]<<endl;
			}	
}	

matrix operator ^ (matrix A,int P){
    matrix B;
    fo(i,1,24) B.x[i][i]=1;
    for( ; P ; P/=2, A = A * A)
        if (P&1) B=B*A;
    return B;
}
