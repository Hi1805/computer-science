#include <bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<int, vector<int>, greater<int> > mypq;
	int stt = 0,x,y;
	cout<<"Nhap kich thuoc cac file, != 0";
	while(1){
		cout<<"\n Nhap kich thuoc file thu "<<++stt<<": ";
		cin>>x;
		if(x == 0) break; 
		else mypq.push(x);
	}
	cout <<"\n Tron cac file...\n";
	int d = 0;
	while(!mypq.empty()){
		x = mypq.top();
		mypq.pop();
		if(mypq.empty()){
			cout<<"\n Da tron xong cac file!!";
			cout<<"\n===== Tong so lan doc file la: "<<d<<"=====";
		}
		else{
			y = mypq.top();
			mypq.pop();
			cout<<"\n Tron 2 file co kich thuoc la "<<x<<" va "<<y;
			cout<<"\n ----so lan doc file la: "<<(x+y);
			mypq.push(x+y);
			d = d+ x+y;
		}
	}
	return 0;
}

