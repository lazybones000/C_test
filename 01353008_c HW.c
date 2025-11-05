#include <stdio.h>
int main(){
    float num[100];
    int a;
    char ch[5], end='g';
    printf("輸入數值尋找最大值、最小值、中位數；輸入g完成輸入\nplease input numbers:\n");
    for(a=0;a<100;a++){
        if(scanf("%f",&num[a])){
            continue;
        }
        else{
            scanf("%s",&ch);
            if(ch[0]!=end){
                while(1){
                    printf("number非數值,請重新輸入:");
                    if(scanf("%f ",&num[a]))
                        break;
                    else{
                        scanf("%s",&ch);
                        if(ch[0]== end){
                            break;
                        }
                        continue;
                    }
                }
            }
            if(ch[0]== end){
                break;
            }
        }
    } 
    for(int b=0;b<a-1;b++){
        for(int c=b+1;c<a;c++){
            if(num[b]>num[c]){
                num[b]=num[b]+num[c];
                num[c]=num[b]-num[c];
                num[b]=num[b]-num[c];
            }
        }
    }
    //若數據量為奇數
    if((a-1)%2==0){
        printf("中位數=%f\n",num[(a-1)/2]);
    }
    //若數據量為偶數
    else{
        printf("中位數=%f\n",(num[(a-2)/2]+num[a/2])/2);
    }
    printf("最小值=%f\n",num[0]);
    printf("最大值=%f",num[a-1]);
    return 0;
}
