//������a��n���������෴��˳���š�
#include<stdio.h>
int fx(int a[],int n)
{
	int i,j;
	int m = (n -1)/ 2;
	int temp=0;
	for ( i = 0; i < m; i++)
	{
		j = n - 1 - i;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	return a;
}
int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int i;
	int n = 10;
	printf("ԭʼ��\n");
	for (i = 0; i < 10; i++)
	{
		printf("%3d", a[i]);
	}
	fx(a,n);
	printf("\n����\n");
	for ( i = 0; i < 10; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;

}