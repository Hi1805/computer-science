#include<iostream>
using namespace std;
long long sumOfDivisors(int n, int k)
{
    if(k > n )  return 0;
    long long sum = 0 ;
    for(int i = k; i <= n ; i=i+k ){
        if(n % i == 0 && i % k == 0){
            sum += i;
        }
    }
    return sum;
}
int main(){
	cout<<sumOfDivisors(1000000000,1000);
}
