#include <stdio.h>
int main()
{
	int n = 0,x=500;
	char a = '\80';
	while (x)
	{
		n++;
		x = x&(x - 1);
		printf("%d->%d\n",x, n);
	}
	printf("%d",n);
	getchar();
	return 0;
}