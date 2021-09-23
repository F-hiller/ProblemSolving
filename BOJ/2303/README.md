## 문제

N명이 모여 숫자 게임을 하고자 한다. 각 사람에게는 1부터 10사이의 수가 적혀진 다섯 장의 카드가 주어진다. 그 중 세 장의 카드를 골라 합을 구한 후 일의 자리 수가 가장 큰 사람이 게임을 이기게 된다. 세 장의 카드가 (7, 8, 10)인 경우에는 합은 7+8+10 = 25가 되고 일의 자리 수는 5가 된다. 어떤 사람이 받은 카드가 (7, 5, 5, 4, 9)인 경우 (7, 4, 9)를 선택하면 합이 20이 되어 일의 자리 수는 0이 되고, (5, 5, 9)를 선택하면 합이 19가 되어 일의 자리 수는 9가 된다. 게임을 이기기 위해서는 세 장의 카드를 선택할 때 그 합의 일의 자리 수가 가장 크게 되도록 선택하여야 한다.

예를 들어, N=3일 때

- 1번 사람이 (7, 5, 5, 4, 9),
- 2번 사람이 (1, 1, 1, 1, 1),
- 3번 사람이 (2, 3, 3, 2, 10)의

카드들을 받았을 경우, 세 수의 합에서 일의 자리 수가 가장 크게 되도록 세 수를 선택하면

- 1번 사람은 (5, 5, 9)에서 9,
- 2번 사람은 (1, 1, 1)에서 3,
- 3번 사람은 (2, 3, 3)에서 8의

결과를 각각 얻을 수 있으므로 첫 번째 사람이 이 게임을 이기게 된다.

N명에게 각각 다섯 장의 카드가 주어졌을 때, 세 장의 카드를 골라 합을 구한 후 일의 자리 수가 가장 큰 사람을 찾는 프로그램을 작성하시오. 가장 큰 수를 갖는 사람이 두 명 이상일 경우에는 번호가 가장 큰 사람의 번호를 출력한다.

## 입력

첫 줄에는 사람의 수를 나타내는 정수 N이 주어진다. N은 2이상 1,000이하이다. 그 다음 N 줄에는 1번부터 N번까지 각 사람이 가진 카드가 주어지는 데, 각 줄에는 1부터 10사이의 정수가 다섯 개씩 주어진다. 각 정수 사이에는 한 개의 빈칸이 있다.

## 출력

게임에서 이긴 사람의 번호를 첫 번째 줄에 출력한다. 이긴 사람이 두 명 이상일 경우에는 번호가 가장 큰 사람의 번호를 출력한다.

[2303번: 숫자 게임](https://www.acmicpc.net/problem/2303)

### 사고의 흐름

그냥 구현 문제이다. 

3중 for문을 사용하여 밑에처럼 노가다를 하는 일이 발생하지 않도록 하자.

- C

```cpp
#define _CRT_SECURE_NO_WARNINGS
#define MAX_ELEMENTS 100100
#define max(a, b) (a>b?a:b)
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int first;
	int second;
}element;
int main() {
	//init
	int n, itemp;
	int output = -1;
	int outputIndex = 0;
	int arr[1002][5];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) { 
			scanf("%d", &arr[i][j]); 
		}
		int result = -1;
		result = max(result, (arr[i][0] + arr[i][1] + arr[i][2]) % 10);
		result = max(result, (arr[i][0] + arr[i][1] + arr[i][3]) % 10);
		result = max(result, (arr[i][0] + arr[i][1] + arr[i][4]) % 10);
		result = max(result, (arr[i][0] + arr[i][2] + arr[i][3]) % 10);
		result = max(result, (arr[i][0] + arr[i][2] + arr[i][4]) % 10);
		result = max(result, (arr[i][0] + arr[i][3] + arr[i][4]) % 10);
		result = max(result, (arr[i][1] + arr[i][2] + arr[i][3]) % 10);
		result = max(result, (arr[i][1] + arr[i][2] + arr[i][4]) % 10);
		result = max(result, (arr[i][1] + arr[i][3] + arr[i][4]) % 10);
		result = max(result, (arr[i][2] + arr[i][3] + arr[i][4]) % 10);
		if (output <= result)
		{
			output = result;
			outputIndex = i;
		}
	}

	printf("%d", outputIndex + 1);

	return 0;
}
```

- C++

```cpp
int main() {
	FastIO;
	//init
	int n, itemp;
	cin >> n;
	vector<int> vtemp;
	int result = -1;
	int resultIndex = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> itemp;
			vtemp.push_back(itemp);
		}
		vector<int> mem;
		mem.push_back((vtemp[0] + vtemp[1] + vtemp[2]) % 10);
		mem.push_back((vtemp[0] + vtemp[1] + vtemp[3]) % 10);
		mem.push_back((vtemp[0] + vtemp[1] + vtemp[4]) % 10);
		mem.push_back((vtemp[1] + vtemp[2] + vtemp[3]) % 10);
		mem.push_back((vtemp[1] + vtemp[2] + vtemp[4]) % 10);
		mem.push_back((vtemp[2] + vtemp[3] + vtemp[4]) % 10);
		mem.push_back((vtemp[0] + vtemp[2] + vtemp[3]) % 10);
		mem.push_back((vtemp[0] + vtemp[2] + vtemp[4]) % 10);
		mem.push_back((vtemp[0] + vtemp[3] + vtemp[4]) % 10);
		mem.push_back((vtemp[1] + vtemp[3] + vtemp[4]) % 10);
		int output = mem[0];
		for (int j = 1; j < mem.size(); j++) { if (mem[j] > output) { output = mem[j]; } }
		if (output>=result)
		{
			result = output;
			resultIndex = i;
		}
		vtemp.clear();
	}
	cout << resultIndex + 1;
	return 0;
}
```
