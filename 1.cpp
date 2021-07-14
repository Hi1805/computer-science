#include<iostream>
using namespace std;
int main(){
	int k=0, n=20; for(int i=1; i<=n; i++) { int j=i; while(j<=n) { k++; j=j*2; } }
	cout<<k;
}
