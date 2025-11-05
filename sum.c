#include <stdio.h>

int main() {
    int quantity;
    float score,average=0,sum=0,statistics[100];

	printf("請輸入學生人數:");
    scanf("%d",&quantity);

    if(quantity<=0) {
        while (quantity > 0) {
        printf("輸入人數必須大於0:");
        scanf("%d", &quantity);
        }
	}
	printf("請依序輸入各學生成績:\n");
    for(int i=1;i<=quantity;i++) {
		printf("第%d位:", i);
        scanf("%f",&score);
        while(score < 0 || score>100) {
            printf("成績輸入錯誤,請重新輸入:");
            scanf("%f",&score);
		}
		sum += score;
		statistics[i - 1] = score;
    }
	//由小到大排序
    for (int b = 0; b < quantity - 1; b++) {
        for (int c = b + 1; c < quantity; c++) {
            if (statistics[b] > statistics[c]) {
                float temp = statistics[b];
                statistics[b] = statistics[c];
                statistics[c] = temp;
            }
        }
    }
	average = sum / quantity;
    printf("\n成績統計結果：\n");
    printf("總成績=%.2f,平均=%.2f\n",sum,average);
	printf("最高分=%.2f,最低分=%.2f\n", statistics[quantity-1], statistics[0]);
    if((quantity-1)%2==0)
        printf("中位數=%.2f\n", statistics[(quantity-1)/2]);
    else
        printf("中位數=%.2f\n", (statistics[quantity / 2 - 1] + statistics[quantity / 2]) / 2);
    printf("平均結果判定：%s\n", (average < 60) ? "不及格，要加油!" : "有及格，歡呼~");

    return 0;
}
