#include<bits/stdc++.h>
using namespace std;
#define MAXINT 2000000;
int d[] = {3,5,7,2,9};// sua d
int n = 5;
// nhan day ma tran
int F[100][100];
int S[100][100];
int num = 1;
int tinh(int n) {
	int j,i,k;
	for(i = 1; i <= n; i++) F[i][i] = 0;
	for(int L = 2; L < n; L++) 
		for(i = 1; i <= n-L+1; i++) {
			j = i+L-1;
			F[i][j] = MAXINT;
			for(int k = i; k < j; k++) {
				int q = F[i][k] + F[k+1][j]+d[i-1]*d[k]*d[j];
				if(q < F[i][j]) {
					F[i][j] = q;
					S[i][j] = k;
				}
 			}
		}
	return F[1][n-1];
}
void inkq(int i, int j){
	if(i==j)
		printf("A%d", num++);
	else{
		printf("(");
		inkq(i,S[i][j]); printf(" x ");
		inkq(S[i][j]+1,j); printf(")");
	}
		
}
int main(){
	cout<<"\n So phep tinh it nhat la:";
	cout<<tinh(n)<<"\n";
	cout<<"\n Thu tu nhan nhau sau: ";
	inkq(1,n-1);
	return 0;
}
