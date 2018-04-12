#include<stdio.h>
#define MAX_LENGTH 100
int find(int *data, int data_length)
{
	int max_sum = 0;
	int data_sum = 0;
	int data_number = 0;

	for (data_number = 0; data_number < data_length; data_number++)
	{
		data_sum = data_sum + (*(data + data_number));
		if (data_sum > max_sum)
			max_sum = data_sum;
		if (data_sum < 0)
			data_sum = 0;
	}
	return max_sum;
}



int main()
{
	int data[MAX_LENGTH] = { 0 };
	int data_length = 0;
	char char_tmp = 0;
	for (data_length = 0; data_length < MAX_LENGTH; data_length++)
	{
		scanf_s("%d", &data[data_length]);
		scanf_s("%c", &char_tmp);
		if (char_tmp != ',')
			break;
	}

	printf("%d\n", find(data, data_length + 1));
	system("pause");
	return 0;
}