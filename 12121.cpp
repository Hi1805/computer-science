#include<iostream>
using namespace std;
int pow(int a, int n)
{	  cout<<"run";
    if(n == 1) return a;
    int tmp = pow(a, n/2);
  
    return (n & 1) ? tmp * tmp * a : tmp * tmp;
}
int main(){
	pow(2,13);
}
