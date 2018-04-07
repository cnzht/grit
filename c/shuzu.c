#include<stdio.h>
int main()
{
	int a[3][5] = {0},temp=a[0][0];
	int i, j;
	int row = 0,column = 0;
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j< 5; j++)
		{
			scanf_s("%d", &a[i][j]);
			if (temp<a[i][j])
			{
				temp = a[i][j];
				row = i;
				column = j;
			}
		}

	}
	printf("a[%d][%d]=%d", row, column, temp);
	printf("\n");
	system("pause");
	return 0;

}