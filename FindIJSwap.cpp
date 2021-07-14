#include<bits/stdc++.h>
using namespace std;

int n, k;
int A[10];

void Print(int A[],int k){
	for(int i = 1; i <= k; i++){
		cout<< A[i];
	}
	cout<< endl;
}
int giaithua(int n){
	int tich = 1;
	for( int i = 2; i <= n; i++){
		tich*=i;
	}
	return tich;
}
int Ckn(int n, int k){
//	return  giaithua(n) / ( giaithua(k) * giaithua(n-k));
	if( k == 0 || k == n)	return 1;
	return Ckn(n-1,k) + Ckn(n-1,k-1);
}

void C( int A[], int n, int k){
	for( int i = 1; i <= k; i++){
		A[i] = i;
	}
	Print(A,k);
	for( int c = 1; c < Ckn(n,k) ; c++){
		int i = k ; 
		while( A[i] == n-k+i) i--;
		A[i] = A[i]+1;
		for( int j = i+1; j <= k; j++){
			A[j]= A[j-1] + 1;
		}
		Print(A, k);
	}
}

int main(){
	cin>> n;
	cin>> k;
	C(A,n,k);
	return 0;
}
