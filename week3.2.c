#include <stdio.h>
int main(){
    float n[100],x;
    int a;
    char ch[5];
    printf("please input numbers:");
    for(a=0;a<100;a++){
        if(scanf("%f",&n[a]))
            continue;
        else{
            scanf("%s",&ch);
            if(ch[0]!='g'){
                while(1){
                    printf("number非數值,請重新輸入:");
                    if(scanf("%f ",&n[a]))
                        break;
                    else{
                        scanf("%s",&ch);
                        if(ch[0]=='g')
                            break;
                        continue;}
                }
            }
            if(ch[0]=='g')
                break;}
    } 
    for(int b=0;b<a-1;b++){
        for(int c=b+1;c<a;c++){
            if(n[b]>n[c]){
                x=n[b];
                n[b]=n[c];
                n[c]=x;}
        }
    }
    if((a-1)%2==0)
        printf("中位數=%f\n",n[(a-1)/2]);
    if((a-1)%2==1)
        printf("中位數=%f\n",(n[(a-2)/2]+n[a/2])/2);
    printf("最小值=%f\n",n[0]);
    printf("最大值=%f",n[a-1]);
    return 0;
}