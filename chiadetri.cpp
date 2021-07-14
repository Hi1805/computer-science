#include<iostream>
using namespace std;
long long nhan(long long a,long long b)
{
    if (b == 0) 
        return 0;
    long long t = nhan(a, b / 2);     	
    t = (t + t) % mod; 
    if (b % 2 == 1) 
        t = (t + a) % mod;
} 
int main(){
	nhan(5,25);
}
