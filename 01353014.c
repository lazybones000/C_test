#include <stdio.h>
#include <math.h>//平方根計算

int main(){
    //從全域變數換成區域變數
    int is_prime = 1;
    double input_num;

    //新增輸入提示
    printf("請輸入一個整數: ");

    //檢查是否為數字
    if (scanf("%lf", &input_num) != 1) {
        printf("輸入錯誤！請輸入有效的數字\n");
        return 1;
    }

    //檢查是否為整數
    if (input_num != (int)input_num) {
        printf("請輸入整數\n");
        return 1;
    }

    //轉換成整數形式
    int num = (int)input_num;

    //檢查是否大於1
    if (num <= 1) {
        printf("請輸入大於1的整數\n");
        return 1;
    }

    // 處理特例
    if (num == 2) {
        printf("%d是質數\n", num);
        return 0;
    }
    
    if (num % 2 == 0) {//檢查是否為偶數
        printf("%d不是質數\n除1和%d外的因數有: 2", num, num);
        is_prime = 0;
    } 
    else {// 只需檢查到平方根即可
        int limit = (int)sqrt(num) + 1;
        
        for (int i = 3; i <= limit; i += 2) {
            if (num % i == 0) {
                printf("%d不是質數\n除1和%d外的因數有: %d", num, num, i);
                is_prime = 0;
                break;
            }
        }
    }

    //輸出結果
    if (is_prime) 
        printf("%d是質數\n", num);
    
    return 0;       
}
