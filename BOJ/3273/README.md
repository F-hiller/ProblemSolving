## 문제

n개의 서로 다른 양의 정수 a1, a2, ..., an으로 이루어진 수열이 있다. ai의 값은 1보다 크거나 같고, 1000000보다 작거나 같은 자연수이다. 자연수 x가 주어졌을 때, ai + aj = x (1 ≤ i < j ≤ n)을 만족하는 (ai, aj)쌍의 수를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 수열의 크기 n이 주어진다. 다음 줄에는 수열에 포함되는 수가 주어진다. 셋째 줄에는 x가 주어진다. (1 ≤ n ≤ 100000, 1 ≤ x ≤ 2000000)

## 출력

문제의 조건을 만족하는 쌍의 개수를 출력한다.

[3273번: 두 수의 합](https://www.acmicpc.net/problem/3273)

### 사고의 흐름

bool형 인덱스를 이용하는 일을 비트마스킹이라고 한다. 



```tsx
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
```
