//计算5个分数的平均成绩。
#include<stdio.h>
float ave(float a[])
{
	int i;
	float sum=0,ave=0;
	for ( i = 0; i < 5; i++)
	{
		sum += a[i];
	}
	ave = sum / 5;
	return ave;
}
int main()
{
	float a[5] = { 0 };
	int i;
	for ( i = 0; i < 5; i++)
	{
		scanf_s("%f", &a[i]);
	}
	printf("%.2f\n",ave(a));
	system("pause");
	return 0;
}