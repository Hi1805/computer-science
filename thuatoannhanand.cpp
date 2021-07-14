#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
using namespace std;

int solve(int a, int b){
    int S = 0;
    int i = 0;
    int o = 0;
    while(b > 0){
    	++o;
        if(b % 2 != 0){
            S = S + a;
        }
        i++;
        b = b / 2;
        if(b > 0) a = a + a;
    }
    cout<<"sl"<<o<<endl;
    return S;
}

int main(){
	cout<<solve(2,33);
}
