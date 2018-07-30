#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int max, min, i, sum;
	printf("Enter lower and upperintegerlimits: ");
	scanf("%d %d", &max, &min);
	if (min>max)
	{
		printf("不符合要求，请重新输入！\n");
		scanf("%d %d", &max, &min);
	}
	while (min<max)
	{
		for (i = min, sum = 0; i <= max; i++)
		{
			sum += i*i;
			printf("The sums of the squares from %d to %d is %d\n", min*min, max*max, sum);
			printf("Enter lower and upperintegerlimits: ");
			scanf("%d %d", &max, &min);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}