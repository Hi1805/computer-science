#include<iostream>
#include <bits/stdc++.h>
using namespace std;

long long chia_bi(int m , int n){
	if(m > 0 && n == 0)
		return 0;
	else
		 if(m==0) return 1;
			else
		 if (m<n) chia_bi(m,m);
		else return chia_bi(m,n-1) + chia_bi(m-n,n);
}
int main(){
	int m = 120, n = 70;
	long long t1, t2, kq;
	t1 = clock(); 
	kq=chia_bi(m,n);
	t2  = clock();
	
	cout<<"\nSo cach bo "<<m<< " bi vao "<<n<<" hop la: "<<kq;
	cout<<"\n Thoi gian tinh toan la = "<<(t2-t1);
	return 0;
}
