#include <stdio.h>
int i,isPrime;
float n;

int main(){

    scanf("%f",&n);

    if(n - (int)n != 0){
        printf("請輸入整數");
        return 0;
    }

    if(n <= 1){
        printf("請輸入大於1的整數");
        return 0;
    }

    for(i=2;i <= n-1;i++){
        if((int)n % i == 0){
            printf("%.0f不是質數\n除1和%.0f外的因數有:%d",n,n,i);
            isPrime = 0;
            break;
        }
        else
            isPrime = 1;
    } 
    
    if(isPrime)   
        printf("%.0f是質數\n",n);

    return 0;       
}