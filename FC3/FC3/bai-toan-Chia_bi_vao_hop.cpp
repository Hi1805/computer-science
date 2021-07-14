#include <bits/stdc++.h>
using namespace std;
//
//long long tinh(int m, int n){
//	if(m > 0 && n == 0)
//		return 0;
//	else if(m == 0)
//		return 1;
//		else if(m < n)
//			return tinh(m,m);
//			else return tinh(m, n-1) + tinh(m - n,n);
//}

long long chia_bi_dp(int m, int n){
	long long **a;
	a = new long long*[m+1];
	for(int i = 0;i <= m; i++) a[i] = new long long [n+1];
	for(int j = 0; j <= n; j++) a[0][j] = 1;
	for(int i = 1; i <= m; i++) a[i][0] = 0;
	for(int i = 1; i <= m; i++) 
		for(int j = 1; j <= n; j++) 
			if(j > i) {
				a[i][j] = a[i][i];
				//cout<<"a["<<i<<"]["<<j<<"]="<<a[i][j]<<endl;
			}
			else{
				a[i][j] = a[i][j-1] + a[i-j][j];
				//cout<<"a["<<i<<"]["<<j<<"]="<<a[i][j]<<endl;
			}
	return a[m][n];
}
int main(){
	int m = 120, n = 70;//120, 70
	long long t1, t2, kq;
	t1 = clock(); 
	kq=chia_bi_dp(m,n);
	t2  = clock();
	
	cout<<"\nSo cach bo "<<m<< " bi vao "<<n<<" hop la: "<<kq;
	cout<<"\n Thoi gian tinh toan la = "<<(t2-t1);
	return 0;
}
