#include <stdio.h>
#include <string.h>
void replaceSpace(char *str, int length) {
	
	for (int i = 1; i < length; i++)
	{
		printf("%s\n", *(str+i));
	}
	/*else
	{
		printf("error");
	}*/
}
int main()
{
	char *str = "we in sohu !";
	int m = strlen(str);
	replaceSpace(&str, m);
	printf("%s", str);
	getchar();
	return 0;
}