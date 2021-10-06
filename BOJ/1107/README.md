[1107번: 리모컨](https://www.acmicpc.net/problem/1107)

## 사고의 흐름

처음 문제를 접했을 때 bfs를 이용해서 풀어보면 어떨까 했지만 풀다보니 아닌 것 같아서 그만뒀다. 그 후 완전 탐색을 통해 진행했었는데 방식이 잘못되었었다. 다른 방식이 없을까 해서 알고리즘 분류를 보니 브루트포스라서 다시 생각해보았다. 그 결과 생각해낸 것은 다음과 같다.

1. 현재 채널이 100이고 가장 마지막 채널인 500000까지 가는데 걸리는 최대 횟수는 500000 - 100번이다. 즉 999900 이전까지만 탐색해보아도 된다는 이야기이다. 
2. 500000대신 입력 n을 기준으로 한다면 최대 범위는 (2 * n - 100) 이전까지이다. 하지만 이는 n > 100인 경우라서 n이 100보다 큰 경우와 작은 경우로 나누었다.
3. n에서부터 커지는 경우와 n에서부터 작아지는 경우를 모두 탐색해본 후 가장 작은 값을 답으로 구해주면 완성이다.
- 물론 해당 채널로 이동하는 버튼을 누르는 횟수도 구해줘야 하므로 make_result함수로 자릿수를 더해줬다.

```cpp
int t, n, m, a, b, c, d, e, itemp1, itemp2;
bool button[11];
int channel[1000000];
string stemp;
int result;

int make_result(int result, int value) {
	//자릿수를 더해줌
	if (value == 0) { return result + 1; }
	while (value)
	{
		result++;
		value /= 10;
	}
	return result;
}
void solution(int first, int second) {
	int i, j, k;
	for (i = n; i < first; i++)
	{
		stemp = to_string(i);
		bool check = 0;
		for (j = 0; j < stemp.size(); j++)
		{
			if (button[stemp[j] - '0'])
			{
				check = 1;
				break;
			}
		}
		if (!check)
		{
			if (result > make_result(i - n, i)) {
				result = make_result(i - n, i);
			}
			break;
		}
	}
	for (i = n - 1; i > second; i--)
	{
		stemp = to_string(i);
		bool check = 0;
		for (j = 0; j < stemp.size(); j++)
		{
			if (button[stemp[j] - '0'])
			{
				check = 1;
				break;
			}
		}
		if (!check)
		{
			if (result > make_result(n - i, i)) {
				result = make_result(n - i, i);
			}
			break;
		}
	}
	cout << result;
}
int main() {
	//init
	FastIO;
	cin >> n >> m;
	int i, j, k;
	for (i = 0; i < m; i++)
	{
		cin >> itemp1;
		button[itemp1] = 1;
	}
	if (n == 100)
	{
		cout << 0;
		return 0;
	}
	if (n < 100)
	{
		result = 100 - n;
		solution(100, -1);
		return 0;
	}
	result = n - 100;
	solution(2 * n - 99, 100);
	return 0;
}
```
