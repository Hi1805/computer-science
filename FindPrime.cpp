#include<iostream>
using namespace std;

void  createArray(int a[], int n){
	for(int i = 2 ; i <=n ; i++ ){
			a[i] = i;
	}
}
void findPrime(int a[] , int n){
	bool check[n+1];
	int p = 2;
	for(int i  = 2 ; i <= n  ; i ++){ // xem nhu tat ca dieu la so ntn 
		check[i] = true;
	}

	for(int i = 2 ; i <= n ; i++){ // i = 2 
		if(check[i]){ // chua bi danh dau 
			for( int j = i * 2 ; j <= n ; j = j + i){ // 4 6 8  
					check[j] = false;
			}
		}
	}

	 for (int i = 2; i <= n; i++) {
	    if (check[i]) {
	  		cout<<a[i]<<" ";
	    }
	  }
}
int main(){
	int a[100];
	createArray(a,100);
	findPrime(a,100);
}
