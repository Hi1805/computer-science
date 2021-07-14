#include<iostream>
using namespace std;

int *rs,*sl,*v;
int n , count = 0;

void init(){
    n = 8;
    v = new int[n];
    // 5 4 2 7 6 2 3 9

    v[0] = 5;
    v[1] = 4;
    v[2] = 2;
    v[3] = 7;
    v[4] = 6;
    v[5] = 2;
    v[6] = 3;
    v[7] = 9;

    sl =  new int[n];
    rs = new int[n];

    for(int i = 0 ; i < n ; i++ ){
        rs[i] = 0;
        sl[i] = 0;
    }
}
void display(){
    cout<<" number " <<++count<<endl;
    for(int i = 0  ; i < n ; i++ ){
        cout<<rs[i] << " ";
    }
    cout<<endl;
}
void find(int i,int d){
    if(i > n ){
        display();
        return
    }
    for(int j = 0 ; j < n ; j++){
        if(sl[j] == 0 && v[j] > d){
            rs[i-1] = v[j];
            sl[j] = 1;
            find(i+1,v[j] - d);
            rs[i-1] =0;
            sl[j] = 0;
        }
    }
}
int main(){
    init();
    find(1,n);
}
