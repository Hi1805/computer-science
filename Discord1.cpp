#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
// cau1 nhap mang 
void nhap(float *p,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%f",(p+i*m+j));
        }
    }
}
// cau 2 xuat mang
void xuat(float *p,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%8.1f\t",*(p+i*m+j));
        }
        printf("\n");
    }
}
// cau 3 tim` phan tu duong
int soduong(float *p,int n,int m)
{
	int k=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(*(p+i*m+j)>0)
            {
            	k++;
			}
        }
    }
    return k;
}
// cau 4 : tim tong so chan
int sochan(float *p,int n,int m)
{
    int k =0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(*(p+i*m+j)-(int)*(p+i*m+j)==0) // kiem tra la so nguyen thi lay
            {
            	if((int)*(p+i*m+j)%2==0)
            	{
            		k++; 
				}
			}
        }
    }
    return k;
}
// cau 5 sap xep phan tu hang k tang dan
void swap(float a, float b)
{		printf("%8.1f\t swap a",a);
    	printf("%8.1f\t swap b",b);
	float sw = a; 
	a=b;
	b=sw;
}
void xuatA(float a,float b){
	printf("%8.1f\t swap a = ",a);
	printf("%8.1f\t swap b =",b);
}
void sapxep(float *p,int n, int m,int k)
{
    for(int j=0;j<m;j++)
    {	
     	 for(int i=0;i<m;i++)
   		 {	
   		 	if(*(p+k*m+j) > *(p+k*m+i)){
//   		 		printf("%8.1f\t ",*(p+k*m+j));
				printf("%8.1f\t ",*(p+k*m+j));
   		 		xuatA(*(p+k*m+j),0);
			}
     
  		  }
    }
}
// cau 6 doc ghi file in phan tu trong arr
void file(FILE *file,float *p,int n, int m)
{    p = new float[m*n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           if(*(p+i*m+j)>0)
           {
           		fprintf(file,"%5.1	f\t",*(p+i*m+j));
		   }
        }
        fprintf(file,"\n");
    }
}
int main()
{
    FILE *arr;
    arr = fopen("E://devc//decuong//bai4arr2.txt","w"); // tep can nhap theo bai
    int n,m;
    float *p;
    p = (float *)malloc(n*m* sizeof(float));
    printf("nhap hang : ");
    scanf("%d",&n);
    printf("nhap cot : ");
    scanf("%d",&m);
    nhap(p,n,m);
    xuat(p,n,m);
    if(soduong!=0)
    {
    	printf("\nco %d so duong",soduong(p,n,m));
	}
	else
	{
		printf("\nkhong co so duong nao");
	}
	if(sochan!=0)
    {
    	printf("\nco %d so chan",sochan(p,n,m));
	}
	else
	{
		printf("\nkhong co so chan nao");
	}
	int k;
	do
	{
		printf("\nsap xep hang : ");
		scanf("%d",&k);
	}
	while(k<0||k>=m);
	sapxep(p,n,m,k);
	printf("\nmang sau khi sap xep:\n");
	xuat(p,n,m);
    file(arr,p,n,m);
    free(p);
    fclose(arr);
    return 0;
}
