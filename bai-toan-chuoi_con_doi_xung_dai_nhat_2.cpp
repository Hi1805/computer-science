#include<bits/stdc++.h>
using namespace std;
//chuoi con doi xung dai nhat
string S;
int dx_dp(int n){
	int **a; a = new int*[n+1];
	for(int i = 0; i <= n; i++) a[i] = new int [n+1];
	for(int i = 1; i <= n; i++) a[i][i] = 1;
	for(int i = n-1; i > 0; i--)
		for(int j = i+1; j <= n; j++){
			if(S[i-1] == S[j-1]) {
				a[i][j] = 2 + a[i+1][j-1];
				cout<<"a["<<i<<"]["<<j<<"]="<<a[i][j]<<endl;
				}
			else {
				a[i][j] = max(a[i+1][j],a[i][j-1]);
				cout<<"a["<<i<<"]["<<j<<"]="<<a[i][j]<<endl;
			}
	}

	return a[1][n];
}

int main(){
	//S= "ABCDACSBSC"; 
	S= "ADBABDB"; 
	int n = S.length();
	long long t1, t2, kq;
	t1 = clock(); 
	kq = dx_dp(n);
	t2  = clock();
	cout<<"\n Do dai chuoi con chung dai nhat la: "<<kq;
	cout<<"\n Thoi gian tinh toan la = "<<(t2-t1);
	return 0;
}
