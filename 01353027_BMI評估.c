#include <stdio.h>
//運算以及判斷中加入空格增加程式可讀性

int main(){
	//新增使用者輸入介紹
	printf("請輸入身高(公尺)與體重(公斤)：");
	
	//修改變數名稱，讓變數變得容易判讀
	float height, weight, bmi;
	scanf("%f%f", &height, &weight);
	
	//新增輸入判斷
	if (height <= 0 || weight <= 0) {
        printf("輸入錯誤：身高與體重必須為正數。\n");
        return 1;
    }

	bmi = weight / (height * height);
	printf("BMI = %.2f\n", bmi); //新增小數點判定
	
	if(bmi < 18.5)
		printf("體重過輕");
	else if(18.5 <= bmi && bmi < 24) //C語言的判斷需要分開
		printf("正常範圍");
	else if(24 <= bmi && bmi < 27)
		printf("過重");
	else if(27 <= bmi && bmi < 30)
		printf("輕度肥胖");
	else if(30 <= bmi && bmi < 35)
		printf("中度肥胖");
	else
		printf("重度肥胖");
	return 0;

}
