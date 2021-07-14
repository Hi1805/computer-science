#include<bits/stdc++.h>

using namespace std;


long long ck(int m, int n){
	if(m == 0 && n == 0)	return 0;
	else
		if(m == 0 || n == 0)	return 1;
		else return ck(m,n-1) + ck(m-1,n);
}

long long ck_dq(int m, int n){
	long long **a;
	a = new long long*[m+1];
	for(int i = 0 ; i <= m; i++)	a[i] = new long long[n+1];
	for(int i = 1; i <= n ; i++)	a[0][i] = 1;
	for(int i = 1; i <= m ; i++)	a[i][0] = 1;
	for(int i = 1; i <=m;i++)
		for(int j = 1; j <= n; j++)
			a[i][j] = a[i][j-1] + a[i-1][j];
	return a[m][n];
}

long long ck_mc(int m, int n){
	long long *a;
	a = new long long [n+1];
	for(int i = 0; i <= n ; i++)	a[i] = 1;
	for(int i = 1; i <=m;i++)
		for(int j = 1; j <= n; j++)
			a[j] = a[j-1] +a[j];
	return a[n];
}
main()
{
int m = 4, n = 2, t1, t2;
t1 = clock(); long long kq = ck_mc(m,n); t2 = clock();
cout << "\n so cach di tren luoi: m "<<m<<",n "<<n<<" la: "<<kq;
cout<<"\n tg chay: "<<(t2-t1);


}
