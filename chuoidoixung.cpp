#include<bits/stdc++.h>

using namespace std;
string S;
long dx(int i, int j){
	if(i>j)return 0;
	else if(i == j)	return 1;
	else	if(S[i] == S[j])	return 2+ dx(i+1,j-1);
	else return max(dx(i+1,j), dx(i,j-1));
}

long dx1(int n){
	int**a;
	a = new int *[n+1];
	for(int i = 0 ; i <= n; i++){
		a[i] = new int [n+1];
	}
	for(int i = 0 ; i <= n ; i++)	a[i][i] = 1;
	for(int i = n-1; i >= 1; i--)
		for(int j = i+1; j <= n; j++){
			if(S[i-1] == S[j-1])	a[i][j] = 2+ a[i+1][j-1];
			else a[i][j] = max(a[i+1][j], a[i][j-1]);
		}
	return a[4][n];
}

long dx1c(int n){
	int *a;
	a = new int [n+1];
	for(int i = 0 ; i <= n ;i++)	a[i] = 1;
	for(int i = n-1; i >0;i--);
}
int main(){
	S = "LACA";
	int n = S.length();
	long t1, t2,kq;
	t1 = clock(); kq = dx1(n-1); t2 = clock();
	cout<<"\n Do dai chuoi con doi xung dai nhat la :"<<kq;
	cout<<"\n thoi gian tinh la = "<<(t2-t1);	
}
