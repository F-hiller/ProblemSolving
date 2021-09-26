[14719번: 빗물](https://www.acmicpc.net/problem/14719)

## 사고의 흐름

변수 이름을 어떻게 지어야할지 잘 모르겠다.. 

빗물 문제를 푼 방식은 다음과 같다.

1. 방문하지 않은 i번째 위치에서 좌우로 가장 높은 수(leftValue, rightValue)를 찾고 인덱스를 기록해둔다(left, right). 
2. 두 수 중 작은 수를 value로 저장해둔다. value가 map[i]와 같다면 1번으로 돌아간다.
3. (left + 1)부터 (right - 1)까지 저장된 물의 높이는 value값으로 맞춰진다. 따라서 mem배열에 value를 저장하고 visited로 방문표시를 해준다. 1번으로 돌아간다.
4. 모든 위치 i에서 mem[i] - map[i]를 더하면 답이 나온다.

```cpp
int t, i, j, k, n, m, a, b, c, d, e, itemp1, itemp2;
int h, w, result;
int map[500];
int mem[500];
bool visited[500];

int main() {
	//init
	FastIO;
	cin >> h >> w;
	for (i = 0; i < w; i++)
	{
		cin >> map[i];
	}
	for (i = 1; i < w - 1; i++)
	{
		if (visited[i])
		{
			result += (mem[i] - map[i]);
			continue;
		}
		int left = i;
		int right = i;
		int leftValue = map[i];
		int rightValue = map[i];

		for (j = i - 1; j > -1; j--)
		{
			if (map[j] > leftValue)
			{
				leftValue = map[j];
				left = j;
			}
		}
		for (j = i + 1; j < w; j++)
		{
			if (map[j] > rightValue)
			{
				rightValue = map[j];
				right = j;
				if (map[j] >= leftValue)
				{
					break;
				}
			}
		}
		int value = min(leftValue, rightValue);
		if (value == map[i])
		{
			continue;
		}
		for (j = left + 1; j < right; j++)
		{
			visited[j] = 1;
			mem[j] = value;
		}
		result += (value - map[i]);
	}
	cout << result;
	return 0;
}
```
