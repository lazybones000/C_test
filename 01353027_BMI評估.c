#include <stdio.h>

int main(){
	float h, w, bmi;
	scanf("%f%f", &h, &w);
	bmi=w/(h*h);
	printf("%f\n", bmi);
	if(bmi<18.5)
		printf("體重過輕");
	else if(18.5<=bmi<24)
		printf("正常範圍");
	else if(24<=bmi<27)
		printf("過重");
	else if(27<=bmi<30)
		printf("輕度肥胖");
	else if(30<=bmi<35)
		printf("中度肥胖");
	else
		printf("重度肥胖");
	return 0;
}