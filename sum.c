#include <stdio.h>

int main() {
    int n,i,s;
    float x=0,y=0;

    scanf("%d",&n);

    for(i=1;i<=n;i++) {
        scanf("%d",&s);
        y=y+s;
    }

    x=y/n;

    printf("總成績=%.0f,平均=%.2f\n",y,x);

    if(x<60)
        printf("不及格");
    else 
        printf("及格");

    return 0;
}