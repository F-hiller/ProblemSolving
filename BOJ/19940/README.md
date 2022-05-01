[19940번: 피자 오븐](https://www.acmicpc.net/problem/19940)

## 사고의 흐름

기본적인 bfs 문제였다.

문제를 잘못읽어 여러번 틀렸다. 문제에서 요구하는 것을 이해하고 코드를 적자.

작업 횟수가 작은 것이 우선이고 

작업 횟수가 같다면 AH, AT, MT, AO, MO 순서로 작은 것이 우선이다.

작업 횟수를 줄이기 위해서는 숫자 N이 주어졌을 때 가장 큰 단위 +60을 넘어가는 것들은 ADDH를 통해서 줄여줘야한다. 즉 60을 넘어가는 것은 ADDH를 진행하는 것이 작업 횟수가 가장 적다.

따라서 작업 횟수가 같은 경우를 확인해줘야하는 것은 0~60의 숫자 범위를 가진다. 

이를 BFS를 통해서 배열에 저장해주고 주어진 입력에 따라 활용하면 된다.

```cpp
#define INF 987654321
#define SHARING 10000001
#define SHARING2 61

int n, m, t, N, K;

//additional variables
typedef struct _count {
	int value;
	int total_count;
	int count[5];
}custom;
custom sixty[SHARING2];

void bfs() {
	int i, j;
	int counter[] = { 60, 10, -10, 1, -1 };
	custom ctemp;
	queue<custom> q;

	for (i = 0; i < SHARING2; i++)
	{
		sixty[i].total_count = INF;
	}

	ctemp = sixty[0];
	ctemp.total_count = 0;

	q.push(ctemp);

	while (!q.empty())
	{
		custom top = q.front();
		int value = top.value;
		q.pop();
		if (-1 < value && value < SHARING2)
		{
			custom sixty_value = sixty[value];
			if (top.total_count > sixty_value.total_count) { continue; }
			if (top.total_count == sixty_value.total_count)
			{
				bool break_check = 1;
				for (i = 0; i < 5; i++)
				{
					if (top.count[i] > sixty_value.count[i]) { break; }
					if (top.count[i] < sixty_value.count[i]) {
						break_check = 0;
						break;
					}
				}
				if (break_check) { continue; }
			}

			sixty[value] = top;

			for (i = 0; i < 5; i++)
			{
				ctemp = top;
				ctemp.value += counter[i];
				ctemp.total_count++;
				ctemp.count[i]++;
				q.push(ctemp);
			}
		}
	}
}

//main function
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int t, i, j, k, itemp;

	//solution
	bfs();

	cin >> t;

	for (i = 0; i < t; i++)
	{
		cin >> n;
		cout << n / 60 + sixty[n % 60].count[0] << " ";
		for (j = 1; j < 5; j++)
		{
			cout << sixty[n % 60].count[j] << " ";
		}
		cout << endl;
	}

	return 0;
}
```
