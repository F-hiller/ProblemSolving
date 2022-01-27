[1417번: 국회의원 선거](https://www.acmicpc.net/problem/1417)

### 사고의 흐름

금방 끝날 줄 알았는데 막혀서 시간을 끌게 되었다.

한 사람씩 매수해보는 방식, 완전 탐색으로 진행했는데 한명씩 매수할 때 마다 득표 수를 정렬해줘야한다. 정렬을 하지 않으면 매수하지 않아도 될 사람을 매수하게 될 수 도 있다.

예를 들어 9 10 12의 입력이 있을 때 12에서 한명 가져와서 10 10 11이 되었을 때 이 코드를 진행하게 되면 3번 후보에게서 표를 가져와서 11 10 10이 되는 것이 아니라 2번 후보의 표를 가져와서 11 9 11이 되고 한번더 가져오는 작업을 하게된다.

```jsx
int n, m, t, N, K, itemp1, itemp2, itemp3;
vector<int> v;
int answer;
int result = 0;

void solution() {
	int i, j, k;
	bool check;
	while (true)
	{
		check = 0;
		while (true)
		{
			check = 0;
			for (i = 0; i < n - 1; i++)
			{
				if (answer <= v[i])
				{
					check = 1;
					answer++;
					v[i]--;
					result++;
					break;
				}
			}
			if (!check)
			{
				break;
			}
			sort(v.begin(), v.end(), greater<int>());
		}
		if (!check)
		{
			break;
		}
	}
	cout << result;
}

int main() {
	//init
	FastIO;
	//init
	int i, j, k;
	init();

	solution();

	return 0;
}

void init() {
	int i, j, k;
	cin >> n;
	cin >> answer;
	for (i = 1; i < n; i++)
	{
		cin >> itemp1;
		v.push_back(itemp1);
	}
	sort(v.begin(), v.end(), greater<int>());
}
```
