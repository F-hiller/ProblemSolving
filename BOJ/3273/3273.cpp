#define _CRT_SECURE_NO_WARNINGS
#define MAX_RANGE 2000001
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, x, temp;
	scanf("%d", &n);
	//int* arr = (int*)malloc(sizeof(int) * n);
	short int* check = (short int*)malloc(sizeof(short int) * MAX_RANGE);
	for (int i = 0; i < MAX_RANGE; i++)
	{
		check[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		//arr[i] = temp;
		check[temp] = 1;
	}
	scanf("%d", &x);
	int result = 0;
	if (x%2==0)
	{
		for (int i = 1; i < x / 2; i++)
		{
			if (check[i] && check[x - i])
			{
				result++;
			}
		}
	}
	else
	{
		for (int i = 1; i <= x / 2; i++)
		{
			if (check[i] && check[x - i])
			{
				result++;
			}
		}
	}
	
	printf("%d", result);

	return 0;
}
