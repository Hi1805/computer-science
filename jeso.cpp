#include<bits/stdc++.h>
using namespace std;

void josephus(int n, int k){
	queue<int> q;
	for(int i = 1; i<=n; i++)	q.push(i);
	int d = n, v = 0, x;
	while(d>1){
		int x = q.front();
		q.pop();
	
		++v;
		if(v% k == 0 ){
			d--;
			v=0;
			cout<<x;
		}else q.push(x);
		cout<<endl;
	}
	cout<<"\n Phan tu con sot lai la: "<<q.front();
}

int main(){
	int n, k;
	cin >>n;
	cin>>k;
	josephus(n,k);
}
