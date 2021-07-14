#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace  std;

// tim mang con lien tiep co tong lon nhat
void sol1(int *a,int n){
	int smax = a[0],b= 0,c=0;
	for(int i = 0 ; i < n ;i ++){
		for(int j = i ;j <n;j++){
			int s =0;
			for(int k = i ; k <= j ; k++){
				s= s+ a[k];
			}
				if(s > smax){
					smax = s;
					b = i;
					c = j;
				}
			
		}
	}
	cout<<"\nDoan co tong lon nhat la "<<smax;
}
void sol2(int *a, long n){
	int smax = a[0], d = 0,c=0;
	int *ss = new int[n];
	ss[0] = a[0];
	for(int i = 1 ; i < n ; i++)
		ss[i] = ss[i-1] + a[i];
	for(int i = 0 ; i < n ; i ++){
		for(int j = i ; j < n; j++){
			int s= 0;
			if(i==0)
				s = ss[j];
			else s=ss[j] - ss[i-1];
			if(s > smax){
				smax = s;
				d=i;
				c=j;
			}
		}
	}
	cout<<"\nDoan con co tong lon nhat la "<<smax;
}
void sol3(int *a,long n){
	int smax = a[0]; 
	int dau =0,cuoi =0,s=0,d=0;
	
	for(int i = 0 ; i<n;i++){
		s = s + a[i];
		if(s > smax ){
			smax = s;
			dau = d;
			cuoi = i;
		}
		if(s < 0){
			s = 0;
			d = i + 1;
		}
	}
	cout<<"\n Mang lient tiep co tong lon nhat la "<<smax;
}
void singmang(int *&a, long n){
	a = new int[n];
	for(int i = 0;i<n; i++){
		int x = rand()%1001;
		if(x % 3 == 0){
			x=-2*x;
			a[i] = x;
		}
	} 
}
int main(){
//	int a[]={1,25,6,8,3,5,6},n=7;
	int *a;
	long n = 100000;
	singmang(a,n);
	long t1,t2;
	t1 = clock();sol2(a,n);t2 = clock();
	cout<<"\n Thoi gian thuc hien thuat toan theo sol2 la "<<(t2-t1);
	t1 = clock();sol3(a,n);t2 = clock();
	cout<<"\n Thoi gian thuc hien thuat toan theo sol3 la "<<(t2-t1);}
