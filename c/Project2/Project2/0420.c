#define _CRT_SECURE_NO_WARNINGS
/*
//��Ϊ���ԣ�������ǡ�
#include <stdio.h>
#define N 15
#define M 15
int main()
{
	int a[N][M] = {0}, i, j, n = 0, m = 0;
	printf("��������������");
	scanf("%d", &n);
	while (m<=n)
	{
		a[m][0] = 1;
		for ( i = 1; i < n; i++)
		{
			for ( j = 1; j < n; j++)
			{
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
			
		}
		m++;
	}
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
		
	}
	printf("��������Ҫȡ�������У�");
	scanf("%d,%d", &n, &m);
	printf("%d\n", a[n][m]);
	system("pause");
	return 0;
}
*/

#include <stdio.h>
#define N 15
#define M 15
int main()
{
	system("pause");
	return 0;
}