	#include<iostream>
using namespace std;

// May bay di tuan
int  *V, *B, *result;
int dem = 0, n;
void init(){
    n = 2;// so phan tu
    V = new int[n];
    V[0] = 3;
    V[1] = 5;
    V[2] = 1;
    V[3] = 4;
//    V[4] = 6;
//    V[5] = 2;
//    V[6] = 3;
//    V[7] = 9;

    B = new int[n];
    result = new int[n];
    for(int j = 0; j < n; j++){
        B[j] = result[j] = 0;
    }
}

void output(){
    cout << "\n Cach thu " << ++dem << ": ";
    for(int i = 0; i < n; i++){
        cout << " " << result[i];
    }
}
void find(int i, int d){
    if(i > n){ // Tìm du?c n bình xang
        output();
    }
    else{
     for(int j = 0; j < n; j++){// Ch?y m?ng duy?t bình xang
        if(B[j] == 0 && V[j] > d){
            //cout << i << endl;
            result[i - 1] = V[j];
            B[j] = 1;
            find(i + 1, V[j] - d);
            result[i - 1] = 0;
            B[j] = 0;
        }
     }
    }
}
int main(){
 int d = 2;
 init();
 find(1, d);
 return 0;
}
